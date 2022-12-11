#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > g;
vector<int> par;
vector<int> sz;
vector<int> inc;

int dfs(int x, int p) {
  par[x] = p;
  int ans = (g[x].size() == 1 ? 1 : 0);
  for (int c : g[x])
    if (c != p) {
      ans += dfs(c, x);
    }
  sz[x] = ans;
  inc[ans]++;
  return ans;
}

int main() {
  cin >> n;
  g.resize(n);
  g[0].push_back(-1);
  for (int i=1; i<n; ++i) {
    int p;
    cin >> p;
    p--;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  par.resize(n);
  sz.resize(n);
  inc.assign(n+1, 0);
  dfs(0, -1);
  int ans = 0;
  int cur = 1;
  for (int i=1; i<=n; ++i) {
    ans += inc[i];
    while (cur <= ans) {
      cout << i << ' ';
      cur++;
    }
  }
  cout << endl;
}