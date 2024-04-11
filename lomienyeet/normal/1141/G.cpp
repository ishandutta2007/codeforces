#include <iostream>
#include <vector>
#include <algorithm>
const int mxN = 2e5 + 5;
int deg[mxN], col[mxN], mx;
std::vector<int> adj[mxN], edges[mxN];
void dfs(int u, int p, int cur) {
  int ee = 1;
  if (ee == cur && ee < mx) ee++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i], idx = edges[u][i];
    if (v != p) {
      col[idx] = ee;
      dfs(v, u, ee);
      if (ee < mx) ee++;
      if (ee == cur && ee < mx) ee++;
    }
  }
}
void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 1, u, v; i < n; i++) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges[u].push_back(i);
    edges[v].push_back(i);
    deg[u]++;
    deg[v]++;
  }
  std::sort(deg + 1, deg + n + 1);
  mx = std::max(deg[n - k], 1);
  std::cout << mx << "\n";
  dfs(1, -1, 0);
  for (int i = 1; i < n; i++) std::cout << col[i] << " ";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}