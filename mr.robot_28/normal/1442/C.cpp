#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    else if(b % 2 == 0)
    {
        int t = power(a, b / 2);
        return 1LL * t * t % mod;
    }
    else
    {
        return 1LL * power(a, b - 1) * a % mod;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > g, g1;
    g.resize(n);
    g1.resize(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g1[b].push_back(a);
    }
    int t = log2(m + 1) + 1;
    int dp[n][t];
    for(int i= 0; i < n; i++)
    {
        for(int j = 0; j < t; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    priority_queue <pair <int, pair <int, int> > > q;
    q.push({0, {0, 0}});
    while(q.size() != 0)
    {
        int v = q.top().second.first;
        int type = q.top().second.second;
        int val = q.top().first;
        q.pop();
        if(dp[v][type] != -val)
        {
            continue;
        }
        if(type % 2 == 0)
        {
            for(int i = 0; i < g[v].size(); i++)
            {
                int to = g[v][i];
                if(dp[to][type] > dp[v][type] + 1)
                {
                    dp[to][type] = dp[v][type] + 1;
                    q.push({-dp[to][type], {to, type}});
                }
            }
        }
        else
        {
            for(int i = 0; i < g1[v].size(); i++)
            {
                int to = g1[v][i];
                if(dp[to][type] > dp[v][type] + 1)
                {
                    dp[to][type] = dp[v][type] + 1;
                    q.push({-dp[to][type], {to, type}});
                }
            }
        }
        if(type < t - 1 && dp[v][type + 1] > dp[v][type] + (1 << type))
        {
            dp[v][type + 1] = dp[v][type] + (1 << type);
            q.push({-dp[v][type + 1], {v, type + 1}});
        }
    }
    int ans = 1e9;
    for(int i = 0; i < t; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    if(ans != 1e9)
    {
        cout << ans;
        return 0;
    }
    pair <int, int> dp1[n][2];
    for(int i = 0; i < n; i++)
    {
        for(int t = 0; t < 2; t++)
        {
        dp1[i][t] = {1e9, 1e9};
        }
    }
    priority_queue <pair <pair <int, int>, pair <int, int> > > q1;
    dp1[0][0] = {0, 0};
    q1.push({{0, 0}, {0, 0}});
    while(q1.size() != 0)
    {
        pair <int, int> val = q1.top().first;
        int v = q1.top().second.first;
        int t=  q1.top().second.second;
        q1.pop();
        val.first = -val.first;
        val.second = -val.second;
        if(val != dp1[v][t])
        {
            continue;
        }
        if(t % 2 == 0)
        {
            for(int i = 0; i < g[v].size(); i++)
            {
                int to = g[v][i];
                if(dp1[to][t].first > dp1[v][t].first || dp1[to][t].first == dp1[v][t].first && dp1[to][t].second > dp1[v][t].second + 1)
                {
                    dp1[to][t] = {dp1[v][t].first, dp1[v][t].second + 1};
                    q1.push({{-dp1[to][t].first, -dp1[to][t].second}, {to, t}});
                    }
                }
                for(int i = 0; i < g1[v].size(); i++)
                {
                    int to = g1[v][i];
                    if(dp1[to][1 - t].first > dp1[v][t].first + 1 || dp1[to][1 - t].first == dp1[v][t].first + 1 && dp1[to][1 - t].second > dp1[v][t].second + 1)
                    {
                        dp1[to][1 - t] = {dp1[v][t].first + 1, dp1[v][t].second + 1};
                        q1.push({{-dp1[to][1 - t].first, -dp1[to][1 - t].second}, {to, 1 - t}});
                    }
                }
            }
            else
            {
                for(int i = 0; i < g1[v].size(); i++)
                {
                int to = g1[v][i];
                if(dp1[to][t].first > dp1[v][t].first || dp1[to][t].first == dp1[v][t].first && dp1[to][t].second > dp1[v][t].second + 1)
                {
                    dp1[to][t] = {dp1[v][t].first, dp1[v][t].second + 1};
                    q1.push({{-dp1[to][t].first, -dp1[to][t].second}, {to, t}});
                    }
                }
                for(int i = 0; i < g[v].size(); i++)
                {
                    int to = g[v][i];
                    if(dp1[to][1 - t].first > dp1[v][t].first + 1 || dp1[to][1 - t].first == dp1[v][t].first + 1 && dp1[to][1 - t].second > dp1[v][t].second + 1)
                    {
                        dp1[to][1 - t] = {dp1[v][t].first + 1, dp1[v][t].second + 1};
                        q1.push({{-dp1[to][1 - t].first, -dp1[to][1 - t].second}, {to, 1 - t}});
                    }
                }
            }
        }
        pair <int, int> ans1 = dp1[n - 1][0];
        if(dp1[n - 1][1].first < ans1.first || dp1[n - 1][1].second < ans1.second && dp1[n - 1][1].first == ans1.first)
        {
            ans1 = dp1[n - 1][1];
        }
        cout << 1LL * (power(2, ans1.first) - 1 +  ans1.second) % mod;
        return 0;
    }