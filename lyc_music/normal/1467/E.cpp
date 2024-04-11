// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define poly vector<int>
#define SZ(a) int(a.size())
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 500005;
int a[N], cnt, n;
map<int, int> Map;

vector<int> adj[N];
int dfn[N], sz[N], dep[N], scc;
int f[N][20], id[N];
void dfs(int u, int fa) {
  dfn[u] = ++scc, id[scc] = u, dep[u] = dep[fa] + 1;
  f[u][0] = fa;
  for (int i = 1; i < 20; i++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
  }
  sz[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v]; 
  }
} 
int jump(int u, int v) {
  int len = dep[u] - dep[v] - 1;
  for (int i = 19; i >= 0; i--) {
    if (len >> i & 1) {
      u = f[u][i];
    }
  }
  return u;
}
set<int> col[N];

ll d[N], ans;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (!Map[a[i]]) Map[a[i]] = ++cnt;
    a[i] = Map[a[i]];
  }
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i <= n; i++) {
    col[a[i]].insert(dfn[i]);
    adj[a[i]].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!col[i].size()) continue;
    for (auto v: adj[i]) {
      int l = dfn[v], r = dfn[v] + sz[v] - 1;
      if (l < r) {
        auto it = col[i].lower_bound(l + 1);
        if (it != col[i].end() && *it <= r) {
          int t = jump(id[*it], v);
          //printf("v = %d, it = %d, t = %d\n", v, id[*it], t);
          d[1]++, d[dfn[t]]--;
          d[dfn[t] + sz[t]]++;
          it++;
        }
        it = col[i].upper_bound(r);
        if (it != col[i].begin()) {
          it--;
          if (*it > l && *it <= r) {
            int t = jump(id[*it], v);
            //printf("v = %d, it = %d, t = %d\n", v, id[*it], t);
            d[1]++, d[dfn[t]]--;
            d[dfn[t] + sz[t]]++;
            it++;
          }
        }
      }
      if (l > 1) {
        auto it = col[i].begin();
        if (it != col[i].end() && *it < l) {
          //printf("v = %d\n", v);
          d[dfn[v]]++, d[r + 1]--;
        }
      }
      if (r < n) {
        auto it = col[i].lower_bound(r + 1);
        if (it != col[i].end() && *it <= n) {
          //printf("v = %d\n", v);
          d[dfn[v]]++, d[r + 1]--;
        }
      }
    }
  }
  //for (int i = 1; i <= n; i++) {
  //  printf("dfn[%d] = %d\n", i, dfn[i]);
  //}
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
    if (d[i] == 0) ans++;
  }
  printf("%lld\n", ans);
  return 0;
}