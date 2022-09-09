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

//#define int li
//const int mod = 1000000007;

void solve(bool read) {
  const int INF = 1000000000;
  string s, p;
  cin >> s >> p;
  vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, INF));
  dp[0][0] = 0;
  for (int pos = 0; pos < s.length(); ++pos) {
    for (int len = 0; len <= pos; ++len) {
      if (dp[pos][len] < 0) {
        continue;
      }
      if (len % p.length() == 0) {
        relax_min(dp[pos + 1][len], dp[pos][len]);
      }
      relax_min(dp[pos + 1][len], dp[pos][len] + 1);
      char new_symbol = p[len % p.length()];
      if (s[pos] == new_symbol) {
        relax_min(dp[pos + 1][len + 1], dp[pos][len]);
      }
    }
  }

  /*for (int len = 0; len <= s.length(); ++len) {
    cout << dp.back()[len] << " ";
  }
  cout << endl;*/

  vector<int> res(s.length() + 1, 0);
  for (int len = 0; len <= s.length(); ++len) {
    int to_erase = dp.back()[len];
    int steps = len / (int)p.length();
    for (int i = to_erase; i <= s.length(); ++i) {
      int rest = (int)s.length() - i;
      steps = min(steps, rest / (int)p.length());
      relax_max(res[i], steps);
    }
  }

  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;

}