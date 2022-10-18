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
#define pdd pair<long double, long double>
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

int n;
long double m, a[1005], b[1005];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    long double L = 0, R = 2e9;
    int t = 500;
    while (t--)
    {
        long double mid = (L + R) / 2;
        long double cur = m + mid, fuel = mid;
        bool neg = 0;
        for (int i = 1; i <= n; i++)
        {
            long double burn = cur / a[i];
            cur -= burn, fuel -= burn;
            if (fuel < 0)
                neg = 1;
            burn = cur / b[i % n + 1];
            cur -= burn, fuel -= burn;
            if (fuel < 0)
                neg = 1;
        }
        if (neg)
            L = mid;
        else
            R = mid;
    }
    if (L > 1e9)
        cout << -1;
    else
        cout << fixed << setprecision(10) << (L + R) / 2 << '\n';
}