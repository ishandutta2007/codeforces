#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU {
  int n;
  vector<int> par, sz;
  set<int> roots;

  void assign(int n_) {
    n = n_;
    par.assign(n, 0);
    iota(par.begin(), par.end(), 0);
    sz.assign(n, 1);
    roots = set<int>(par.begin(), par.end());
  }

  int get_par(int v) {
    return par[v] == v ? v : par[v] = get_par(par[v]);
  }

  void unite(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (v != u) {
      if (sz[v] < sz[u]) {
        swap(u, v);
      }
      par[u] = v;
      sz[v] += sz[u];
      roots.erase(u);
    }
  }

  vector<int> get_sizes() {
    vector<int> sizes;
    for (int i = 0; i < n; i++) {
      if (par[i] == i) {
        sizes.push_back(sz[i]);
      }
    }
    sort(sizes.begin(), sizes.end());
    return sizes;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G;
  G.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[max(v, u)].push_back(min(v, u));
  }
  DSU dsu;
  dsu.assign(n);
  for (int i = 0; i < n; i++) {
    unordered_map<int, int> cnts;
    for (auto &root : dsu.roots) {
      if (root >= i) {
        break;
      }
      cnts[root] = 0;
    }
    for (auto &j : G[i]) {
      cnts[dsu.get_par(j)]++;
    }
    vector<int> need;
    for (auto &[root, cnt] : cnts) {
      if (cnt < dsu.sz[root]) {
        need.push_back(root);
      }
    }
    for (auto &root : need) {
      dsu.unite(root, i);
    }
  }
  vector<int> sizes = dsu.get_sizes();
  cout << sizes.size() << '\n';
  for (auto &el : sizes) {
    cout << el << ' ';
  }
}