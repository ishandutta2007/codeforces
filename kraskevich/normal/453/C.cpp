#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5;

vector<int> g[N];
bool u[N];
int ones;
int want[N];
int have[N];
vector<int> cur;

void dfs(int v, int par) {
  u[v] = true;
  if (want[v] == 1)
    ones++;
  have[v]++;
  have[v] %= 2;
  cur.push_back(v);
  for (int to : g[v]) {
    if (u[to])
      continue;
    dfs(to, v);
    have[v]++;
    have[v] %= 2;
    cur.push_back(v);
  }
  if (have[v] == want[v])
    return;
  have[v] = want[v];
  if (par == -1) {
    cur.pop_back();
  }
  else {
    have[par]++;
    have[par] %= 2;
    cur.push_back(par);
    cur.push_back(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  vector<int> res;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    cin >> want[i];
  for (int i = 0; i < n; i++) {
    if (u[i])
      continue;
    cur.clear();
    ones = 0;
    dfs(i, -1);
    if (ones == 0)
      continue;
    if (res.size() > 0) {
      cout << -1;
      return 0;
    }
    res = cur;
  }
  cout << res.size() << "\n";
  for (int x : res)
    cout << x + 1 << " ";
  return 0;
}