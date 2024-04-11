#include <bits/stdc++.h>

using namespace std;

const int N = 6000 + 10;

vector<int> g[N];
int a[N];
int f[N];
int sz;
int res = 0;

void dfs(int v, int p) {
  bool pop = false;
  int pos;
  int old_val;
  pos = lower_bound(f, f + sz, a[v]) - f;
  if (pos == sz) {
    f[sz++] = a[v];
    pop = true;
  } else {
    old_val = f[pos];
    f[pos] = a[v];
  }
  res = max(res, sz);
  for (int to : g[v])
    if (to != p)
      dfs(to, v);
  if (pop)
    sz--;
  else 
    f[pos] = old_val;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    sz = 0;
    dfs(i, i);
  }
  cout << res << "\n";
  return 0;
}