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

const int C = 1010;
int c[C][C];

void solve(bool read) {
    for (int i = 0; i < C; ++i) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    vector<vector<int>> powers(11, vector<int>(C, 1));
    auto super_powers = powers;
    auto one_powers = powers;
    for (int j = 0; j < powers.size(); ++j) {
        for (int i = 1; i < powers[j].size(); ++i) {
            powers[j][i] = powers[j][i - 1] * j % mod;
            if (j > 0) {
                super_powers[j][i] = super_powers[j][i - 1] * (1 + 10 * binpow(j, mod - 2, mod)) % mod;
                one_powers[j][i] = one_powers[j][i - 1] * (1 + binpow(j, mod - 2, mod)) % mod;
            }
        }
    }
    //read = false;
    string s;
    if (read) {
        cin >> s;
    } else {
        for (int i = 0; i < 700; ++i) {
            s += (char)('0' + rand() % 10);
        }
    }
    int n = (int)s.length();
    bool finished = false;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '9') {
            s[i] = '0';
            continue;
        } else {
            ++s[i];
            finished = true;
            break;
        }
    }
    if (!finished) {
        s.insert(s.begin(), '0');
    }
    n = (int)s.length();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    vector<int> init(10);
    int rev9 = binpow(9LL, mod - 2, mod);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int free_positions = n - i - 1;
        init.assign(10, 0);
        for (int j = 0; j < i; ++j) {
            ++init[a[j]];
        }
        for (int cur_val = 0; cur_val < a[i]; ++cur_val) {
            ++init[cur_val];
            int pref_init = 0;
            for (int dig = 9; dig > 0; --dig) {
                for (int pref = 0; pref <= free_positions; ++pref) {
                    int len = free_positions - pref;
                    int common = powers[10][pref_init + pref] * c[free_positions][pref] % mod * dig % mod *
                                 powers[9 - dig][pref] % mod;
                    int init_multiplier = common * powers[dig + 1][len] % mod;
                    int add = (powers[10][init[dig]] - 1) * rev9 % mod * init_multiplier % mod;
                    ans += add;
                    int multiplier = common * powers[10][init[dig]] % mod * powers[dig][len] % mod * rev9 % mod;
                    ans -= multiplier * one_powers[dig][len] % mod;
                    ans += multiplier * super_powers[dig][len] % mod;
                    ans %= mod;
                    if (ans < 0) {
                        ans += mod;
                    }
                }
                pref_init += init[dig];
            }
            --init[cur_val];
        }
    }

    cout << ans << endl;

}