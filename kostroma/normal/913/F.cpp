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

#define int li
//const int mod = 1000000007;

const int mod = 998244353;

const int C = 2010;

int dp_cut[C][C];

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

void solve(bool read) {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  int p = a * binpow(b, mod - 2, mod) % mod;
  vector<int> id_powers(C + 1, 1);
  auto minus_powers = id_powers;
  for (int i = 1; i < id_powers.size(); ++i) {
    id_powers[i] = id_powers[i - 1] * p % mod;
    minus_powers[i] = minus_powers[i - 1] * (1 + mod - p) % mod;
  }
  dp_cut[0][0] = 1;
  for (int pref = 0; pref + 1 < C; ++pref) {
    for (int taken = 0; taken <= pref; ++taken) {

      /*if (pref <= n) {
        cout << pref << " " << taken << " " << dp_cut[pref][taken] << endl;
      }*/

      add(dp_cut[pref + 1][taken], dp_cut[pref][taken] * id_powers[taken]);
      add(dp_cut[pref + 1][taken + 1], dp_cut[pref][taken] * minus_powers[pref - taken]);
    }
  }
  vector<int> dp(n + 1, 1);
  for (int i = 1; i < dp.size(); ++i) {
    for (int m = 1; m < i; ++m) {
      //cout << i << " " << m << " " << (dp[m] * dp_cut[i][m]) % mod << endl;
      add(dp[i], mod - (dp[m] * dp_cut[i][m]) % mod);
    }
    //cout << i << " " << dp[i] << endl;
  }
  vector<int> res(n + 1, 0);
  for (int i = 2; i < res.size(); ++i) {
    int to_div = 1;
    if (dp[i] > 0) {
      to_div = binpow(1 + mod - dp[i], mod - 2, mod);
      res[i] += dp[i] * to_div % mod * (i * (i - 1) / 2 % mod);
      res[i] %= mod;
      //cout << "init " << i << " " << res[i] << endl;
    }
    for (int m = 1; m < i; ++m) {
      //cout << dp_cut[i][m] << endl;
      int cur_add = to_div * dp_cut[i][m] % mod * dp[m] % mod * (res[m] + res[i - m] + m * (m - 1) / 2 % mod + m * (i - m) % mod) % mod;
      add(res[i], cur_add);
    }
    //cout << "res " << i << " " << res[i] << endl;
  }

  cout << res[n] << endl;

}