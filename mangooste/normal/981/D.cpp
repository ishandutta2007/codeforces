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
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n), pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    ll ans = 0;
    for (int bit = 60; bit >= 0; bit--) {
        vector dp(n + 1, vector<bool>(k + 1));
        dp[0][0] = true;
        ans ^= 1ll << bit;
        for (int cnt = 1; cnt <= k; cnt++) {
            for (int pos = 1; pos <= n; pos++) {
                for (int prev_pos = 0; prev_pos < pos; prev_pos++) {
                    if (!dp[prev_pos][cnt - 1]) continue;
                    if (((pref[pos] - pref[prev_pos]) & ans) == ans) {
                        dp[pos][cnt] = true;
                        break;
                    }
                }
            }
        }
        if (!dp[n][k]) ans ^= 1ll << bit;
    }
    cout << ans << '\n';
}