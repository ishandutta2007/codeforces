/*
    20.12.2018 15:45:56
*/

#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    } else if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1, d;
    if (a > b) {
        d = gcd(a % b, b, x1, y1);
        x = x1;
        y = y1 - x1 * (a / b);
    } else {
        d = gcd(a, b % a, x1, y1);
        y = y1;
        x = x1 - y1 * (b / a);
    }
    x = x % mod;
    y = y % mod;
    if (x < 0) {
        x += mod;
    }
    if (y < 0) {
        y += mod;
    }
    return d;
}

long long inv(long long k) {
    long long x, y;
    gcd(k, mod, x, y);
    return x;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    long long mul = m;
    for (int i = 0; i < k; ++i) {
        mul = mul * (m - 1) % mod;
    }
    long long num = 1, den = 1;
    for (int i = 0; i < k; ++i) {
        den = den * (long long)(i + 1) % mod;
    }
    for (int i = 0; i < k; ++i) {
        num = num * (long long)(i + n - k) % mod;
    }
    // cout << den << ' ' << inv(den) << ' ' << den * inv(den) % mod << '\n';
    cout << num * inv(den) % mod * mul % mod << '\n';
    return 0;
}