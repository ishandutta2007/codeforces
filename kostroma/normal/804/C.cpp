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
  cout.flush();

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

vector<vector<int>> g;
vector<vector<int>> a;

vector<int> col;

void dfs(int v, int p) {
  vector<int> used_cols;
  vector<int> to_state;
  for (int x : a[v]) {
    if (col[x] != -1) {
      used_cols.push_back(col[x]);
    } else {
      to_state.push_back(x);
    }
  }
  sort(all(used_cols));
  used_cols.erase(unique(all(used_cols)), used_cols.end());
  int uk = 0;
  for (int c : to_state) {
    while (true) {
      auto it = lower_bound(all(used_cols), uk);
      if (it != used_cols.end() && *it == uk) {
        ++uk;
        continue;
      }
      col[c] = uk++;
      break;
    }
  }
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
  }
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int root = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].size() > a[root].size()) {
      root = i;
    }
  }

  col.resize(m, -1);
  dfs(root, root);

  int cols = max((int)a[root].size(), 1);
  cout << cols << endl;
  for (int x : col) {
      if (x == -1) x = 0;
    cout << x + 1 << " ";
  }
  cout << endl;

}