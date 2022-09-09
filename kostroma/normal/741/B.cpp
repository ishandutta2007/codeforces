#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
  freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
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
    solve();
    ++testNumber;
    //++timer;
  }

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

template <typename T>
using Matrix = vector<vector<T>>;

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

void solve() {
  int n, m, W;
  cin >> n >> m >> W;
  init(n);
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    merge(x, y);
  }

  vector<vector<int>> groups(n);
  for (int i = 0; i < n; ++i) {
    groups[find_set(i)].push_back(i);
  }

  vector<int> dp(W + 1, -1e9);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    auto new_dp = dp;
    int sum_b = 0, sum_w = 0;
    for (int girl : groups[i]) {
      for (int cur = W; cur >= 0; --cur) {
        if (cur >= w[girl] && dp[cur - w[girl]] + b[girl] > new_dp[cur]) {
          new_dp[cur] = dp[cur - w[girl]] + b[girl];
        }
      }
      sum_w += w[girl];
      sum_b += b[girl];
    }
    for (int cur = W; cur >= 0; --cur) {
      if (cur >= sum_w && dp[cur - sum_w] + sum_b > new_dp[cur]) {
        new_dp[cur] = dp[cur - sum_w] + sum_b;
      }
    }
    new_dp.swap(dp);
  }

  int res = 0;
  for (int i = 0; i <= W; ++i) {
    res = max(res, dp[i]);
  }

  cout << res << "\n";

}