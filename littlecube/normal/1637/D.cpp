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
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll n, arr[205];
ll sum, res, ans;
bitset<200005> dp[205];

void solve()
{
    sum = res = 0;
    ans = 1e18;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        res += (n - 2) * arr[i] * arr[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i] = (dp[i - 1] << arr[i]) | (dp[i - 1] << arr[i + n]);
    for (ll i = sum; i >= 0; i--)
        if (dp[n][i] == 1)
            ans = min(ans, res + i * i + (sum - i) * (sum - i));
    cout << ans << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}