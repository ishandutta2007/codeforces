#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int n, k;
vector<vector<pair<int, lli>>> g;

// {without parent edge, with parent edge}
pair<lli, lli> dfs(int cur, int par) {
  vector<pair<lli, lli>> children;
  for (auto p : g[cur])
    if (p.first != par) {
      children.push_back(dfs(p.first, cur));
      children.back().second += p.second;
    }
  lli noPicks=0; vector<lli> difs;
  for (auto p : children) {
    noPicks += p.first;
    difs.push_back(p.second-p.first);
  }
  sort(difs.begin(), difs.end(), greater<lli>());
  lli ans=noPicks;
  for (int i=0; i<k-1 && i<difs.size(); ++i)
    if (difs[i] > 0)
      ans += difs[i];
  lli ansNoPar=ans;
  if (k-1 < difs.size() && difs[k-1] > 0)
    ansNoPar += difs[k-1];
  return make_pair(ansNoPar, ans);
}

void solve() {
  cin >> n >> k;
  g.assign(n, vector<pair<int, lli>>());
  for (int i=0; i<n-1; ++i) {
    int u, v;
    lli w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  cout << dfs(0, -1).first << '\n';
}

int main() {
  iostream::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int i=0; i<q; ++i)
    solve();
}