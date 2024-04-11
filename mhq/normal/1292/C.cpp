#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define y0 gsjdlgskdg
const int maxN = 3005;
ll dp[maxN][maxN];
int n;
int from[maxN], to[maxN];
vector < int > g[maxN];
int dist[maxN][maxN];
vector < pair < int, int > > byDist[maxN];
int h[maxN];
int sz[maxN][maxN];
int ROOT = -1;
void dfs(int u, int p) {
    sz[ROOT][u] = 1;
    for (int to : g[u]) {
        if (to == p) continue;
        h[to] = h[u] + 1;
        dfs(to, u);
        sz[ROOT][u] += sz[ROOT][to];
    }
}
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        h[i] = 0;
        ROOT = i;
        dfs(i, -1);
        for (int j = 1; j <= n; j++) {
            dist[i][j] = h[j];
            if (i >= j) continue;
            byDist[h[j]].emplace_back(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dist[i][j] == 1) {
                dp[i][j] = sz[i][j] * sz[j][i];
            }
            else {
                dp[i][j] = -INF;
            }
        }
    }
    ll best = 0;
    for (int dst = 1; dst <= n - 1; dst++) {
        for (auto it : byDist[dst]) {
            int u = it.first;
            int v = it.second;
            dp[u][v] = max(dp[u][v], dp[v][u]);
            dp[v][u] = dp[u][v];
            best = max(best, dp[u][v]);
            if (dp[u][v] < 0) continue;
            for (int p : g[u]) {
                if (dist[p][v] < dist[u][v]) continue;
                dp[p][v] = max(dp[p][v], dp[u][v] + sz[p][v] * sz[v][p]);
            }
            swap(u, v);
            for (int p : g[u]) {
                if (dist[p][v] < dist[u][v]) continue;
                dp[p][v] = max(dp[p][v], dp[v][u] + sz[p][v] * sz[v][p]);
            }
        }
    }
    cout << best;
    return 0;
}