#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool one = 0;
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == s[i + 1] && s[i] == '1')
            one = 1;
        else if (s[i] == s[i + 1] && s[i] == '0' && one)
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}