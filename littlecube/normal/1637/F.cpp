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

ll N, arr[200005], dp[200005][2], val[200005], pre[2000005], mx, mxcnt, ans;
vector<int> E[200005];

void dfs(int k)
{
    for (int i : E[k])
        if (pre[k] != i)
        {
            pre[i] = k;
            dfs(i);
            if (val[dp[i][0]] > val[dp[k][0]])
            {
                dp[k][1] = dp[k][0];
                dp[k][0] = dp[i][0];
            }
            else if (val[dp[i][0]] > val[dp[k][1]])
                dp[k][1] = dp[i][0];
        }
    if (E[k].size() == 1 && k != mx)
        dp[k][0] = k, val[k] = arr[k];
    else if (k != mx)
        val[dp[k][0]] = max(val[dp[k][0]], arr[k]);
    else if (E[k].size() == 1)
    {
        val[dp[k][0]] = max(val[dp[k][0]], arr[k]);
        val[k] = arr[k];
    }
    else if (mxcnt == 1)
    {
        val[dp[k][0]] = max(val[dp[k][0]], arr[k]);
        val[dp[k][1]] = max(val[dp[k][1]], arr[k]);
    }
    else if (val[dp[k][0]] != val[dp[k][1]])
        val[dp[k][1]] = max(val[dp[k][1]], arr[k]);
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if (arr[i] > arr[mx])
            mx = i, mxcnt = 0;
        if (arr[i] == arr[mx])
            ++mxcnt;
    }
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    dfs(mx);
    for (int i = 1; i <= N; i++)
        ans += val[i];
    cout << ans << '\n';
}