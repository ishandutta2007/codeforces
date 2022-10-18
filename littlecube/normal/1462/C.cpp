#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

string s[51];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n > 45)
            cout << "-1\n";
        else if (n > 44)
            cout << n - 44 << "23456789\n";
        else if (n > 42)
            cout << n - 42 << "3456789\n";
        else if (n > 39)
            cout << n - 39 << "456789\n";
        else if (n > 35)
            cout << n - 35 << "56789\n";
        else if (n > 30)
            cout << n - 30 << "6789\n";
        else if (n > 24)
            cout << n - 24 << "789\n";
        else if (n > 17)
            cout << n - 17 << "89\n";
        else if (n > 9)
            cout << n - 9 << "9\n";
        else
            cout << n << "\n";
    }
}