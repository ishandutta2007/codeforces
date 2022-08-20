/*
    21.03.2019 19:21:27
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
const int mxm = 100005;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int mxm = 1e5 + 100;
#endif

long long mod = 1e9 + 7;

array< long long, mxm > inv;
vector< long long > primes;
long long m;

long long mpow(long long a, long long p, long long mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

long long get_inv(long long k) {
    if (inv[k] == -1) inv[k] = mpow(k, mod - 2, mod);
    return inv[k];
}

long long euler(long long k) {
    long long res = k;
    for (auto p : primes) {
        if (k % p == 0)
            res = res / p * (p - 1);
        while (k % p == 0)
            k /= p;
        if (k == 1)
            break;
    }
    return res;
}

long long calc(long long k, long long m) {
    if (k == 1) return m;
    show(k, m);
    vector< long long > fact;
    long long k1 = k;
    for (auto p : primes) {
        if (k % p == 0)
            fact.push_back(p);
        while (k % p == 0)
            k /= p;
        if (k == 1)
            break;
        if (p * p > k) {
            fact.push_back(k);
            break;
        }
    }
    int n = fact.size();
    int cnt = (1 << n);
    long long res = 0;
    for (int i = 0; i < cnt; ++i) {
        int sign = 1;
        long long p = m;
        int x = i;
        int ind = 0;
        while (x != 0) {
            if (x % 2 == 1) {
                p /= fact[ind];
                sign *= -1;
            }
            ++ind;
            x >>= 1;
        }
        res += p * sign;
    }
    show(res);
    return res;
}

int main() {
    auto tt = clock();
    primes.push_back(2);
    for (long long k = 3; k <= mxm; ++k) {
        bool is_prime = true;
        for (auto x : primes) {
            if (k % x == 0) {
                is_prime = false;
                break;
            }
            if (x * x > k) break;
        }
        if (is_prime)
            primes.push_back(k);
    }
    inv.fill(-1);
    // for (int i = 1; i < mxm; ++i) {
    //     inv[i] = mpow(i, mod - 2, mod);
    // }
    // inv[0] = 0;
    cin >> m;

    vector< long long > f(m + 1);
    f[1] = 0;
    for (int i = 2; i <= m; ++i) {
        f[i] = 0;
        for (int t = 1; t * t <= i; ++t) {
            if (i % t == 0) {
                f[i] += calc(i / t, m / t) * f[t] % mod;
                if (t * t != i && t != 1)
                    f[i] += calc(t, m / (i / t)) * f[i / t] % mod;
            }
        }
        f[i] = f[i] % mod + m;
        f[i] *= get_inv(m - m / i);
        f[i] %= mod;
    }
    long long sm = 0;
    for (int i = 1; i <= m; ++i) {
        sm += f[i];
    }
    sm = sm % mod * get_inv(m) % mod + 1;
    cout << sm % mod << '\n';

    long double time = (long double)(clock() - tt) / CLOCKS_PER_SEC;
    show(time);
    return 0;
}