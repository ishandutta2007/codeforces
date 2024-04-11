/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

ll n, m, q, a[100005], b[100005], cur;
vector<ll> v;

signed main()
{
    fast;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        a[i] = (i & 1 ? 1 : -1) * a[i] + a[i - 1];
    for (int i = 1; i <= m; i++)
        b[i] = (i & 1 ? 1 : -1) * b[i] + b[i - 1];
    for (int i = 0; i <= m - n; i++)
        v.emplace_back(a[n] - (i & 1 ? -1 : 1) * (b[i + n] - b[i]));
    v.emplace_back(1e18);
    v.emplace_back(-1e18);
    sort(v.begin(), v.end());
    cout << min(*lower_bound(v.begin(), v.end(), -cur) + cur, -cur - *prev(upper_bound(v.begin(), v.end(), -cur))) << '\n';
    for (int i = 1; i <= q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l) % 2 == 0)
            cur += x * (l & 1 ? 1 : -1);
        cout << min(*lower_bound(v.begin(), v.end(), -cur) + cur, -cur - *prev(upper_bound(v.begin(), v.end(), -cur))) << '\n';
    }
}