#include <bits/stdc++.h>

using namespace std;

const int N = (int)5e5;
const int INF = 1000 * 1000 * 1000;

vector<int> par(N);
vector<int> diam(N);
vector<int> g[N];
int dist[N];
bool u[N];
vector<int> cur;

void dfs(int v) {
  u[v] = true;
  cur.push_back(v);
  for (int to : g[v])
    if (!u[to])
      dfs(to);
}

void bfs(int st) {
  for (int u : cur)
    dist[u] = INF;
  dist[st] = 0;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to : g[v])
      if (dist[to] > dist[v] + 1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
  }
}

int get_diam(int st) {
  bfs(st);
  int v = st;
  for (int u : cur)
    if (dist[u] > dist[v])
      v = u;
  bfs(v);
  int res = 0;
  for (int u : cur)
    res = max(res, dist[u]);
  return res;
}

int root(int v) {
  return par[v] == v ? v : par[v] = root(par[v]);
}

void unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b)
    return;
  int d1 = diam[a] / 2 + diam[a] % 2;
  int d2 = diam[b] / 2 + diam[b] % 2;
  int d = d1 + d2 + 1;
  d = max(d, max(diam[a], diam[b]));
  par[b] = a;
  diam[a] = d;
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    par[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    if (!u[i]) {
      cur.clear();
      dfs(i);
      int d = get_diam(i);
      for (int u : cur)
        unite(u, cur[0]);
      int r = root(cur[0]);
      diam[r] = d;
    }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      x--;
      x = root(x);
      cout << diam[x] << "\n";
    }
    else {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      unite(a, b);
    }
  }


  return 0;
}