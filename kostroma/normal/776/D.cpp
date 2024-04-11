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
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
    //cerr << testNum << endl;
    //cout << "Case #" << testNum++ << ": ";
    solve(true);
    ++testNumber;
    //++timer;
  }

  /*while (true) {
      solve(false);
  }*/

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

//#define int li

//const int mod = 1000000007;

int n;
vector < vector<int> > g, gt;
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
  for (size_t i=0; i<gt[v].size(); ++i) {
    int to = gt[v][i];
    if (comp[to] == -1)
      dfs2 (to, cl);
  }
}

void add_edge(int a, int b) {
  g[a].push_back(b);
  g[b ^ 1].push_back(a ^ 1);
  gt[b].push_back(a);
  gt[a ^ 1].push_back(b ^ 1);
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<vector<int>> a(n);
  for (int i = 0; i < m; ++i) {
    int cur;
    cin >> cur;
    for (int j = 0; j < cur; ++j) {
      int id;
      cin >> id;
      --id;
      a[id].push_back(i);
    }
  }

  int N = 2 * m;

  g.resize(N);
  gt.resize(N);
  for (int i = 0; i < n; ++i) {
    int fs = a[i][0], sc = a[i][1];
    if (!r[i]) {
      add_edge(2 * fs, 2 * sc + 1);
      add_edge(2 * fs + 1, 2 * sc);
    } else {
      add_edge(2 * fs, 2 * sc);
      add_edge(2 * fs + 1, 2 * sc + 1);
    }
  }

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
      cout << "NO\n";
      return;
    }

  cout << "YES\n";
}