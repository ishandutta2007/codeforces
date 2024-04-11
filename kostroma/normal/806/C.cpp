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
    //cin >> t;
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

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  const int L = 42;
  vector<int> num(L, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int cur = a[i];
    int cnt = 0;
    while (cur % 2 == 0) {
      cur /= 2;
      ++cnt;
    }
    if (cur == 1) {
      ++num[cnt];
    }
  }

  vector<int> possible(L);
  for (int i = 0; i < n; ++i) {
    int cur = a[i];
    if (cur & (cur - 1)) {
      for (int j = 0; j < L; ++j) {
        if (cur < (1LL << (j + 1)) && cur > (1LL << j)) {
          ++possible[j];
        }
      }
    }
  }

  vector<int> res;
  for (int x = 1; x <= num[0]; ++x) {
    int tails = num[0] - x;
    int rest = x;
    bool f = true;
    for (int j = 1; j < L; ++j) {
      tails += possible[j - 1];
      int cont = min(rest, num[j]);
      int used_tails = min(rest - cont, tails);
      tails -= used_tails;
      tails += num[j] - cont;
      rest = cont;
      /*if (x == 2) {
        cout << j << " " << rest << " " << tails << endl;
      }*/
    }
    if (f && tails == 0) {
      res.push_back(x);
    }
  }

  if (res.empty()) {
    cout << "-1\n";
  } else {
    for (int x : res) {
      cout << x << " ";
    }
    cout << endl;
  }


}