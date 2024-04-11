#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k1, k2, ans;
vector<vector<int>> G;
set<int> my, his;

int dfs(int v, int pr = -1) {
  if (my.find(v + 1) != my.end()) {
    return v;
  }
  for (auto u : G[v]) {
    if (u != pr) {
      int cur = dfs(u, v);
      if (cur != -1) {
        return cur;
      }
    }
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    G.assign(n, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
      int v, u;
      cin >> v >> u;
      v--, u--;
      G[v].push_back(u);
      G[u].push_back(v);
    }
    my.clear();
    cin >> k1;
    for (int i = 0; i < k1; i++) {
      int x;
      cin >> x;
      my.insert(x);
    }
    his.clear();
    cin >> k2;
    for (int i = 0; i < k2; i++) {
      int x;
      cin >> x;
      his.insert(x);
    }
    cout << "B " << *his.begin() << endl;
    int v;
    cin >> v;
    if (my.find(v) != my.end()) {
      ans = v;
    } else {
      int u = dfs(v - 1);
      assert(u != -1);
      cout << "A " << u + 1 << endl;
      int w;
      cin >> w;
      if (his.find(w) != his.end()) {
        ans = u + 1;
      } else {
        ans = -1;
      }
    }
    cout << "C " << ans << endl;
  }
}