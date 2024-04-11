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

void solve(int test_num) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    constexpr int INF = 1e9;
    vector dp_pref(n + 1, vector<int>(m + 1, -INF));
    for (int pos = 0; pos <= n; pos++) {
        dp_pref[pos][0] = pos;
        if (!pos) continue;
        for (int ln = 1; ln <= m; ln++) {
            if (s[pos - 1] == t[ln - 1] && dp_pref[pos - 1][ln - 1] != -INF) {
                dp_pref[pos][ln] = dp_pref[pos - 1][ln - 1];
            } else if (dp_pref[pos - 1][ln] != -INF) {
                dp_pref[pos][ln] = pos;
            }
        }
        dbg(pos, dp_pref[pos]);
    }

    vector dp_suf(n + 1, vector<bool>(m + 1));
    for (int pos = n; pos >= 0; pos--) {
        dp_suf[pos][m] = true;
        if (pos == n) continue;
        for (int ln = m - 1; ln >= 0; ln--) {
            dp_suf[pos][ln] = dp_suf[pos + 1][ln];
            if (s[pos] == t[ln] && dp_suf[pos + 1][ln + 1]) {
                dp_suf[pos][ln] = true;
            }
        }
    }

    int ans = INF;
    for (int cut = 0; cut <= n; cut++) {
        for (int left = 0; left <= m; left++) {
            if (dp_pref[cut][left] == -INF) continue;
            if (!dp_suf[cut][left]) continue;

            int cost = 0;
            if (cut) {
                int new_length = left - (cut - dp_pref[cut][left]);
                cost += dp_pref[cut][left] != 0;
                cost += 2 * dp_pref[cut][left] - new_length;
            }
            cost += n - cut;
            ans = min(ans, cost);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}