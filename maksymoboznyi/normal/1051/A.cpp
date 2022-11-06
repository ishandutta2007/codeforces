#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

signed main()
{
    int t;
    cin >> t;
    for (int o = 0; o < t; o++)
    {
        string s;
        vector<int> aa, bb, cc;
        cin >> s;

        bool a = 0, b = 0, c = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                a = 1, aa.pb(i);
            if (s[i] >= 'A' && s[i] <= 'Z')
                b = 1, bb.pb(i);
            if (s[i] >= '0' && s[i] <= '9')
                c = 1, cc.pb(i);
        }
        if (a && b && c)
        {
            cout << s << "\n";
            continue;
        }
        if (a && !b && !c)
        {
            s[0] = '0';
            s[1] = 'A';
            cout << s << "\n";
            continue;
        }
        if (b && !a && !c)
        {
            s[0] = 'a';
            s[1] = '0';
            cout << s << "\n";
            continue;
        }
        if (c && !a && !b)
        {
            s[0] = 'a';
            s[1] = 'A';
            cout << s << "\n";
            continue;
        }
        if (!a)
        {
            if (bb.size() == 1)
                s[cc[0]] = 'a';
            else
                s[bb[0]] = 'a';
            cout << s << "\n";
            continue;
        }
        if (!b)
        {
            if (aa.size() == 1)
                s[cc[0]] = 'A';
            else
                s[aa[0]] = 'A';
            cout << s << "\n";
            continue;
        }
        if (!c)
        {
            if (bb.size() == 1)
                s[aa[0]] = '0';
            else
                s[bb[0]] = '0';
            cout << s << "\n";
            continue;
        }
    }
    return 0;
}