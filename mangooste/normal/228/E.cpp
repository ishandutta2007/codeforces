#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> G, rev_G;
int cur_num = 0;
vector<int> top_sort, used, num, ans;

inline void add_edge(int v, int u) {
  G[v ^ 1].push_back(u);
  rev_G[u].push_back(v ^ 1);
  G[u ^ 1].push_back(v);
  rev_G[v].push_back(u ^ 1);
}

void dfs_top_sort(int v) {
  used[v] = 1;
  for (auto u : G[v]) {
    if (!used[u]) {
      dfs_top_sort(u);
    }
  }
  top_sort.push_back(v);
}

void dfs(int v) {
  num[v] = cur_num;
  for (auto u : rev_G[v]) {
    if (num[u] == -1) {
      dfs(u);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  G.resize(2 * n);
  rev_G.resize(2 * n);
  for (int i = 0; i < m; i++) {
    int v, u, c;
    cin >> v >> u >> c;
    v--, u--;
    if (c == 0) {
      add_edge(2 * v, 2 * u);
      add_edge(2 * v + 1, 2 * u + 1);
    } else {
      add_edge(2 * v, 2 * u + 1);
      add_edge(2 * v + 1, 2 * u);
    }
  }
  used.assign(2 * n, 0);
  for (int i = 0; i < 2 * n; i++) {
    if (!used[i]) {
      dfs_top_sort(i);
    }
  }
  reverse(top_sort.begin(), top_sort.end());
  num.assign(2 * n, -1);
  for (auto v : top_sort) {
    if (num[v] == -1) {
      dfs(v);
      cur_num++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (num[2 * i] == num[2 * i + 1]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (num[2 * i] < num[2 * i + 1]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto el : ans) {
    cout << el + 1 << ' ';
  }
  cout << '\n';
}