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
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
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
//const li mod = 1000000007;

//using ull = unsigned long long;

const int C = 5050;
int best_dp[C][C];

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    //a[i] = rand();
    cin >> a[i];
  }
  vector<int> last_dp(n + 1, 0);
  auto cur_dp = last_dp;
  for (int i = n - 1; i >= 0; --i) {
    cur_dp[0] = a[i];
    for (int j = 1; j < cur_dp.size(); ++j) {
      cur_dp[j] = cur_dp[j - 1] ^ last_dp[j - 1];
    }
    for (int j = 0; j < cur_dp.size(); ++j) {
      int r = i + j;
      if (r < C) {
        best_dp[i][r] = cur_dp[j];
      }
    }
    cur_dp.swap(last_dp);
  }
  for (int l = 0; l < C; ++l) {
    for (int r = l; r + 1 < C; ++r) {
      relax_max(best_dp[l][r + 1], best_dp[l][r]);
    }
  }
  for (int r = C - 1; r >= 0; --r) {
    for (int l = r; l > 0; --l) {
      relax_max(best_dp[l - 1][r], best_dp[l][r]);
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l; --r;
    cout << best_dp[l][r] << "\n";
  }

}