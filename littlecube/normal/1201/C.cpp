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

ll N, k, a[200005];

signed main()
{
    fast;
    cin >> N >> k;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + N);
    ll L = a[N / 2 + 1], R = L + k;
    while (L < R)
    {
        ll mid = (L + R + 1) / 2, cnt = 0;
        for (int i = N / 2 + 1; i <= N; i++)
            cnt += max(0LL, mid - a[i]);
        if (cnt <= k)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}