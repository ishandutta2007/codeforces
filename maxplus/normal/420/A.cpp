#include <iostream>

using namespace std;

bool good(char c)
{
    if (c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y')
        return 1;
    return 0;
}

int main()
{
    char c;
    char a[100000];
    int am = 0;
    while (cin >> c && c != '.')
    {
        a[am++] = c;
        if (!good(c))
        {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < am - i - 1; ++i)
        if (a[i] != a[am - i - 1])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}