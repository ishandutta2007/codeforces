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

const int C = 100500;
int mod;
int phi;
int rem[C];
int rev_rem[C];
vector<int> primes, degs;
int n;

int get_deg(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

int getC(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = rem[n] * rev_rem[k] % mod * rev_rem[n - k] % mod;
    for (int i = 0; i < primes.size(); ++i) {
        int deg = get_deg(n, primes[i]) - get_deg(k, primes[i]) - get_deg(n - k, primes[i]);
        res = res * binpow(primes[i], deg, mod) % mod;
    }
    //cout << n << " " << k << " " << res << endl;
    return res;
}

int get_res(int l) {
    int res = 0;
    for (int par = 0; par < 2; ++par) {
        for (int cur = 0; 2 * cur + par <= n; ++cur) {
            int m = 2 * cur + par;
            int cur_l = l;
            if ((cur_l + par) % 2) {
                ++cur_l;
            }
            int now_c = (m + cur_l) / 2;
            res += getC(n, m) * getC(m, now_c);
            res %= mod;
        }
    }
    //cout << l << " " << res << endl;
    return res;
}

void solve(bool read) {
    int l, r;
    cin >> n >> mod >> l >> r;
    rem[0] = 1;
    int M = mod;
    phi = mod;
    for (int p = 2; p * p <= M; ++p) {
        if (M % p == 0) {
            phi = phi * (p - 1) / p;
            primes.push_back(p);
            degs.push_back(0);
            while (M % p == 0) {
                M /= p;
                ++degs.back();
            }
        }
    }
    if (M > 1) {
        phi = phi * (M - 1) / M;
        primes.push_back(M);
        degs.push_back(1);
    }

    for (int i = 1; i < C; ++i) {
        int cur = i;
        for (int p : primes) {
            while (cur % p == 0) {
                cur /= p;
            }
        }
        rem[i] = rem[i - 1] * cur % mod;
    }
    for (int i = 0; i < C; ++i) {
        rev_rem[i] = binpow(rem[i], phi - 1, mod);
    }

    int res = get_res(l) - get_res(r + 1);
    res %= mod;
    if (res < 0) {
        res += mod;
    }
    cout << res << endl;

}