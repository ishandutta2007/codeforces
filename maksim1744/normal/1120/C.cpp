/*
    14.03.2019 19:14:46
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

long long p = 131;
long long p1 = 31;
long long mod = 18014398241046527ll;
long long mod1 = 1e9 + 7;
int inf = 1e9;

// long long mpow(long long a, long long p, long long mod = mod) {
//     long long res = 1;
//     while (p) {
//         if (p & 1) res = res * a % mod;
//         p >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }

int main() {
    // vector< long long > pp(5005, 1);
    // for (int i = 1; i < pp.size(); ++i) {
    //     pp[i] = pp[i - 1] * p % mod;
    // }
    // long long mmd = 1000000000ll;
    // mmd *= mmd;
    // ++mmd;
    // while (true) {
    //     bool ok = true;
    //     for (int i = 2; i * i <= mmd; ++i) {
    //         if (mmd % i == 0) {
    //             ok = false;
    //             break;
    //         }
    //     }
    //     if (ok) {
    //         break;
    //     }
    //     mmd += 2;
    //     show(mmd);
    // }
    // cout << mod << '\n';
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    // s = " " + s;
    // unordered_map< long long, short > mp;
    // vector< int > dp(n + 1, inf);
    // dp[0] = 0;
    // for (int i = 1; i <= n; ++i) {
    //     dp[i] = dp[i - 1] + a;
    //     long long h = 0;
    //     long long h1 = 0;
    //     for (int j = 0; j < i; ++j) {
    //         h = (h * p + (s[i - j] - 'a' + 1)) % mod;
    //         // h1 = (h1 * p1 + (s[i - j] - 'a' + 1)) % mod1;
    //         // show(s[i-j]);
    //         // show(h);
    //         auto it = mp.find(h);
    //         // show(*it, i/, j);
    //         if (it != mp.end() && it->second <= i - j - 1) {
    //             dp[i] = min(dp[i], dp[i - j - 1] + b);
    //         }
    //         if (it == mp.end() && (j + 1) <= n / 2) {
    //             mp[h] = i;
    //         }
    //     }
    //     // show(mp);
    // }
    // // show(dp);
    // cout << dp[n] << '\n';
    vector< int > dp(n, inf);
    dp[0] = a;
    vector< vector< int > > sim(n);
    for (int i = 0; i < n; ++i) {
        sim[i].assign(i, 0);
        for (int j = 0; j < i; ++j) {
            if (s[j] == s[i]) {
                sim[i][j] = 1;
                if (i > 0 && j > 0)
                    sim[i][j] += sim[i - 1][j - 1];
            }
        }
    }
    show(sim);
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + a;
        for (int j = 0; j < i; ++j) {
            if (sim[i][j] != 0) {
                dp[i] = min(dp[i], dp[max(j, i - sim[i][j])] + b);
            }
        }
    }
    cout << dp.back() << '\n';
    return 0;
}