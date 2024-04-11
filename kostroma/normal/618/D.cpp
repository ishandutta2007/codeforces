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

#define int li
//const int mod = 1000000007;

vector<vector<int>> g;

vector<vector<int>> dp;

void dfs(int v, int p) {
  dp[v].assign(2, (int)1e9);
  vector<int> inner_dp(3, (int)1e9);
  inner_dp[0] = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
    vector<int> new_inner_dp(3, (int)1e9);
    for (int i = 0; i < 3; ++i) {
      relax_min(new_inner_dp[i], inner_dp[i] + min(dp[to][0], dp[to][1])); //   
    }
    relax_min(new_inner_dp[1], inner_dp[0] + dp[to][1]);
    relax_min(new_inner_dp[2], inner_dp[1] + dp[to][1] - 1);
    inner_dp = new_inner_dp;
  }
  dp[v][0] = min(inner_dp[1], inner_dp[2]);
  dp[v][1] = min(inner_dp[1], 1 + inner_dp[0]);
}

void solve(bool read) {
  int n, x, y;
  cin >> n >> x >> y;
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  if (x >= y) {
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, (int)g[i].size());
    }
    if (mx == n - 1) {
      cout << x + (n - 2) * y << endl;
    } else {
      cout << (n - 1) * y << endl;
    }
    return;
  }

  dp.resize(n);
  dfs(0, 0);

  int ans = min(dp[0][0], dp[0][1]);

  cout << (ans - 1) * y + x * (n - ans) << endl;


}