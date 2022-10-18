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

int n, k, dp[205][6005],  ans;
pii arr[205];
bool valid[205][6005];

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        ll x, two = 0, five = 0;
        cin >> x;
        while (x % 2 == 0)
            two++, x >>= 1;
        while (x % 5 == 0)
            five++, x /= 5;
        arr[i] = pii{two, five};
    }
    valid[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int cnt = k; cnt >= 1; cnt--)
            for (int j = k * 30; j >= arr[i].S; j--)
                if (valid[cnt - 1][j - arr[i].S])
                {
                    dp[cnt][j] = max(dp[cnt][j], dp[cnt - 1][j - arr[i].S] + arr[i].F), valid[cnt][j] = 1;
                    ans = max(ans, min(j, dp[cnt][j]));
                }

    cout << ans << '\n';
}