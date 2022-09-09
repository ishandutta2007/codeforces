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

char can[5005][5005];

void solve(bool read) {
  string s;
  cin >> s;
  int n = (int)s.length();
  int ans = 0;
  for (int w = 0; w < 2; ++w) {
    for (int l = 0; l < n; ++l) {
      int bal = 0;
      int open = 0;
      for (int r = l; r < n; ++r) {
        if (s[r] != ')') {
          ++bal;
          if (s[r] == '(') {
            ++open;
          }
        } else {
          --bal;
        }
        if (bal < 0) {
          break;
        }
        if (bal % 2 == 0 && open <= (r + 1 - l) / 2) {
          if (w == 0) {
            ++can[l][r];
          } else {
            ++can[n - r - 1][n - l - 1];
          }
        }
      }
    }
    reverse(all(s));
    for (char& c : s) {
      if (c == ')') {
        c = '(';
      } else if (c == '(') {
        c = ')';
      }
    }
  }
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      if (can[l][r] == 2) {
        ++ans;
      }
    }
  }
  cout << ans << "\n";
}