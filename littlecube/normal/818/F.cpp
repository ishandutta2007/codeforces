/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

ll Q, N;

ll getB(ll N, ll A)
{
    return (N - A) * (N - 1 - A) / 2;
}

signed main()
{
    fast;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> N;
        ll L = 1, R = N - 1, ans = N - 1;
        while (R - L > 3)
        {
            ll mid = (L + R) / 2;
            if (mid <= getB(N, mid))
                L = mid;
            else
                R = mid;
        }
        for (ll j = L; j <= R; j++)
            ans = max(ans, j + min(j, getB(N, j)));
        cout << ans << '\n';
    }
}