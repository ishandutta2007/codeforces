#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
const int mxN = 3e3 + 5;
int sum[mxN][mxN], dp[mxN][mxN], pp[mxN][mxN];
std::vector<int> adj[mxN];
void dfs(int u, int rt, int p) {
  sum[u][rt] = 1;
  for (auto i : adj[u]) {
    if (i != p) {
      pp[i][rt] = u;
      dfs(i, rt, u);
      sum[u][rt] += sum[i][rt];
    }
  }
}
int calc(int u, int v) {
  if (u > v) std::swap(u, v);
  if (dp[u][v] != -1) return dp[u][v];
  return dp[u][v] = std::max(calc(u, pp[v][u]), calc(v, pp[u][v])) + sum[u][v] * sum[v][u];
}
void solve() {
  int n;
  std::cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    dfs(i, i, -1);
    dp[i][i] = 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) ans = std::max(ans, calc(i, j));
    }
  }
  std::cout << ans << "\n";
}
int32_t main(){
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}