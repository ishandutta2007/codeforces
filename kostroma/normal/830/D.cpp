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

#define int li
const int mod = 1000000007;

void add(int& cur, int val) {
  cur += val;
  //cur %= mod;
}

const int C = 450;
int c[C][C];

void solve(bool read) {
  for (int i = 0; i < C; ++i) {
    c[i][i] = c[i][0] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  int k;
  cin >> k;
  --k;
  vector<vector<int>> dp(k + 1, vector<int>(k + 2, 0));
  int rev2 = binpow(2LL, mod - 2, mod);
  dp[0][0] = 1;
  dp[0][1] = rev2;
  int all_step = 1;

  //cout << (3 * rev2 + 6) % mod << endl;
  for (int n = 1; n <= k; ++n) {
    all_step = (all_step * 2 + 1) % mod;
    for (int m = 0; m < dp[n - 1].size(); ++m) {
      for (int l = 0; l < dp[n - 1].size(); ++l) {
        if (m + l > dp[n].size() + 5) {
          break;
        }
        //cout << m << " " << l << " " << dp[n - 1][m] << " " << dp[n - 1][l] << endl;
        int prod = dp[n - 1][m] * dp[n - 1][l] % mod;
        if (m + l + 1 < dp[n].size()) {
          add(dp[n][m + l + 1], prod * rev2 % mod);
        }
        if (m + l < dp[n].size()) {
          add(dp[n][m + l], prod);
        }
        if (m && l && m + l - 1 < dp[n].size()) {
          add(dp[n][m + l - 1], prod * 2 * 2 * m * l);
          //cout << n << " " << m << " " << l << " " << dp[n][m + l - 1] << " " << dp[n - 1][m] * 2 * dp[n - 1][l] * 2 % mod << endl;
        }
        if (m && m + l < dp[n].size()) {
          add(dp[n][m + l], prod * 2 * m);
        }
        if (l && m + l < dp[n].size()) {
          add(dp[n][m + l], prod * 2 * l);
        }
        if (m >= 2 && m + l - 1 < dp[n].size()) {
          add(dp[n][m + l - 1], prod * c[m][2] * 4);
        }
        if (l >= 2 && m + l - 1 < dp[n].size()) {
          add(dp[n][m + l - 1], prod * c[l][2] * 4);
        }
        //cout << m << " " << l << " " << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;
      }
    }
    for (int m = 0; m < dp[n].size(); ++m) {
      dp[n][m] %= mod;
    }
  }

  int ans = (dp[k][1] - rev2 * all_step) % mod * 2 + all_step;
  ans %= mod;
  if (ans < 0) {
    ans += mod;
  }
  cout << ans << endl;

}