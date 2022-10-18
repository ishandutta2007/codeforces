/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
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
//using namespace __gnu_pbds;

#define LOCAL

void extgcd(ll a, ll b, ll c, ll &x, ll &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        extgcd(b, a % b, c, y, x);
        y -= a / b * x;
    }
}

signed main()
{
    fast;
    ll N, M, k, gcd, lcm;
    cin >> N >> M >> k;
    gcd = __gcd(2 * M, 2 * N);
    lcm = 4 * M * N / gcd;
    for (int i = 1; i <= k; i++)
    {
        ll x, y, ans = 1e18;
        cin >> x >> y;
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 2; j += 2)
                if ((i * x + j * y) % gcd == 0)
                {
                    ll p, q, t;
                    extgcd(2 * N, -2 * M, abs(i * x + j * y), p, q);
                    if (i * x + j * y < 0)
                        p = -p, q = -q;
                    t = 2 * M * q + j * y;
                    t = ((t % lcm) + lcm) % lcm;
                    ans = min(ans, t);
                }
        cout << (ans >= 1e17 ? -1 : ans) << '\n';
    }
}