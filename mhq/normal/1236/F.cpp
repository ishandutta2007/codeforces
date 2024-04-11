#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5 * (int)1e5 + 100;
int n, m;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
  return (1LL * a * b) % mod;
}
int pw(int a, int b) {
  if (b == 0) return 1;
  if (b & 1) return mult(a, pw(a, b - 1));
  int res = pw(a, b / 2);
  return mult(res, res);
}
int sub(int a, int b) {
  int s = a - b;
  if (s < 0) s += mod;
  return s;
}
int sum(int a, int b) {
  int s = a + b;
  if (s >= mod) s -= mod;
  return s;
}
vector < int > cyc;
int st_number[maxN];
int used[maxN];
vector < vector < int > > cycles;
vector < int > g[maxN];
int pw2[maxN]; int inv2[maxN];
void dfs(int v, int p) {
  used[v] = 1;
  st_number[v] = cyc.size();
  cyc.push_back(v);
  for (int to : g[v]) {
    if (used[to] == 2) continue;
    if (used[to] == 0) {
      dfs(to, v);
    }
    if (used[to] == 1 && to != p) {
      vector < int > nall;
      for (int i = st_number[to]; i < cyc.size(); i++) nall.push_back(cyc[i]);
      cycles.push_back(nall);
      continue;
    }
  }
  used[v] = 2;
  cyc.pop_back();
}
int vertex() {
  return mult(n, inv2[1]);
}
int edges() {
  return mult(m, inv2[2]);
}
int cyces() {
  int tot = 0;
  for (auto it : cycles) {
    tot = sum(tot, inv2[it.size()]);
  }
  return tot;
}
int vert2() {
  int ans = mult(mult(n, n - 1), inv2[2]);
  ans = sum(ans, mult(n, inv2[1]));
  return ans;
}
int edges2() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int to : g[i]) {
      if (i > to) continue;
      // i < to
      int other_edges = m - g[i].size() - g[to].size() + 1;
      int not_other = g[i].size() - 1 + g[to].size() - 1;
      ans = sum(ans, mult(other_edges, inv2[4]));
      ans = sum(ans, mult(not_other, inv2[3]));
    }
  }
  ans = sum(ans, mult(m, inv2[2]));
  return ans;
}
int veredges() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int other_edges = m - g[i].size();
    ans = sum(ans, mult(other_edges, inv2[3]));
    int my_edges = g[i].size();
    ans = sum(ans, mult(my_edges, inv2[2]));
  }
  return ans;
}
vector < int > bySz[maxN];
int vercycles() {
  int ans = 0;
  int tot = cyces();
  for (int i = 1; i <= n; i++) {
    int val = tot;
    for (int sz : bySz[i]) {
      val = sub(val, inv2[sz]);
    }
    ans = sum(ans, mult(inv2[1], val));
    ans = sum(ans, sub(tot, val));
  }
  return ans;
}
int cyccyc() {
  int total = cyces();
  int ans = 0;
  for (auto it : cycles) {
    int my_sz = it.size();
    int coef = inv2[my_sz];
    ans = sum(ans, coef);
    int val = total;
    for (int v : it) {
      for (int sz : bySz[v]) {
        val = sub(val, inv2[sz]);
      }
      val = sum(val, inv2[my_sz]);
    }
    val = sub(val, inv2[my_sz]);
    ans = sum(ans, mult(inv2[my_sz], val));
    int rest = sub(total, sum(val, inv2[my_sz]));
    // they have 2
    ans = sum(ans, mult(mult(inv2[my_sz], 2), rest));
  }
  return ans;
}
int cycedges() {
  int ans = 0;
  for (auto it : cycles) {
    int my_sz = it.size();
    int edges_inside = my_sz;
    ans = sum(ans, mult(edges_inside, inv2[my_sz]));
    int edges_not_inside = 0;
    for (int u : it) {
      edges_not_inside = sum(edges_not_inside, g[u].size() - 2);
    }
    int left_edges = m - edges_inside - edges_not_inside;
    ans = sum(ans, mult(edges_not_inside, inv2[my_sz + 1]));
    ans = sum(ans, mult(left_edges, inv2[my_sz + 2]));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input.txt", "r", stdin);
  cin >> n >> m;
  pw2[0] = 1;
  for (int i = 1; i < maxN; i++) {
    pw2[i] = mult(pw2[i - 1], 2);
  }
  inv2[0] = 1;
  for (int i = 1; i < maxN; i++) {
    inv2[i] = mult(inv2[i - 1], (mod + 1) / 2);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  for (auto it : cycles) {
    for (int v : it) bySz[v].push_back(it.size());
  }
  int ex = sub(sum(vertex(), cyces()), edges());
  ex = pw(ex, 2);
  int v2 = vert2();
  int c2 = cyccyc();
  int ed2 = edges2();
  int val = sum(sum(v2, c2), ed2);
  int other_coef = vercycles();
  other_coef = sub(other_coef, sum(cycedges(), veredges()));
  other_coef = mult(other_coef, 2);
  val = sum(other_coef, val);
  val = sub(val, ex);
  cout << val;
  return 0;
}