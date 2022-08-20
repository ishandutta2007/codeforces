/*
    17.03.2019 1:38:57
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

long long mod = 1e9 + 7;
int mx = 1000010;

long long mpow(long long a, long long p, long long mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    long long n, m;
    cin >> n >> m;
    // after 2 hours I came to this:
    // answer = sum{s=1..n} C(m-1, s-1) * m**(n-s-1) * (s-1)! * (s+1) * n**(n-s-2) * C(n-2, s-1)
    // C(m-1, s-1)          for number of ways to represent m as s variables in [1..m]
    // m**(n-s-1)           for coloring other edges
    // (s-1)!               for permutations of (s-1) vertices on the path
    // (s+1) * n**(n-s-2)   for number of trees (it took a lot of time of guessing, I don't now why it's true)
    // C(n-2, s-1)          for picking (s-1) vertices for path
    vector< long long > f(mx); f[0] = 1;
    vector< long long > fi(mx);
    for (int i = 1; i < mx; ++i)
        f[i] = f[i - 1] * i % mod;
    fi.back() = mpow(f.back(), mod - 2, mod);
    for (int i = fi.size() - 2; i >= 0; --i)
        fi[i] = fi[i + 1] * (i + 1) % mod;
    auto c = [&](int n, int k) -> long long {
        if (k < 0 || k > n) return 0;
        return f[n] * fi[k] % mod * fi[n - k] % mod;
    };
    vector< long long > np(mx, 1), mp(mx, 1);
    for (int i = 1; i < mx; ++i) {
        np[i] = np[i - 1] * n % mod;
        mp[i] = mp[i - 1] * m % mod;
    }
    long long ans = 0;
    for (long long s = 1; s < n - 1; ++s) {
        ans += c(m-1,s-1) * mp[n-s-1] % mod * f[s-1] % mod * (s+1) % mod * np[n-s-2] % mod * c(n-2,s-1) % mod;
    }
    if (m - n + 1 >= 0)
        ans += f[m-1] * fi[m-n+1] % mod;
    cout << ans % mod << '\n';
    return 0;
}