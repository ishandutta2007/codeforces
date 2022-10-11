#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(all(a));

    int sz = *max_element(all(a)) / (k - 1) + 2;
    vec<int> dp1(sz);
    vec<vec<int>> pref(n + 1, vec<int>(k + 1));
    vec<vec<int>> dp(n + 1, vec<int>(k + 1));
    a.insert(a.begin(), 0);

    for (int delta = 0; delta < sz; delta++) {
        dp[0][0] = 1;
        pref[0][0] = 1;
        int prev = 1;
        for (int i = 1; i <= n; i++) {
            while (prev < i && a[i] - a[prev] >= delta)
                prev++;
            for (int j = 0; j <= k; j++) {
                if (j)
                    dp[i][j] = pref[prev - 1][j - 1];
                pref[i][j] = pref[i - 1][j] + dp[i][j];
                if (pref[i][j] >= mod)
                    pref[i][j] -= mod;
            }
            dp1[delta] += dp[i][k];
            if (dp1[delta] >= mod)
                dp1[delta] -= mod;
        }
    }

    int ans = dp1[sz - 1];
    for (int i = sz - 2; i >= 0; i--) {
        int cur = dp1[i] - dp1[i + 1];
        if (cur < 0)
            cur += mod;
        ans += 1ll * cur * i % mod;
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
}