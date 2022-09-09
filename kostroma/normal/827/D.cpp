#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
    //cout << "Case #" << testNum++ << ": ";
    //cerr << testNum << endl;
    solve(true);
    //cerr << testNum - 1 << endl;
  }
  cout.flush();
#ifdef AIM1
  while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

void precalc() {

}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

//#define int li
//const int mod = 1000000007;

struct Edge {
  int from;
  int to;
  int wei;
  int id;
  bool operator < (const Edge& ot) const {
    return wei < ot.wei;
  }
};

const int L = 18;
vector<vector<Edge>> g;
vector<int> tin, tout;
vector<vector<int>> parent;
vector<vector<int>> max_wei, min_wei;

bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (upper(a, b)) {
    return a;
  }
  for (int i = L - 1; i >= 0; --i) {
    if (!upper(parent[i][a], b)) {
      a = parent[i][a];
    }
  }
  return parent[0][a];
}

void dfs(int v, int p, int w) {
  static int TIMER = 1;
  tin[v] = TIMER++;
  parent[0][v] = p;
  max_wei[0][v] = w;
  for (int i = 1; i < L; ++i) {
    parent[i][v] = parent[i - 1][parent[i - 1][v]];
    max_wei[i][v] = max(max_wei[i - 1][v], max_wei[i - 1][parent[i - 1][v]]);
  }
  for (auto item : g[v]) {
    if (item.to == p) {
      continue;
    }
    dfs(item.to, v, item.wei);
  }
  tout[v] = TIMER++;
}

vector<int> dsu;

void init(int n) {
  dsu.resize(n);
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
  }
}

int find_set(int v) {
  if (dsu[v] == v) {
    return v;
  }
  return dsu[v] = find_set(dsu[v]);
}

bool merge(int q, int w) {
  q = find_set(q);
  w = find_set(w);
  if (q == w) {
    return false;
  }
  dsu[w] = q;
  return true;
}

int get_max_wei(int a, int c) {
  int res = 0;
  if (a == c) {
    return res;
  }
  for (int i = L - 1; i >= 0; --i) {
    if (!upper(parent[i][a], c)) {
      relax_max(res, max_wei[i][a]);
      a = parent[i][a];
    }
  }
  relax_max(res, max_wei[0][a]);
  return res;
}

void make_relax(int a, int c, int w) {
  if (a == c) {
    return;
  }
  for (int i = L - 1; i >= 0; --i) {
    if (!upper(parent[i][a], c)) {
      relax_min(min_wei[i][a], w);
      a = parent[i][a];
    }
  }
  relax_min(min_wei[0][a], w);
}

const int INF = (int)2e9;

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].from >> edges[i].to >> edges[i].wei;
    edges[i].id = i;
    --edges[i].from;
    --edges[i].to;
  }
  sort(all(edges));
  init(n);

  g.resize(n);
  tin.resize(n);
  tout.resize(n);
  parent.assign(L, vector<int>(n, 0));
  max_wei.assign(L, vector<int>(n, 0));
  min_wei.assign(L, vector<int>(n, INF));

  vector<char> in_mst(m, false);
  for (int i = 0; i < m; ++i) {
    int a = edges[i].from, b = edges[i].to;
    if (merge(a, b)) {
      in_mst[edges[i].id] = true;
      Edge e = edges[i];
      g[a].push_back(e);
      swap(e.from, e.to);
      g[b].push_back(e);
    }
  }
  dfs(0, 0, 0);

  vector<int> ans(m);

  for (int i = 0; i < m; ++i) {
    if (in_mst[edges[i].id]) {
      continue;
    }
    int a = edges[i].from, b = edges[i].to;
    int c = lca(a, b);
    //cout << a << " " << b << " " << c << endl;
    int cur_res = max(get_max_wei(a, c), get_max_wei(b, c));
    //cout << i << " " << cur_res << endl;
    ans[edges[i].id] = cur_res - 1;

    make_relax(a, c, edges[i].wei);
    make_relax(b, c, edges[i].wei);
  }

  for (int i = L - 1; i > 0; --i) {
    for (int j = 0; j < n; ++j) {
      relax_min(min_wei[i - 1][j], min_wei[i][j]);
      relax_min(min_wei[i - 1][parent[i - 1][j]], min_wei[i][j]);
    }
  }

  for (int i = 0; i < m; ++i) {
    if (!in_mst[edges[i].id]) {
      continue;
    }
    int a = edges[i].from, b = edges[i].to;
    if (!upper(a, b)) {
      swap(a, b);
    }
    assert(upper(a, b));
    int cur_res = min_wei[0][b];
    if (cur_res > INF - 5) {
      ans[edges[i].id] = -1;
    } else {
      ans[edges[i].id] = cur_res - 1;
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

}