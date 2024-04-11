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

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int, int> mp;
    mp[0] = 0;

    vector<int> dp(n);
    int pref_xor = 0;
    for (int i = 0; i < n; i++) {
        pref_xor ^= a[i];
        if (mp.count(pref_xor)) {
            dp[i] = mp[pref_xor] + 1;
        }
        if (i) dp[i] = max(dp[i], dp[i - 1]);
        mp[pref_xor] = max(mp[pref_xor], dp[i]);
    }
    cout << n - dp[n - 1] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}