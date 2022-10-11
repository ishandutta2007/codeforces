#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, cur_num, timer = 0;
vector<int> a, b, va, vb, deg, ve, ue, way, ans, used, dfs_used;
vector<vector<int>> G;

inline void add_edge(int v, int u) {
  deg[v]++;
  deg[u]++;
  G[v].push_back(cur_num);
  G[u].push_back(cur_num);
  ve[cur_num] = v;
  ue[cur_num] = u;
  cur_num++;
}

void dfs(int v) {
  dfs_used[v] = timer;
  for (auto num : G[v]) {
    int u = (ve[num] ^ ue[num] ^ v);
    if (dfs_used[u] != timer) {
      dfs(u);
    }
  }
}

void dfs_euler(int v) {
  while (!G[v].empty()) {
    int num = G[v].back();
    G[v].pop_back();
    if (used[num] == timer) {
      continue;
    }
    used[num] = timer;
    dfs_euler(ve[num] ^ ue[num] ^ v);
  }
  way.push_back(v);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  G.assign(2 * n + (1 << 20), vector<int>());
  deg.assign(2 * n + (1 << 20), 0);
  va.assign(n, 0);
  vb.assign(n, 0);
  ve.assign(3 * n, -1);
  ue.assign(3 * n, -1);
  used.assign(3 * n, -1);
  dfs_used.assign(2 * n + (1 << 20), -1);
  for (int bit = 20; bit >= 0; bit--, timer++) {
    int m = (1 << bit), sz = 2 * n + m;
    for (int i = 0; i < sz; i++) {
      deg[i] = 0;
      G[i].clear();
    }
    cur_num = 0;
    for (int i = 0; i < n; i++) {
      va[i] = a[i] % m;
      vb[i] = b[i] % m;
      add_edge(m + 2 * i, va[i]);
      add_edge(m + 2 * i + 1, vb[i]);
      add_edge(m + 2 * i, m + 2 * i + 1);
    }
    bool ok = true;
    for (int i = 0; i < sz; i++) {
      if (deg[i] % 2 == 1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    dfs(m);
    for (int i = m; i < sz; i++) {
      if (dfs_used[i] != timer) {
        ok = false;
      }
    }
    if (!ok) {
      continue;
    }
    dfs_euler(m);
    for (auto el : way) {
      if (el >= m) {
        ans.push_back(el - m);
      }
    }
    ans.pop_back();
    assert(ans.size() == 2 * n);
    if (ans[0] / 2 != ans[1] / 2) {
      rotate(ans.begin(), ans.begin() + 1, ans.end());
    }
    cout << bit << '\n';
    for (auto el : ans) {
      cout << el + 1 << ' ';
    }
    cout << '\n';
    return 0;
  }
  assert(false);
}