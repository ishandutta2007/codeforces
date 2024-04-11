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
const li mod = 1000000007;

const int C = 5010;
int stir[C][C];

void solve(bool read) {
  for (int i = 0; i < C; ++i) {
    stir[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      stir[i][j] = stir[i - 1][j - 1] + ((j * 1LL * stir[i - 1][j]) % mod);
      if (stir[i][j] >= mod) {
        stir[i][j] -= mod;
      }
    }
    /*if (i < 10) {
      for (int j = 0; j < 10; ++j) {
        cout << stir[i][j] << " ";
      }
      cout << endl;
    }*/
  }
  int n, k;
  cin >> n >> k;

  li res = 0;
  li prod = 1;
  li rev2 = binpow(2LL, mod - 2, mod);
  li cur_power = binpow(2LL, (li)n, mod);
  for (int i = 0; i <= k && i <= n; ++i) {
    res += prod * stir[k][i] % mod * cur_power;
    res %= mod;
    prod = prod * ((n - i) % mod) % mod;
    cur_power = cur_power * rev2 % mod;
  }
  if (res < 0) {
    res += mod;
  }
  cout << res << "\n";

}