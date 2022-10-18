#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        bool y = true;
        for (int i = (s.length() + 1) / 2 - 1; i < s.length(); i++)
            if (s[i] != ')')
                y = false;
        if (y)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}