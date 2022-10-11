#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, k, mx;
vector<vector<int>> G;
vector<vector<int>> ans;
vector<int> used;

void dfs(int v) {
  if (ans.back().size() == mx) {
    ans.push_back({});
  }
  ans.back().push_back(v);
  used[v] = 1;
  for (auto u : G[v]) {
    if (!used[u]) {
      dfs(u);
      if (ans.back().size() != mx) {
        ans.back().push_back(v);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  mx = (2 * n + k - 1) / k;
  G.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  ans.push_back({});
  used.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  while (ans.size() < k) {
    ans.push_back({0});
  }
  assert(ans.size() == k);
  for (auto &el : ans) {
    cout << el.size();
    for (auto &ell : el) {
      cout << ' ' << ell + 1;
    }
    cout << '\n';
  }
}