#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s[0] == s[s.length() - 1])
        {
            cout << "NO\n";
            continue;
        }
        int pos = 0, neg = 0;
        bool bpos = true, bneg = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[0])
                pos++, neg++;
            else if (s[i] == s[s.length() - 1])
                pos--, neg--;
            else
                pos++, neg--;
    
            if (pos < 0)
                bpos = false;
            if (neg < 0)
                bneg = false;
            
        }
        if((bpos && pos==0) || (bneg && neg == 0))
            cout << "YES\n";
            else
                cout << "NO\n";
    }
}