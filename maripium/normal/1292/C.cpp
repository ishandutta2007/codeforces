#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 3030;

int N;
vector<int> adj[MAXN];
ll cost[MAXN][MAXN];
ll dp[MAXN][MAXN];
int sz[MAXN];
int par[MAXN][MAXN];
vector<pair<int, int>> edges[MAXN];

void dfs1(int v, int p, int root, int dep) {
   if (dep) edges[dep].emplace_back(v, root);
   sz[v] = 1;
   for (auto u : adj[v]) {
      if (u != p) {
         par[u][root] = v;
         dfs1(u, v, root, dep + 1);
         sz[v] += sz[u];
      }
   }
}

void dfs2(int v, int p, int root, int coeff) {
   cost[v][root] = (ll) coeff * sz[v];
   for (int u : adj[v]) {
      if (u != p) {
         dfs2(u, v, root, coeff);
      }
   }
}

void precalc(int root) {
   dfs1(root, -1, root, 0);
   for (int v : adj[root]) {
      dfs2(v, root, root, sz[root] - sz[v]);
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 0; i + 1< N; ++i) {
      int v, u;
      cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   for (int i = 1; i <= N; ++i) {
      precalc(i);
   }
   ll ans = 0;
   for (auto p : edges[1]) {
      int v, u;
      tie(v, u) = p;
      dp[v][u] = cost[v][u];
      ans = max(ans, dp[v][u]);
   }
   for (int dep = 2; dep <= N - 1; ++dep) {
      for (auto p : edges[dep]) {
         int v, u;
         tie(v, u) = p;
         dp[v][u] = max(dp[par[v][u]][u], dp[v][par[u][v]]) + cost[v][u];
         ans = max(ans, dp[v][u]);
      }
   }
   cout << ans << "\n";
}