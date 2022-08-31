#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 3e6 + 7;

vector <int> g[N];
vector <int> rg[N];

void add_edge(int u, int v) {
  g[u].push_back(v);
  rg[v].push_back(u);
}

vector <int> t;

bool u[N];

void dfs(int v) {
  u[v] = true;
  for (int to : g[v]) {
    if (!u[to]) {
      dfs(to);
    }
  }
  t.push_back(v);
}

int id = 0;

int comp[N];
bool vis[N];

void zhfs(int v) {
  vis[v] = true;
  comp[v] = id;
  for (int to : rg[v]) {
    if (!vis[to]) {
      zhfs(to);
    }
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (auto &c : a[i]) c -= '0';
  }
  vector <string> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    for (auto &c : b[i]) c -= '0';
  }
  string s;
  cin >> s;
  for (auto &c : s) c -= '0';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int si = 0; si < 2; si++) {
        for (int sj = 0; sj < 2; sj++) {
          int x = a[i][j] ^ (si & s[j]) ^ (sj & s[i]);
          int y = b[i][j];
          if (x != y) {
            add_edge(i * 2 + si, (n + j) * 2 + (sj ^ 1));
            add_edge((n + j) * 2 + sj, i * 2 + (si ^ 1));
          }
        }
      }
    }
  }
  int sz = 4 * n;
  for (int i= 0; i < sz; i++) {
    if (!u[i]) {
      dfs(i);
    }
  }
  reverse(t.begin(), t.end());
  for (int v : t) {
    if (!vis[v]) {
      zhfs(v);
      id++;
    }
  }
  vector <int> ans;
  int f = 0;
  for (int i = 0; i < n + n; i++) {
    if (comp[i * 2] == comp[i * 2 + 1]) {
      cout << -1 << '\n';
      return 0;
    }
    if (comp[i * 2] < comp[i * 2 + 1]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (int i : ans) {
    if (i < n) {
      cout << "row " << i << '\n';
    } else {
      cout << "col " << i - n << '\n';
    }
  }
}