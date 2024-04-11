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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
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

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

//#define int li
//const int mod = 1000000007;

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

void merge(int q, int w) {
  q = find_set(q);
  w = find_set(w);
  dsu[w] = q;
}

vector<vector<int>> g, revg;

void add_edge(int a, int b) {
  g[a].push_back(b);
  g[b ^ 1].push_back(a ^ 1);
  revg[b].push_back(a);
  revg[a ^ 1].push_back(b ^ 1);
}

vector<bool> used;
vector<int> order, comp;

void dfs1 (int v) {
  used[v] = true;
  for (size_t i=0; i<g[v].size(); ++i) {
    int to = g[v][i];
    if (!used[to])
      dfs1 (to);
  }
  order.push_back (v);
}

void dfs2 (int v, int cl) {
  comp[v] = cl;
  for (size_t i=0; i<revg[v].size(); ++i) {
    int to = revg[v][i];
    if (comp[to] == -1)
      dfs2 (to, cl);
  }
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> words(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    words[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> words[i][j];
      --words[i][j];
    }
  }
  init(m);

  g.resize(2 * m);
  revg.resize(2 * m);

  for (int i = 0; i + 1 < n; ++i) {
    int lcp = 0;
    while (lcp < words[i].size() && lcp < words[i + 1].size() && words[i][lcp] == words[i + 1][lcp]) {
      ++lcp;
    }
    if (lcp == words[i].size()) {
      continue;
    }
    if (lcp == words[i + 1].size()) {
      cout << "No\n";
      return;
    }
    if (words[i][lcp] < words[i + 1][lcp]) {
      add_edge(2 * words[i + 1][lcp] + 1, 2 * words[i][lcp] + 1);
      continue;
    }
    add_edge(2 * words[i][lcp], 2 * words[i][lcp] + 1);
    add_edge(2 * words[i + 1][lcp] + 1, 2 * words[i + 1][lcp]);
  }

  int N = 2 * m;
  used.assign (N, false);
  for (int i=0; i<N; ++i)
    if (!used[i])
      dfs1 (i);

  comp.assign (N, -1);
  for (int i=0, j=0; i<N; ++i) {
    int v = order[N-i-1];
    if (comp[v] == -1)
      dfs2 (v, j++);
  }

  for (int i=0; i<N; ++i)
    if (comp[i] == comp[i^1]) {
      cout << "No\n";
      return;
    }
  cout << "Yes\n";

  vector<int> ans;
  for (int i=1; i<N; i += 2) {
    if (comp[i] > comp[i ^ 1]) {
      ans.push_back(i / 2);
    }
  }

  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << endl;

}