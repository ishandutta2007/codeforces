#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> a;
vector<vector<int>> G;
ll ans = 0;

array<array<int, 2>, 20> dfs(int v = 0, int pr = -1) {
  array<array<int, 2>, 20> cur;
  for (int i = 0; i < 20; i++) {
    cur[i] = {0, 0};
  }
  vector<array<array<int, 2>, 20>> vals;
  for (auto u : G[v]) {
    if (u != pr) {
      vals.push_back(dfs(u, v));
      for (int i = 0; i < 20; i++) {
        int bt = ((a[v] >> i) & 1);
        for (int j = 0; j < 2; j++) {
          cur[i][j ^ bt] += vals.back()[i][j];
        }
        ans += (1ll << i + 1) * vals.back()[i][bt ^ 1];
      }
    }
  }
  for (auto &el : vals) {
    array<array<int, 2>, 20> without = cur;
    for (int i = 0; i < 20; i++) {
      int bt = ((a[v] >> i) & 1);
      for (int j = 0; j < 2; j++) {
        without[i][j ^ bt] -= el[i][j];
      }
    }
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 2; j++) {
        ans += (1ll << i) * el[i][j] * without[i][j ^ 1];
      }
    }
  }
  for (int i = 0; i < 20; i++) {
    cur[i][(a[v] >> i) & 1]++;
  }
  return cur;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  G.assign(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  dfs();
  cout << ans / 2 + accumulate(a.begin(), a.end(), 0ll);
}