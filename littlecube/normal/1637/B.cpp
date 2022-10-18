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

int n, arr[105], dp[105];
ll ans;

void solve()
{
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i - 1] = 0;
        for (int j = i; j <= n; j++)
        {
            set<int> s;
            dp[j] = 0;
            for (int k = 0; k <= 101; k++)
                s.insert(k);
            for (int k = j; k >= i; k--)
            {
                auto iter = s.find(arr[k]);
                if(iter != s.end())
                    s.erase(iter);
                dp[j] = max(dp[j], dp[k - 1] + *s.begin() + 1);
            }
        }
        for (int j = i; j <= n; j++)
            ans += dp[j];
    }
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