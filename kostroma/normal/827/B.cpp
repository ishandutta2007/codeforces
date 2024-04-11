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

void solve(bool read) {
  int n, k;
  cin >> n >> k;
  /*if (k == n - 1) {
    cout << 2 << endl;
    for (int i = 1; i < n; ++i) {
      cout << 1 << " " << i + 1 << endl;
    }
    return;
  }
  if (k == n - 2) {
    cout << 3 << endl;
    for (int i = 2; i < n; ++i) {
      cout << 1 + (i % 2) << " " << i + 1 << endl;
    }
    return;
  }*/

  vector<pair<int, int>> edges;

  int L = 1, R = n - k + 4;
  while (L + 1 < R) {
    int d = (L + R) / 2;
    int rest_leaves = k - 2, rest_big = n - k - (d - 2);
    int len = (d - 1) / 2;
    if (rest_leaves * (len - 1) >= rest_big) {
      edges.clear();
      for (int i = 0; i + 1 < d; ++i) {
        edges.push_back({i, i + 1});
      }
      int last_v = d;
      for (int i = 0; i < rest_leaves; ++i) {
        int prev_v = d / 2;
        for (int j = 0; j + 1 < len && rest_big > 0; ++j) {
          edges.push_back({prev_v, last_v});
          prev_v = last_v;
          ++last_v;
          --rest_big;
        }
        edges.push_back({prev_v, last_v});
        ++last_v;
      }
      R = d;
    } else {
      L = d;
    }
  }

  assert(!edges.empty());

  cout << R - 1 << endl;
  for (auto item : edges) {
    cout << item.first + 1 << " " << item.second + 1 << endl;
  }

}