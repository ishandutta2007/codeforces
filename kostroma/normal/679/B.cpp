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

const int C = 2000010;

pair<int, int> max_blocks[C];

int step(int n) {
  return n * n * n;
}

map<int, pair<int, int>> dp;

pair<int, int> calc(int pref) {
  if (pref < C) {
    return max_blocks[pref];
  }
  if (dp.count(pref)) {
    return dp[pref];
  }
  auto& res = dp[pref];
  int m = pow(pref, 1.0 / 3) - 3;
  while (step(m + 1) <= pref) {
    ++m;
  }
  if (pref == step(m + 1) - 1) {
    for (int x = 1; x <= m; ++x) {
      auto cur_res = calc(step(x + 1) - step(x) - 1);
      cur_res.first += 1;
      cur_res.second += step(x);
      if (res.first <= cur_res.first) {
        res = cur_res;
      }
    }
    //cerr << pref << " " << res.first << " " << res.second << endl;
    return res;
  }
  res = calc(step(m) - 1);
  pref = pref - step(m);
  auto cur_res = calc(pref);
  cur_res = {cur_res.first + 1, step(m) + cur_res.second};
  if (res.first <= cur_res.first) {
    res = cur_res;
  }
  //cerr << pref + step(m) << " " << res.first << " " << res.second << endl;
  return res;
}

void solve(bool read) {
  int m = 1;
  for (int i = 1; i < C; ++i) {
    while (step(m + 1) <= i) {
      ++m;
    }
    max_blocks[i].second = i;
    max_blocks[i].first = 1 + max_blocks[i - step(m)].first;
  }
  for (int i = 1; i < C; ++i) {
    if (max_blocks[i].first < max_blocks[i - 1].first) {
      max_blocks[i] = max_blocks[i - 1];
    }
  }

  int border;
  cin >> border;
  auto res = calc(border);
  cout << res.first << " " << res.second << endl;
}