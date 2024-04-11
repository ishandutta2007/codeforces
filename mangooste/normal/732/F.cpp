#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, timer = 0, ans = 0, where_ans = -1;
vector<vector<int>> G;
vector<int> tin, tup, used;
set<pair<int, int>> bridges;
vector<pair<int, int>> edges;
unordered_map<ll, int> edge_num;

void dfs(int v, int pr) {
  tin[v] = tup[v] = timer++;
  used[v] = 1;
  for (auto u : G[v]) {
    if (u == pr) {
      continue;
    }
    if (used[u]) {
      tup[v] = min(tup[v], tin[u]);
      if (tin[u] < tin[v]) {
        edges.emplace_back(v, u);
      }
    } else {
      dfs(u, v);
      tup[v] = min(tup[v], tup[u]);
      if (tup[u] > tin[v]) {
        bridges.insert(make_pair(min(u, v), max(u, v)));
      } else {
        edges.emplace_back(v, u);
      }
    }
  }
}

int dfs_size(int v) {
  used[v] = 1;
  int res = 1;
  for (auto u : G[v]) {
    if (!used[u] && bridges.find(make_pair(min(v, u), max(v, u))) == bridges.end()) {
      res += dfs_size(u);
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  G.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
    edge_num[1ll * n * min(v, u) + max(v, u)] = i;
  }
  tin.assign(n, 0);
  tup.assign(n, 0);
  used.assign(n, 0);
  dfs(0, -1);
  used.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      int cur_size = dfs_size(i);
      if (ans < cur_size) {
        ans = cur_size;
        where_ans = i;
      }
    }
  }
  assert(where_ans != -1);
  used.assign(n, 0);
  queue<int> q;
  q.push(where_ans);
  used[where_ans] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : G[v]) {
      if (!used[u]) {
        used[u] = 1;
        if (bridges.find(make_pair(min(v, u), max(v, u))) != bridges.end()) {
          edges.emplace_back(u, v);
        }
        q.push(u);
      }
    }
  }
  cout << ans << '\n';
  assert(edges.size() == m);
  sort(edges.begin(), edges.end(), [&](pair<int, int> a, pair<int, int> b) {
    if (a.first > a.second) {
      swap(a.first, a.second);
    }
    if (b.first > b.second) {
      swap(b.first, b.second);
    }
    return edge_num[1ll * n * a.first + a.second] < edge_num[1ll * n * b.first + b.second];
  });
  for (auto &[v, u] : edges) {
    cout << v + 1 << ' ' << u + 1 << '\n';
  }
}