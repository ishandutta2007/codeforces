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
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> a(n), b(k);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  sort(all(b));
  int L = -1, R = 1e10;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    bool flag = true;
    vector<char> used(k, false);
    for (int i = 0; i < n; ++i) {
      int best = -1;
      for (int j = 0; j < k; ++j) {
        if (used[j]) {
          continue;
        }
        int dist = abs(b[j] - a[i]) + abs(b[j] - p);
        if (dist <= M) {
          best = j;
          break;
        }
      }
      if (best == -1) {
        flag = false;
        break;
      }
      used[best] = true;
    }
    if (flag) {
      R = M;
    } else {
      L = M;
    }
  }
  cout << R << endl;

}