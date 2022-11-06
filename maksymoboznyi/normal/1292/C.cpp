#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 3e3 + 3;

int n, p[N][N], sub[N][N], dist[N][N];
vector<int> g[N];
long long dp[N][N];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return dist[a.first][a.second] < dist[b.first][b.second];
}

void dfs(int start, int v, int par, int dep = 0) {
    p[start][v] = par;
    sub[start][v] = 1;
    dist[start][v] = dep;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != par)
            dfs(start, g[v][i], v, dep + 1), sub[start][v] += sub[start][g[v][i]];
}

long long solve(int u, int v) {
    if (dp[u][v] != -1)
        return dp[u][v];
    if (v == u)
        return dp[u][v] = 0;
    //cout << sub[u][v] << ' ' << sub[v][u] << ' ' << u << ' ' << v << endl;
    return (dp[u][v] = 1ll * sub[u][v] * sub[v][u] + max(solve(u, p[u][v]), solve(v, p[v][u])));
}

signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, i, -1);
    int aa = 1, b = 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > dist[aa][b])
                aa = i, b = j;
            dp[i][j] = -1;
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                solve(i, j), ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}