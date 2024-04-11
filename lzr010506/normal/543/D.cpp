#include <bits/stdc++.h>
using namespace std;
int dp[200010], res[200010];
vector<int> g[200010], mult[200010];
const int Mod = 1000000007;

void dfs(int u, int pu) 
{
    dp[u] = 1;
    for (auto v : g[u]) 
    {
        if (v == pu) continue;
        dfs(v, u);
        dp[u] = (long long)dp[u] * (1 + dp[v]) % Mod;
    }
}

void dfs2(int u, int pu, int up) 
{
    int m = g[u].size();
    res[u] = (long long)dp[u] * up % Mod;
    mult[u].resize(m);
    for (int i = 0; i < m; i ++) 
    {
        int v = g[u][i];
        if (v == pu) mult[u][i] = 1;
        else mult[u][i] = (dp[v] + 1) % Mod;
    }
    for (int i = m - 2; i >= 0; i --) 
        mult[u][i] = (long long)mult[u][i] * mult[u][i + 1] % Mod;
    
    int cur = 1;
    for (int i = 0; i < m; i ++) 
    {
        int v = g[u][i];
        if (v == pu) continue;
        else 
        {
            int val = cur;
            if (i != m - 1) val = (long long)cur * mult[u][i + 1] % Mod;
            val = ((long long)val * up % Mod + 1) % Mod;
            dfs2(v, u, val);
        }
        cur = (long long)cur * (1 + dp[v]) % Mod;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++) 
    {
        int x;
        scanf("%d", &x);
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1, 1);
    dfs2(1, 1, 1);
    for (int i = 1; i <= n; i ++) 
    {
        if (i > 1)
            printf(" ");
        printf("%d", res[i]);
    }
    puts("");
    return 0;
}