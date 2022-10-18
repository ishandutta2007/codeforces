/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, m, x[200005], p[200005], h[200005], ans[200005];

signed main()
{
    // fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<pll> slope;
        vector<pll> incQ, decQ;
        set<pll> inc;
        set<pll> dec;
        ll cur = 0, last = 0, mul = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> p[i];
            ans[i] = 1;
            slope.emplace_back(pll(x[i] - p[i], 0));
            slope.emplace_back(pll(x[i],        i));
            slope.emplace_back(pll(x[i] + p[i], 0));
        }
        sort(slope.begin(), slope.end());

        for (auto [pos, type] : slope)
        {
            cur += (pos - last) * mul;
            last = pos;
            mul += (type == 0) ? 1 : -2;
            if (type)
                h[type] = cur;
            
        }
        for (int i = 1; i <= n; i++)
        {
            incQ.emplace_back(pll(x[i], i));
            decQ.emplace_back(pll(x[i], i));
        }
        sort(incQ.begin(), incQ.end());
        for (auto [pos, i] : incQ)
        {
            inc.insert(pll(p[i] + x[i], i));
            if (h[i] > m)
                while (!inc.empty() && inc.begin()->F - pos < h[i] - m)
                {
                    ans[inc.begin()->S] = 0;
                    inc.erase(inc.begin());
                }
        }
        sort(decQ.begin(), decQ.end(), greater<>());
        for (auto [pos, i] : decQ)
        {
            dec.insert(pll(p[i] - x[i], i));
            if (h[i] > m)
                while (!dec.empty() && pos + dec.begin()->F < h[i] - m)
                {
                    ans[dec.begin()->S] = 0;
                    dec.erase(dec.begin());
                }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i];
        cout << '\n';
    }
}