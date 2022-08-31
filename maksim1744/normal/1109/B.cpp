/*
    16.03.2019 22:41:41
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

// int solve(string& s) {
//     if (s.size() <= 2)
//         return -1;
//     string half = s.substr(0, s.size() / 2);
//     if (half == string(half.size(), half[0]))
//         return -1;
//     int k = solve(half);
//     if ()
// }

long long mod = 1e9 + 7;
long long p = 61;

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
    string s;
    cin >> s;
    if (s.size() % 2 == 1) {
        s[s.size() / 2] = s[0];
    }
    if (s == string(s.size(), s[0])) {
        cout << "Impossible\n";
        return 0;
    }
    int n = s.size();
    vector< long long > dp(n + 1);
    vector< long long > dpi(n + 1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
        dp[i] = dp[i - 1] * p % mod;
    }
    dpi.back() = mpow(dp.back(), mod - 2, mod);
    for (int i = dpi.size() - 2; i >= 0; --i) {
        dpi[i] = dpi[i + 1] * p % mod;
    }
    vector< long long > h(n);
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; ++i) {
        h[i] = (h[i - 1] + (long long)(s[i] - 'a' + 1) * dp[i]) % mod;
    }
    vector< long long > hi(n);
    hi[n - 1] = s[n - 1] - 'a' + 1;
    for (int i = n - 2; i >= 0; --i) {
        hi[i] = (hi[i + 1] + (long long)(s[i] - 'a' + 1) * dp[n - i - 1]) % mod;
    }
    auto askh = [&](int l, int r)->long long {
        long long ans = h[r];
        if (l > 0) ans -= h[l - 1];
        ans *= dpi[l];
        return (ans % mod + mod) % mod;
    };
    auto askhi = [&](int l, int r)->long long {
        long long ans = hi[l];
        if (r + 1 < n) ans -= hi[r + 1];
        ans *= dpi[n - r - 1];
        return (ans % mod + mod) % mod;
    };
    show(h, hi);
    show(askh(0, 5));
    show(askh(6, 11));
    long long allh = askh(0, n - 1);
    for (int i = 1; i < n; ++i) {
        long long ah1 = askh(i, n - 1) + askh(0, i - 1) * dp[n - i] % mod;
        long long ahi1 = askhi(i, n - 1) * dp[i] % mod + askhi(0, i - 1);
        ah1 %= mod;
        ahi1 %= mod;
        if (ah1 == ahi1 && ah1 != allh) {
            show(ah1, ahi1, allh);
            show(i);
            cout << 1 << '\n';
            return 0;
        }
    }
    // vector< int > p2(n, 0);
    // for (int i = 0; i < n - 1; ++i) {
    //     int l = 0, r = 2 + min(i, n - 1 - i);
    //     while (r - l > 1) {
    //         int m = (l + r) / 2;
    //         if (askh(i - m + 1, i) == askhi(i + 1, i + m)) {
    //             l = m;
    //         } else {
    //             r = m;
    //         }
    //     }
    //     p2[i] = l;
    // }
    // vector< int > p1(n, 0);
    // for (int i = 1; i < n - 1; ++i) {
    //     int l = 0, r = 1 + min(i, n - i - 1);
    //     while (r - l > 1) {
    //         int m = (l + r) / 2;
    //         if (askh(i - m, i - 1) == askhi(i + 1, i + m))
    //             l = m;
    //         else
    //             r = m;
    //     }
    //     p1[i] = l;
    // }
    // show(p1, p2);
    // if (n % 2 == 0) {
    //     for (int i = 0; i < n; ++i) {
    //         int ln = n / 2 - (i + 1);
    //         if (p2[i] == i + 1 && p2[n - 1 - ln] == ln) {
    //             showt(1, i);
    //             cout << 1 << '\n';
    //             return 0;
    //         }
    //     }
    // } else {
    //     for (int i = 0; i < n; ++i) {
    //         int ln = n / 2 - (i + 1);
    //         if (p2[i] == i + 1 && p1[n - 1 - ln] == ln) {
    //             showt(2, i);
    //             cout << 1 << '\n';
    //             return 0;
    //         }
    //     }
    //     for (int i = 0; i < n - 1; ++i) {
    //         int ln1 = (n - i - 1);
    //         int ln2 = n / 2 - ln1;
    //         if (p2[i] == ln1 && p1[ln2] == ln2) {
    //             show(ln1, ln2);
    //             showt(3, i);
    //             cout << 1 << '\n';
    //             return 0;
    //         }
    //     }
    // }
    cout << 2 << '\n';
    return 0;
}