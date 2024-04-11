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

#define int li
const int mod = 1000000007;

const int C = 1000500;
int fact[C], revfact[C];

void solve(bool read) {
    fact[0] = 1;
    for (int i = 1; i < C; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    revfact[C - 1] = binpow(fact[C - 1], mod - 2,mod);
    for (int i = C - 2; i >= 0 ;--i) {
        revfact[i] = revfact[i + 1] * (i + 1) % mod;
    }
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << "0\n";
        return;
    }
    vector<int> dp(n + 1, 0);
    int cur_sum = 0;
    for (int i = 0; i <= k; ++i) {
        dp[i] = fact[i - 1];
        if (i) {
            cur_sum += dp[i] * revfact[i - 1];
            cur_sum %= mod;
        }
    }
    for (int i = k + 1; i <= n; ++i) {
        dp[i] = cur_sum * fact[i - 2] % mod;
        cur_sum -= dp[i - k] * revfact[i - k - 1];
        cur_sum += dp[i] * revfact[i - 1];
        cur_sum %= mod;
        if (cur_sum < 0) {
            cur_sum += mod;
        }
    }

    /*for (int i = 1; i <= n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";*/

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += dp[i] * fact[n - 1] % mod * revfact[i - 1] % mod;
        //cout << "add for " << i << " " << dp[i] * fact[n - 1] % mod * revfact[i - 1] % mod << endl;
        res %= mod;
    }

    res = fact[n] - res;
    res %= mod;
    if (res < 0) {
        res += mod;
    }
    cout << res << "\n";

}