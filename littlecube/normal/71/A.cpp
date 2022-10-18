#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.length() > 10)
        {
            cout << s[0] << (s.length() - 2) << s[s.length() - 1] << '\n';
        }
        else
        {
            cout << s << '\n';
        }
    }
}