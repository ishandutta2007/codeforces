#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
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

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

//#define int li
//const int mod = 1000000007;


void solve(bool read) {
  vector<int> a(3);
  vector<int> t(2);
  cin >> a[0] >> a[1] >> a[2] >> t[0] >> t[1];
  a[0] %= 12;
  t[0] %= 12;
  t[1] %= 12;
  a[0] *= 5;
  t[0] *= 5;
  t[1] *= 5;

  int hour = a[0] * 60 * 60 + a[1] * 60 + a[2];
  int minute = a[1] * 60 * 60 + a[2] * 60;
  int seconds = a[2] * 60 * 60;
  a = {hour, minute, seconds};

  for (int& cur_t : t) {
    cur_t *= 60 * 60;
  }

  //cout << hour << " " << minute << " " << seconds << endl;

  for (int dir = -1; dir <= 1; dir += 2) {
    int now = t[0];
    while (true) {
      if (now == t[1]) {
        cout << "YES\n";
        return;
      }
      bool can = true;
      for (int x : a) {
        if (x == now) {
          can = false;
          break;
        }
      }
      if (!can) {
        break;
      }
      now = (now + dir + 60 * 60 * 60) % (60 * 60 * 60);
    }
  }

  cout << "NO\n";

}