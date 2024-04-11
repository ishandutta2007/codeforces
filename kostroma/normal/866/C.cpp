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

double dp[55][5050];

void solve(bool read) {
    //read = false;
    int n, need;
    if (read) {
        cin >> n >> need;
    } else {
        n = 50;
        need = 150 * n;
    }
    vector<int> f(n), s(n);
    vector<double> p(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> f[i] >> s[i];
        } else {
            f[i] = 100;
            s[i] = 200;
        }
        sum += s[i];
        if (read) {
            cin >> p[i];
        } else {
            p[i] = 80;
        }
        p[i] /= 100.;
    }

    double L = 0, R = 1e10;
    while (R - L > 1e-11) {
        double x = (L + R) / 2;
        //vector<vector<double>> dp(n + 1, vector<double>(sum + 1, x));
        for (int i = 0; i <= sum; ++i) {
            dp[n][i] = ((i <= need) ? 0 : x);
        }
        int max_sum = sum;
        for (int i = n - 1; i >= 0; --i) {
            max_sum -= s[i];
            for (int time = 0; time <= max_sum; ++time) {
                double val = p[i] * (f[i] + dp[i + 1][time + f[i]]) + (1 - p[i]) * (s[i] + dp[i + 1][time + s[i]]);
                if (i > 0) {
                    val = min(val, x);
                }
                dp[i][time] = val;
            }
        }
        if (dp[0][0] > x) {
            L = x;
        } else {
            R = x;
        }
    }

    cout << R << endl;

}