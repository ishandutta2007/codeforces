#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];
  vector<vector<int>> g(n);
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int rt = 0;
  for (int i = 0; i < n; ++i) {
    if (h[i] > h[rt]) {
      rt = i;
    }
  }
  ll ans = 0;
  function<int(int, int)> dfs = [&](int u, int p) {
    int mx1 = 0, mx2 = 0;
    vector<int> have;
    for (auto v : g[u]) {
      if (v != p) {
        int cur = dfs(v, u);
        if (cur > mx1) swap(cur, mx1);
        if (cur > mx2) swap(cur, mx2);
      }
    }
    if (p != -1) {
      int delta = max(0, h[u] - mx1);
      ans += delta;
      mx1 += delta;
    } else {
      ans += max(0, h[u] - mx1) + max(0, h[u] - mx2);
    }
    return mx1;
  };
  dfs(rt, -1);
  cout << ans << '\n';
}