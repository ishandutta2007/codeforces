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

void solve(bool read) {
  vector<int> state(10, -1);
  int n;
  cin >> n;
  while (n--) {
    char c;
    int cur;
    cin >> c >> cur;
    if (c == '&') {
      for (int i = 0; i < 10; ++i) {
        if (!(cur & (1 << i))) {
          state[i] = 0;
        }
      }
    } else if (c == '|') {
      for (int i = 0; i < 10; ++i) {
        if (cur & (1 << i)) {
          state[i] = 1;
        }
      }
    } else {
      for (int i = 0; i < 10; ++i) {
        if (cur & (1 << i)) {
          if (state[i] < 0) {
            if (state[i] == -1) {
              --state[i];
            } else {
              ++state[i];
            }
          } else {
            state[i] ^= 1;
          }
        }
      }
    }
  }

  int make_and = 1023, make_or = 0, make_xor = 0;
  for (int i = 0; i < 10; ++i) {
    if (state[i] >= 0) {
      if (state[i] == 0) {
        make_and ^= (1 << i);
      } else {
        make_or |= (1 << i);
      }
    } else {
      if (state[i] == -2) {
        make_xor ^= (1 << i);
      }
    }
  }

  cout << 3 << endl;
  cout << "& " << make_and << endl;
  cout << "| " << make_or << endl;
  cout << "^ " << make_xor << endl;

}