#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < 4; i++)
            if (s[i] == ((i % 2 == 0) ? 2 : 0) + 48)
                r++;
            else
                break;
        for (int i = 0; i < 4; i++)
            if (s[n - 1 - i] == ((i % 2 == 0) ? 0 : 2) + 48)
                r++;
            else
                break;
        if (r >= 4)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}