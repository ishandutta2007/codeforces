#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, s, t, ds, dt;
vector<vector<int>> G;
vector<pair<int, int>> ans, from;
vector<int> used;
array<vector<int>, 4> types;

pair<int, int> dfs(int v) {
  pair<int, int> res = make_pair(-1, -1);
  used[v] = 1;
  for (auto u : G[v]) {
    if (u == s) {
      res.first = v;
    } else if (u == t) {
      res.second = v;
    } else if (!used[u]) {
      ans.emplace_back(v, u);
      pair<int, int> cur = dfs(u);
      if (cur.first != -1) {
        res.first = cur.first;
      }
      if (cur.second != -1) {
        res.second = cur.second;
      }
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
  }
  cin >> s >> t >> ds >> dt;
  s--, t--;
  used.assign(n, 0);
  used[s] = used[t] = 1;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      from.push_back(dfs(i));
      int cur_type = 0;
      if (from.back().first != -1) {
        cur_type += 2;
      }
      if (from.back().second != -1) {
        cur_type++;
      }
      assert(cur_type);
      types[cur_type].push_back(from.size() - 1);
    }
  }
  while (types[1].size()) {
    ans.emplace_back(t, from[types[1].back()].second);
    types[1].pop_back();
    dt--;
  }
  while (types[2].size()) {
    ans.emplace_back(s, from[types[2].back()].first);
    types[2].pop_back();
    ds--;
  }
  if (min(ds, dt) <= 0) {
    cout << "No\n";
    return 0;
  }
  if (types[3].empty()) {
    assert(find(G[s].begin(), G[s].end(), t) != G[s].end());
    ans.emplace_back(s, t);
  } else {
    int sum = ds + dt;
    if (types[3].size() >= sum) {
      cout << "No\n";
      return 0;
    }
    ans.emplace_back(from[types[3].back()].first, s);
    ans.emplace_back(from[types[3].back()].second, t);
    ds--, dt--;
    types[3].pop_back();
    while (types[3].size() && dt) {
      ans.emplace_back(t, from[types[3].back()].second);
      types[3].pop_back();
      dt--;
    }
    while (types[3].size() && ds) {
      ans.emplace_back(s, from[types[3].back()].first);
      types[3].pop_back();
      ds--;
    }
  }
  assert(ans.size() == n - 1);
  cout << "Yes\n";
  for (auto &[u, v] : ans) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
}