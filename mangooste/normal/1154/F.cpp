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
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    sort(all(a));
    while (a.size() != k) {
        a.pop_back();
    }
    reverse(all(a));
    vector<int> maybe(k + 1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= k) {
            maybe[x] = max(maybe[x], y);
        }
    }
    vector<pii> real;
    for (int i = 1; i <= k; i++) {
        if (maybe[i] != -1) {
            real.eb(i, maybe[i]);
        }
    }
    m = real.size();
    const ll INF = 1e16;
    vector<ll> dp(k + 1, INF);
    dp[0] = 0ll;
    vector<ll> pref(k + 1, 0ll);
    for (int i = 0; i < k; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i - 1] + a[i - 1];
        for (int j = 0; j < m; j++) {
            int x = real[j].first, y = real[j].second;
            if (i - x >= 0) {
                ll cur_ans = 0;
                cur_ans += dp[i - x];
                cur_ans += pref[i - y] - pref[i - x];
                dp[i] = min(dp[i], cur_ans);
            }
        }
    }
    cout << dp[k] << '\n';
}