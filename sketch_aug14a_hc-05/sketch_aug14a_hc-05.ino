/*
 * Reference
 * To config bluetooth: https://www.allnewstep.com/article/141/โปรเจก-arduino-bluetooth-hc-05-สอนวิธี-ตั้งค่าชื่อ-และเปลี่ยนรหัสผ่าน-ของ-bluetooth
 * To plot graph: https://github.com/gthe856/arduinoBluetoothSample/blob/master/sineWaveBluetoothSample.ino
 * https://www.arduino.cc/reference/en/language/functions/time/millis/
 * 
 * MCU: Arduino Mega
 * Wiring: 
 *   MCU          HC-05
 *   TX2 (16) ->  RX
 *   RX2 (17) ->  TX
 *   GND      ->  GND
 *   5V       ->  VCC
 */
unsigned long counter;

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);
  counter = millis();
}

void loop()
{
  if( millis() - counter > 500) { // Delay for 500 ms
    counter = millis();
    Serial2.print("Graph:");
    Serial2.print(random(0, 100));
    Serial2.print("&");
    Serial2.print(random(0, 100));
    Serial2.println(";");
  }
  
  if (Serial2.available())
    Serial.write(Serial2.read());
  delay(100);
}
