#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5;

vector<int> g[N];
vector<int> w[N];
vector<int> packid[N];
vector<int> id[N];
int for_id[N];
int for_packid[N];
int ans[N];
int tin[N];
int tout[N];
int h[N];
int timer = 0;
int n;
bool zero[N];

void dfs0(int v, int hei) {
  h[v] = hei;
  tin[v] = timer++;
  for (int to : g[v])
    dfs0(to, hei + 1);
   tout[v] = timer++;
}

bool is_anc(int a, int b) {
  return tin[a] <= tin[b] && tin[b] <= tout[a];
}

struct Tree {
  vector<int> val;
  
  Tree(int n = 0) {
    val.assign(4 * n + 10, -1);
  }
  
  void put(int i, int l, int r, int pos, int nval) {
    if (l == pos && r == pos) {
      val[i] = nval;
      return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
      put(2 * i + 1, l, m, pos, nval);
    else
      put(2 * i + 2, m + 1, r, pos, nval);
    val[i] = max(val[2 * i + 1], val[2 * i + 2]);
  }
  
  int get(int i, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
      return val[i];
    int sl = -1;
    int sr = -1;
    int m = (tl + tr) / 2;
    if (l <= m)
      sl = get(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
      sr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    return max(sl, sr);
  }
};

Tree tree;

void dfs(int v) {
  for (int now : packid[v])
    for (int q : id[for_packid[now]]) {
      int u = for_id[q];
      if (u == v || (is_anc(u, v) && tree.get(0, 0, n - 1, h[u], h[v] - 1) < now))
        ans[q] = 1;
      else
        ans[q] = 0;
    }
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    int t = w[v][i];
    tree.put(0, 0, n - 1, h[v], t);
    dfs(to);
  }
}
  

int main() {
  ios_base::sync_with_stdio(0);
  
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    ans[i] = -1;
  int cnt = 0;
  fill(zero, zero + n, true);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[y].push_back(x);
      w[y].push_back(i);
      zero[x] = false;
    } else if (t == 2) {
      int x;
      cin >> x;
      --x;
      cnt++;
      for_packid[i] = cnt;
      packid[x].push_back(i);
    } else {
      int x, p;
      cin >> x >> p;
      --x;
      id[p].push_back(i);
      for_id[i] = x;
    }
  }
  tree = Tree(n);
  for (int i = 0; i < n; i++)
    if (zero[i])
      dfs0(i, 0);
  for (int i = 0; i < n; i++)
    if (zero[i])
      dfs(i);
  for (int i = 0; i < m; i++)
    if (ans[i] == 0)
      cout << "NO\n";
    else if (ans[i] == 1)
      cout << "YES\n";
      
  return 0;
}