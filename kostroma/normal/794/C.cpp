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

//const int mod = 1000000007;

//#define int li

void solve(bool read) {
  vector<string> s(2);
  for (int i = 0; i < 2; ++i) {
    cin >> s[i];
    sort(all(s[i]));
  }
  int n = (int)s[0].length();
  s[0].resize((n + 1) / 2);
  s[1] = s[1].substr((n + 1) / 2, n / 2);
  string res(n, 0);
  int lef_res = 0, right_res = n - 1;
  vector<int> lef(2, 0), rig(2, 0);
  for (int i = 0; i < 2; ++i) {
    rig[i] = (int)s[i].length() - 1;
  }
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (rig[1] < 0 || s[0][lef[0]] < s[1][rig[1]]) {
        res[lef_res++] = s[0][lef[0]++];
      } else {
        res[right_res--] = s[0][rig[0]--];
      }
    } else {
      if (lef[0] == s[0].length() || s[1][rig[1]] > s[0][lef[0]]) {
        res[lef_res++] = s[1][rig[1]--];
      } else {
        res[right_res--] = s[1][lef[1]++];
      }
    }
  }

  cout << res << endl;

}