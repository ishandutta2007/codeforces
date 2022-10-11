#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> rev_G(n);
    for (int i = 0; i < n; i++) {
        rev_G[i].pb(i);
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        rev_G[u].pb(v);
    }
    vector<vector<int>> real_G(n);
    for (int i = 0; i < n; i++) {
        int mx = *max_element(all(rev_G[i]));
        real_G[mx].pb(i);
    }
    const ll N = 5002;
    vector<int> dp(N, -1);
    dp[k] = 0;
    for (int i = 0; i < n; i++) {
        vector<int> new_dp(N, -1), tmp_dp(N, -1);
        for (int last = a[i]; last < N; last++) {
            if (dp[last] != -1 && (tmp_dp[last + b[i]] == -1 && tmp_dp[last + b[i]] < dp[last])) {
                tmp_dp[last + b[i]] = dp[last];
            }
        }
        vector<int> vals;
        for (auto j : real_G[i]) {
            vals.pb(c[j]);
        }
        sort(all(vals));
        reverse(all(vals));
        for (int pref = 0, sm = 0; pref <= vals.size(); pref++) {
            for (int j = pref; j < N; j++) {
                if (tmp_dp[j] != -1 && (new_dp[j - pref] == -1 || new_dp[j - pref] < tmp_dp[j] + sm)) {
                    new_dp[j - pref] = tmp_dp[j] + sm;
                }
            }
            if (pref != vals.size()) {
                sm += vals[pref];
            }
        }
        swap(dp, new_dp);
    }
    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (dp[i] != -1 && (ans == -1 || ans < dp[i])) {
            ans = dp[i];
        }
    }
    cout << ans << '\n';
}