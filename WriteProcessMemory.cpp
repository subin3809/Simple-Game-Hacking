#include <iostream>
#include <conio.h>
#include <windows.h>

int main() {
    DWORD Pointer = 0x0;    //CE Address
    DWORD offset = 0x0;     //CE Pointer
    int Value = 0; // Value
    HWND hWND = FindWindow(0, "Tutorial-x86_64"); // or name-ProcessPath   name = process
    if (hWND == 0x00) {
        std::cerr << "���μ����� ã���� �����ϴ�." << std::endl;
    }
    else {
        DWORD pId;
        GetWindowThreadProcessId(hWND, &pId);
        HANDLE pVictim = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
        if (!pVictim) {
            std::cerr << "���μ��� ����." << std::endl;
        }
        else {
            int result = WriteProcessMemory(pVictim, (LPVOID)(Pointer+offset), &Value, (DWORD)sizeof(Value), nullptr);
            if (result > 0x00) {
                std::clog << "���ٲٱ�: ����." << std::endl;
            }
            else {
                std::cerr << "���ٲٱ�: ����." << std::endl;
            }
            CloseHandle(pVictim);
        }
    } _getch();
    return 0x00;
}