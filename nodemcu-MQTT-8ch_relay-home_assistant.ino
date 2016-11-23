/*
   MQTT Light for Home-Assistant - NodeMCU (ESP8266)
   https://home-assistant.io/components/light.mqtt/

   Libraries :
    - ESP8266 core for Arduino : https://github.com/esp8266/Arduino
    - PubSubClient : https://github.com/knolleary/pubsubclient

   Sources :
    - File > Examples > ES8266WiFi > WiFiClient
    - File > Examples > PubSubClient > mqtt_auth
    - File > Examples > PubSubClient > mqtt_esp8266

   Schematic :
    - https://github.com/mertenats/open-home-automation/blob/master/ha_mqtt_light/Schematic.png
    - GND - LED - Resistor 220 Ohms - D1/GPIO5

   Configuration (HA) :
    light:
      platform: mqtt
      name: Office light'
      state_topic: 'changeme/1/status'
      command_topic: 'changeme/1/switch'
      optimistic: false

   Samuel M. - v1.1 - 08.2016
   If you like this example, please add a star! Thank you!
   https://github.com/mertenats/open-home-automation
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define MQTT_VERSION MQTT_VERSION_3_1_1

// Wifi: SSID and password
const char* WIFI_SSID = "changeme";
const char* WIFI_PASSWORD = "changeme";

// MQTT: ID, server IP, port, username and password
const PROGMEM char* MQTT_CLIENT_ID = "relays8ch";
const PROGMEM char* MQTT_SERVER_IP = "changeme";
const PROGMEM uint16_t MQTT_SERVER_PORT = 1883;
const PROGMEM char* MQTT_USER = "changeme";
const PROGMEM char* MQTT_PASSWORD = "changeme";

// MQTT: topics
const char* MQTT_LIGHT_STATE_TOPIC1 = "changeme/1/status";
const char* MQTT_LIGHT_COMMAND_TOPIC1 = "changeme/1/switch";

const char* MQTT_LIGHT_STATE_TOPIC2 = "changeme/2/status";
const char* MQTT_LIGHT_COMMAND_TOPIC2 = "changeme/2/switch";

const char* MQTT_LIGHT_STATE_TOPIC3 = "changeme/3/status";
const char* MQTT_LIGHT_COMMAND_TOPIC3 = "changeme/3/switch";

const char* MQTT_LIGHT_STATE_TOPIC4 = "changeme/4/status";
const char* MQTT_LIGHT_COMMAND_TOPIC4 = "changeme/4/switch";

const char* MQTT_LIGHT_STATE_TOPIC5 = "changeme/5/status";
const char* MQTT_LIGHT_COMMAND_TOPIC5 = "changeme/5/switch";

const char* MQTT_LIGHT_STATE_TOPIC6 = "changeme/6/status";
const char* MQTT_LIGHT_COMMAND_TOPIC6 = "changeme/6/switch";

const char* MQTT_LIGHT_STATE_TOPIC7 = "changeme/7/status";
const char* MQTT_LIGHT_COMMAND_TOPIC7 = "changeme/7/switch";

const char* MQTT_LIGHT_STATE_TOPIC8 = "changeme/8/status";
const char* MQTT_LIGHT_COMMAND_TOPIC8 = "changeme/8/switch";


// payloads by default (on/off)
const char* LIGHT_ON = "ON";
const char* LIGHT_OFF = "OFF";

const PROGMEM uint8_t LED_PIN1 = 5;
const PROGMEM uint8_t LED_PIN2 = 4;
const PROGMEM uint8_t LED_PIN3 = 0;
const PROGMEM uint8_t LED_PIN4 = 2;
const PROGMEM uint8_t LED_PIN5 = 14;
const PROGMEM uint8_t LED_PIN6 = 12;
const PROGMEM uint8_t LED_PIN7 = 13;
const PROGMEM uint8_t LED_PIN8 = 15;


boolean m_light_state = false; // light is turned off by default

WiFiClient wifiClient;
PubSubClient client(wifiClient);

// function called to publish the state of the light (on/off)
void publishLightState1() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC1, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC1, LIGHT_OFF, true);
  }
}

void publishLightState2() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC2, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC2, LIGHT_OFF, true);
  }
}

void publishLightState3() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC3, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC3, LIGHT_OFF, true);
  }
}

void publishLightState4() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC4, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC4, LIGHT_OFF, true);
  }
}

void publishLightState5() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC5, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC5, LIGHT_OFF, true);
  }
}

void publishLightState6() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC6, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC6, LIGHT_OFF, true);
  }
}

void publishLightState7() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC7, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC7, LIGHT_OFF, true);
  }
}void publishLightState8() {
  if (m_light_state) {
    client.publish(MQTT_LIGHT_STATE_TOPIC8, LIGHT_ON, true);
  } else {
    client.publish(MQTT_LIGHT_STATE_TOPIC8, LIGHT_OFF, true);
  }
}
// function called to turn on/off the light
void setLightState1() {
  if (m_light_state) {
    digitalWrite(LED_PIN1, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN1, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState2() {
  if (m_light_state) {
    digitalWrite(LED_PIN2, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN2, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState3() {
  if (m_light_state) {
    digitalWrite(LED_PIN3, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN3, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState4() {
  if (m_light_state) {
    digitalWrite(LED_PIN4, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN4, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState5() {
  if (m_light_state) {
    digitalWrite(LED_PIN5, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN5, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState6() {
  if (m_light_state) {
    digitalWrite(LED_PIN6, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN6, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState7() {
  if (m_light_state) {
    digitalWrite(LED_PIN7, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN7, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
void setLightState8() {
  if (m_light_state) {
    digitalWrite(LED_PIN8, HIGH);
    Serial.println("INFO: Turn light on...");
  } else {
    digitalWrite(LED_PIN8, LOW);
    Serial.println("INFO: Turn light off...");
  }
}
// function called when a MQTT message arrived
void callback(char* p_topic, byte* p_payload, unsigned int p_length) {
  // concat the payload into a string
  String payload;
  for (uint8_t i = 0; i < p_length; i++) {
    payload.concat((char)p_payload[i]);
  }

  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC1).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState1();
        publishLightState1();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState1();
        publishLightState1();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC2).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState2();
        publishLightState2();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState2();
        publishLightState2();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC3).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState3();
        publishLightState3();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState3();
        publishLightState3();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC4).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState4();
        publishLightState4();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState4();
        publishLightState4();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC5).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState5();
        publishLightState5();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState5();
        publishLightState5();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC6).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState6();
        publishLightState6();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState6();
        publishLightState6();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC7).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState7();
        publishLightState7();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState7();
        publishLightState7();
      }
    }
  }


  // handle message topic
  if (String(MQTT_LIGHT_COMMAND_TOPIC8).equals(p_topic)) {
    // test if the payload is equal to "ON" or "OFF"
    if (payload.equals(String(LIGHT_ON))) {
      if (m_light_state != true) {
        m_light_state = true;
        setLightState8();
        publishLightState8();
      }
    } else if (payload.equals(String(LIGHT_OFF))) {
      if (m_light_state != false) {
        m_light_state = false;
        setLightState8();
        publishLightState8();
      }
    }
  }
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("INFO: Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("INFO: connected");
      // Once connected, publish an announcement...
      publishLightState1();
      publishLightState2();
      publishLightState3();
      publishLightState4();
      publishLightState5();
      publishLightState6();
      publishLightState7();
      publishLightState8();

      // ... and resubscribe
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC1);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC2);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC3);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC4);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC5);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC6);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC7);
      client.subscribe(MQTT_LIGHT_COMMAND_TOPIC8);
    } else {
      Serial.print("ERROR: failed, rc=");
      Serial.print(client.state());
      Serial.println("DEBUG: try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  // init the serial
  Serial.begin(115200);

  // init the led
  pinMode(LED_PIN1, OUTPUT);
  setLightState1();
  pinMode(LED_PIN2, OUTPUT);
  setLightState2();
  pinMode(LED_PIN3, OUTPUT);
  setLightState3();
  pinMode(LED_PIN4, OUTPUT);
  setLightState4();
  pinMode(LED_PIN5, OUTPUT);
  setLightState5();
  pinMode(LED_PIN6, OUTPUT);
  setLightState6();
  pinMode(LED_PIN7, OUTPUT);
  setLightState7();
  pinMode(LED_PIN8, OUTPUT);
  setLightState8();

  // init the WiFi connection
  Serial.println();
  Serial.println();
  Serial.print("INFO: Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("INFO: WiFi connected");
  Serial.print("INFO: IP address: ");
  Serial.println(WiFi.localIP());

  // init the MQTT connection
  client.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
