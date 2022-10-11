#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        G[v].eb(u, w);
        G[u].eb(v, w);
    }
    vector<array<ll, 2>> dp(n, {0, 0});

    function<void(int, int, int)> Dfs = [&](int v, int pr, int w_from) {
        vector<pair<ll, ll>> maybe;
        for (auto i : G[v]) {
            int u = i.first;
            int w = i.second;
            if (u != pr) {
                Dfs(u, v, w);
                maybe.eb(dp[u][1], dp[u][0]);
            }
        }
        sort(all(maybe), [&](pair<ll, ll> &a, pair<ll, ll> &b) {
            return a.first - a.second > b.first - b.second;
        });
        int sz = maybe.size();
        vector<ll> suf(sz + 1);
        suf[sz] = 0ll;
        for (int i = sz - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + maybe[i].second;
        }
        vector<ll> pref(sz + 1);
        pref[0] = 0ll;
        for (int i = 0; i < sz; i++) {
            pref[i + 1] = pref[i] + maybe[i].first;
        }
        for (int i = 0; i <= k && i <= sz; i++) {
            dp[v][0] = max(dp[v][0], pref[i] + suf[i]);
        }
        for (int i = 0; i <= k - 1 && i <= sz; i++) {
            dp[v][1] = max(dp[v][1], pref[i] + suf[i]);
        }
        dp[v][1] += w_from;
    };

    Dfs(0, 0, 0);
    cout << dp[0][0] << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}