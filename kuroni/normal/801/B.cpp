#include <stdio.h>
#include <iostream>

using namespace std;

string a, s, b = "";

int main()
{
    cin >> a;
    cin >> s;
    for (int i = 0; i < a.size(); i++)
    {
        if (s[i] > a[i])
        {
            cout << -1;
            return 0;
        }
        else b = b + s[i];
    }
    cout << b;
}