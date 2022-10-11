#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
#endif // LOCAL

template<typename A, typename B>
bool setmin(A &a, const B &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename A, typename B>
bool setmax(A &a, const B &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void solve(int test_num) {
    int n, x, y;
    string s, t;
    cin >> n >> x >> y >> s >> t;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') s[i] ^= '0' ^ '1';
    }

    if (count(all(s), '1') % 2) {
        cout << "-1\n";
        return;
    }

    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ones.push_back(i);
    }
    if (len(ones) == 2 && ones[0] + 1 == ones[1]) {
        cout << min(x, 2 * y) << '\n';
        return;
    }

    if (x >= y) {
        ll ans = 0;
        for (int i = 0; i < len(ones) / 2; i++) {
            int f = ones[i], s = ones[i + len(ones) / 2];
            ans += s == f + 1 ? x : y;
        }
        cout << ans << '\n';
        return;
    }

    x *= 2;
    const int m = len(ones);
    vector<ll> dp(m + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        setmin(dp[i + 1], dp[i] + y);
        if (i) setmin(dp[i + 1], dp[i - 1] + 1ll * (ones[i] - ones[i - 1]) * x);
    }
    cout << dp[m] / 2 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}