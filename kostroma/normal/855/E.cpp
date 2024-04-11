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
  cin >> t;
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

#define int li
//const int mod = 1000000007;
const int C = 100;
int c[C][C];
void precalc() {
    for (int i = 0; i < C; ++i) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int dp[70][70];
int new_dp[70][70];

int get_res(int b, int L) {
    vector<int> now;
    while (L) {
        now.push_back(L % b);
        L /= b;
    }
    reverse(all(now));
    for (int i = 0; i <= now.size(); ++i) {
        for (int j = 0; j <= b; ++j) {
            dp[i][j] = new_dp[i][j] = 0;
        }
    }
    //vector<vector<int>> dp(now.size() + 1, vector<int>(b + 1, 0));
    dp[0][0] = 1;
    new_dp[0][0] = 1;
    //auto new_dp = dp;
    for (int pos = 0; pos < now.size(); ++pos) {
        for (int odd = 0; odd <= pos && odd <= b; ++odd) {
            //cout << pos << " " << odd << " " << dp[pos][odd] << endl;
            if (odd < b) {
                dp[pos + 1][odd + 1] += dp[pos][odd] * (b - odd);
                int coef = b - odd;
                if (pos == 0) {
                    --coef;
                }
                new_dp[pos + 1][odd + 1] += new_dp[pos][odd] * coef;
            }
            if (odd > 0) {
                dp[pos + 1][odd - 1] += dp[pos][odd] * odd;
                new_dp[pos + 1][odd - 1] += new_dp[pos][odd] * odd;
            }
        }
    }
    int res = 0;
    for (int len = 1; len < now.size(); ++len) {
        res += new_dp[len][0];
        //cout << len << " " << dp[len][0] << endl;
    }
    //cout << "res: " << res << endl;

    vector<int> num(b, 0);
    int odd = 0;
    for (int i = 0; i < now.size(); ++i) {
        for (int prev = 0; prev < now[i]; ++prev) {
            if (i == 0 && prev == 0) {
                continue;
            }
            int new_odd = odd;
            num[prev] ^= 1;
            if (num[prev] == 1) {
                ++new_odd;
            } else {
                --new_odd;
            }
            res += dp[(int)now.size() - 1 - i][new_odd] / c[b][new_odd];
            num[prev] ^= 1;
        }

        num[now[i]] ^= 1;
        if (num[now[i]] == 1) {
            ++odd;
        } else {
            --odd;
        }
    }
    return res;
}

void solve(bool read) {
    //read = false;
    int b, L, R;
    if (read) {
        cin >> b >> L >> R;
    } else {
        b = 2;
        L = 1000000000000000000LL;
        R = 1000000000000000000LL;
    }
    int ans = get_res(b, R + 1) - get_res(b, L);
    cout << ans << endl;

}