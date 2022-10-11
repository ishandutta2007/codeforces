#include <iostream>
#include <cstdio>
using namespace std;

int t, n;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i = 0; i < n / 2; i++)
            if (abs(s[i] - s[n - 1 - i]) != 0 && abs(s[i] - s[n - 1 - i]) != 2)
            {
                cout << "NO\n";
                goto br;
            }
        cout << "YES\n";
    br:
        continue;
    }
}