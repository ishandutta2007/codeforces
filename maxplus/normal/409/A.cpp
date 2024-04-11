#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    unsigned long long int m1 = 0, m2 = 0, a[20], b[20], A = 0, B = 0;
    unsigned char c;
    while (scanf("%c", &c) > 0 && c != '\n')
    {
        if (c == '(')
            a[m1++] = 0;
        if (c == '8')
            a[m1++] = 1;
        if (c == '[')
            a[m1++] = 2;
    }
    while (scanf("%c", &c) > 0 && c != '\n')
    {
        if (c == '(')
            b[m2++] = 0;
        if (c == '8')
            b[m2++] = 1;
        if (c == '[')
            b[m2++] = 2;
    }
    for (int i = 0; i < m1; ++i)
    {
        if (a[i] != b[i])
        {
            if ((a[i] + 1) % 3 == b[i] % 3)
                A++;
            else
                B++;
        }
    }
    if (A == B)
        cout << "TIE";
    else if (A > B)
        cout << "TEAM 1 WINS";
    else
        cout << "TEAM 2 WINS";
    return 0;
}