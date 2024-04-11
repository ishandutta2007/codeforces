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
  cin >> t;
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

void precalc() {

}

#define int li
//const int mod = 1000000007;

void solve(bool read) {
  int a,b;
  cin >> a >> b;
  int pr = a * b;
  int cur = max(1LL, (int)(pow(pr, 1.0 / 3) - 10));
  while (cur * cur * cur < pr) {
    ++cur;
  }
  if (cur * cur * cur != pr) {
    cout << "No\n";
    return;
  }

  vector<int> primes;
  for (int i = 2; i * i <= cur; ++i) {
    if (cur % i == 0) {
      primes.push_back(i);
      while (cur % i == 0) {
        cur /= i;
      }
    }
  }
  if (cur > 1) {
    primes.push_back(cur);
  }

  for (int p : primes) {
    int cnt_a = 0, cnt_b = 0;
    int cur_a = a, cur_b = b;
    while (cur_a % p == 0) {
      cur_a /= p;
      ++cnt_a;
    }
    while (cur_b % p == 0) {
      cur_b /= p;
      ++cnt_b;
    }
    if (min(cnt_a, cnt_b) * 2 >= max(cnt_a, cnt_b)) {
      continue;
    } else {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";

}