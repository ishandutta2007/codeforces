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
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
    cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }
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

int gcd (int a, int b, int & x, int & y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

void solve(bool read) {
  int x, y, p, q;
  cin >> x >> y >> p >> q;
  int g = gcd(p, q);
  p /= g; q /= g;
  int a, b;

  if (p == 0) {
    if (x > 0) {
      cout << "-1\n";
      return;
    }
    cout << "0\n";
    return;
  }

  gcd(q, p, a, b);
  b = -b;
  int c = p * y - q * x;
  int add_b = c / p;
  c -= p * add_b;
  a *= c;
  b *= c;
  b -= add_b;

  int L = -3e9, R = 3e9;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    if ((q - p) * M >= a - b) {
      R = M;
    } else {
      L = M;
    }
  }

  int minT = R;

  L = -3e9, R = 3e9;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    if (a + p * M >= 0) {
      R = M;
    } else {
      L = M;
    }
  }

  minT = max(minT, R);

  if (minT > 3e9 - 100) {
    cout << "-1\n";
    return;
  }

  a = a + p * minT;
  b = b + q * minT;

  cout << b << "\n";

}