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
//const int mod = 1000000007;

int get_min(vector<int>& x, int a, int b) {
    int res = (int)1e18;
    for (int i = 0; i <= x.size(); ++i) {
        int cur_ans = 0;
        if (i) {
            cur_ans += (x[i - 1] - a);
        }
        if (i < x.size()) {
            cur_ans += (b - x[i]);
        }
        relax_min(res, cur_ans);
    }
    return res;
}

void solve(bool read) {
    int n;
    cin >> n;
    int last_green = 0;
    vector<int> reds, blues;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        char col;
        cin >> col;
        if (col == 'R') {
            reds.push_back(x);
        } else if (col == 'B') {
            blues.push_back(x);
        } else {
            if (last_green == 0) {
                if (!reds.empty()) {
                    ans += x - reds[0];
                }
                if (!blues.empty()) {
                    ans += x - blues[0];
                }
            } else {
                int dist = x - last_green;
                int sum_dist = get_min(reds, last_green, x) + get_min(blues, last_green, x);
                ans += dist + min(dist, sum_dist);
            }
            last_green = x;
            reds.clear();
            blues.clear();
        }
    }
    if (last_green == 0) {
        if (!reds.empty()) {
            ans += reds.back() - reds[0];
        }
        if (!blues.empty()) {
            ans += blues.back() - blues[0];
        }
    } else {
        if (!reds.empty()) {
            ans += reds.back() - last_green;
        }
        if (!blues.empty()) {
            ans += blues.back() - last_green;
        }
    }
    cout << ans << endl;
}