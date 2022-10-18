
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int r = 0;
        map<int, bool> p;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (i >= 1)
                if (s[i] == s[i - 1] && !p[i - 1])
                    p[i] = 1;
            if (i >= 2)
                if (s[i] == s[i - 2] && !p[i - 2])
                    p[i] = 1;
        }
        for (int i = 0; i < s.length(); i++)
            if (p[i] == 1)
                r++;
    
    cout << r << '\n';
    }
}