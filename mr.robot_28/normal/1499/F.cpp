#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
const int mod = 998244353;
const int N = 5e3 + 100;
vector <int> g[N];
vector <int> dp1[N];
int maxh[N];
void dfs1(int v, int p = -1)
{
    maxh[v] = 0;
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        dfs1(to, v);
        maxh[v] = max(maxh[v], maxh[to]);
    }
    maxh[v]++;
}
int sum_dp[N];
int n, k;
void dfs(int v, int p = -1)
{
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        dfs(to, v);
    }
  //  cout << v << "\n";
    vector <int> dp(maxh[v] + 1, 0);
    dp[0] = 1;
    vector <int> dp1_(maxh[v] + 1, 0);
    int mx1 = 0;
    dp1[v].resize(maxh[v] + 1);
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        for(int t = 1; t <= maxh[to]; t++)
        {
            for(int t1 = 0; t1 <= mx1 && t + t1 <= k; t1++)
            {
                dp1_[max(t, t1)] = (dp1_[max(t, t1)] + 1LL * dp[t1] * dp1[to][t]) % mod;
            }
        }
        for(int t1 = 0; t1 <= max(maxh[to], mx1); t1++)
        {
            dp[t1] = (1LL * dp[t1] * sum_dp[to] + dp1_[t1]) % mod;
            dp1_[t1] = 0;
        }
        mx1 = max(mx1, maxh[to]);
    }
    for(int i = 0; i < maxh[v]; i++)
    {
        if(i <= k)
        {
            sum_dp[v] = (sum_dp[v] + dp[i]) % mod;
        }
        dp1[v][i + 1] = dp[i];
    }
//    cout << sum_dp[v] << "\n";
  //  cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    fill(sum_dp, sum_dp + N, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(0);
    dfs(0);
    int ans = 0;
    for(int i = 1; i <= maxh[0]; i++)
    {
        ans = (ans + dp1[0][i]) % mod;
    }
    cout << ans;
    return 0;
}