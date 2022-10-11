#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cur_num = 0;
vector<vector<int>> G;
vector<int> ve, ue, comp, dfs_used, ord, used;
map<int, int> edges;

inline int get_num(int v, int u) {
  if (v > u) {
    swap(v, u);
  }
  return v * 300 + u;
}

void dfs(int v) {
  comp.push_back(v);
  dfs_used[v] = 1;
  for (auto num : G[v]) {
    int u = (ve[num] ^ ue[num] ^ v);
    if (!dfs_used[u]) {
      dfs(u);
    }
  }
}

void dfs_euler(int v) {
  while (!G[v].empty()) {
    int num = G[v].back();
    G[v].pop_back();
    if (!used[num]) {
      int u = (ve[num] ^ ue[num] ^ v);
      used[num] = 1;
      dfs_euler(u);
    }
  }
  ord.push_back(v);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    G.assign(n, vector<int>());
    ve.assign(m + n, -1);
    ue.assign(m + n, -1);
    edges.clear();
    cur_num = 0;
    for (int i = 0; i < m; i++, cur_num++) {
      cin >> ve[i] >> ue[i];
      ve[i]--, ue[i]--;
      G[ve[i]].push_back(cur_num);
      G[ue[i]].push_back(cur_num);
      edges[get_num(ve[i], ue[i])]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (G[i].size() % 2 == 0) {
        ans++;
      }
    }
    cout << ans << '\n';
    dfs_used.assign(n, 0);
    used.assign(n * (n - 1) / 2 + n, 0);
    for (int i = 0; i < n; i++) {
      if (!dfs_used[i]) {
        dfs(i);
        vector<int> odd;
        for (auto &el : comp) {
          if (G[el].size() % 2) {
            odd.push_back(el);
          }
        }
        assert(odd.size() % 2 == 0);
        for (int i = 0; i < odd.size(); i += 2, cur_num++) {
          int v = odd[i], u = odd[i + 1];
          ve[cur_num] = v;
          ue[cur_num] = u;
          G[v].push_back(cur_num);
          G[u].push_back(cur_num);
        }
        dfs_euler(i);
        for (int v = 1; v < ord.size(); v++) {
          int num = get_num(ord[v - 1], ord[v]);
          if (edges.find(num) != edges.end() && edges[num] > 0) {
            edges[num]--;
            cout << ord[v - 1] + 1 << ' ' << ord[v] + 1 << '\n';
          }
        }
        comp.clear();
        ord.clear();
      }
    }
  }
}