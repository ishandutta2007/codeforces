#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int lr[N];
int rl[N];
vector<int> g[N];
bool u[N];

bool dfs(int v) {
  if (u[v])
    return false;
  u[v] = true;
  for (int to : g[v])
    if (rl[to] == -1 || dfs(rl[to])) {
      rl[to] = v;
      lr[v] = to;
      return true;
    }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  fill(lr, lr + n, -1);
  fill(rl, rl + m, -1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (abs(a[i] - b[j]) <= 1)
	g[i].push_back(j);
  for (int i = 0; i < n; i++) 
    if (lr[i] == -1) {
      fill(u, u + n, false);
      dfs(i);
    }
  int res = 0;
  for (int i = 0; i < n; i++)
    if (lr[i] >= 0)
      res++;
  cout << res << endl;
  return 0;
}