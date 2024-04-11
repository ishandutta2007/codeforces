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

struct Edge {
  int to;
  int c;
};

vector<vector<Edge>> g;

int dp[111][111][27];

vector<char> used;
vector<int> order;

void dfs(int v) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  for (auto e : g[v]) {
    dfs(e.to);
  }
  order.push_back(v);
}

void solve(bool read) {
  int n;
  cin >> n;
  g.resize(n);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].push_back({b, c - 'a'});
  }
  used.assign(n, false);
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  for (int mx = 0; mx < 2 * order.size(); ++mx) {
    for (int i = 0; i <= mx && i < order.size(); ++i) {
      int v = order[i];
      int j = mx - i;
      if (j < 0 || j >= order.size()) {
        continue;
      }
      int u = order[j];
      for (int c = 0; c < 26; ++c) {
        for (auto e : g[v]) {
          if (e.c >= c && !dp[u][e.to][e.c]) {
            dp[v][u][c] = 1;
            break;
          }
        }
        //cout << v + 1 << " " << u + 1 << " " << c << " " << dp[v][u][c] << endl;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j][0]) {
        cout << "A";
      } else {
        cout << "B";
      }
    }
    cout << "\n";
  }

}