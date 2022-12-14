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
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
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

void solve(bool read) {
    int n, d, b;
    cin >> n >> d >> b;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int L = -1, R = (n + 1) / 2;
    while (L + 1 < R) {
        auto cur_a = a;
        int M = (L + R) / 2;
        int left_sum = 0, rig_sum = 0;
        int lef_need = 0, rig_need = n - 1;
        int lef_uk = M, rig_uk = n - 1 - M;
        int steps = M;
        bool flag = true;
        while (lef_uk < rig_uk) {
            ++steps;
            while (lef_need <= lef_uk + steps * d && left_sum < b) {
                int cur_add = min(cur_a[lef_need], b - left_sum);
                cur_a[lef_need] -= cur_add;
                left_sum += cur_add;
                if (cur_a[lef_need] == 0) {
                    ++lef_need;
                }
            }
            while (rig_need >= rig_uk - steps * d && rig_sum < b) {
                int cur_add = min(cur_a[rig_need], b - rig_sum);
                cur_a[rig_need] -= cur_add;
                rig_sum += cur_add;
                if (cur_a[rig_need] == 0) {
                    --rig_need;
                }
            }
            if (left_sum < b || rig_sum < b) {
                flag = false;
                break;
            }
            left_sum -= b;
            rig_sum -= b;
            ++lef_uk;
            --rig_uk;
        }
        if (flag) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << R << "\n";

}