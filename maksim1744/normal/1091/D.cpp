/*
    25.03.2019 22:03:42
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
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const long long mod = 998244353;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long sm = 1;
    long long f = 1;
    for (int i = 2; i <= n; ++i)
        f = f * i % mod;
    long long fi = mpow(f, mod - 2);
    for (long long i = n - 1; i >= 1; --i) {
        sm = (sm + f * fi % mod * i % mod * (n - i) % mod) % mod;
        show(sm);
        fi = fi * (i + 1) % mod;
    }
    cout << sm << '\n';
    return 0;
}