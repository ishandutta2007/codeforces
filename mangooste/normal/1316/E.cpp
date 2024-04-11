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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    vector<vector<int>> s(n, vector<int>(p));
    for (auto &i : s) {
        for (auto &el : i) {
            cin >> el;
        }
    }
    vector<int> els(n);
    iota(els.begin(), els.end(), 0);
    sort(els.begin(), els.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    int MASK = (1 << p);
    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(MASK, -INF));
    dp[0][0] = 0ll;
    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < MASK; mask++) {
            dp[i][mask] = dp[i - 1][mask];
        }
        int num = els[i - 1];
        for (int mask = 0; mask < MASK; mask++) {
            int allready = __builtin_popcount(mask);
            int choosen = i - 1 - allready;
            if (0 <= choosen && choosen < k) {
                ll cur_cost = a[num];
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + cur_cost);
            }
        }
        for (int where = 0; where < p; where++) {
            for (int mask = 0; mask < MASK; mask++) {
                if (mask & (1 << where)) {
                    int pmask = mask - (1 << where);
                    ll cur_cost = s[num][where];
                    if (dp[i - 1][pmask] != -INF) {
                        dp[i][mask] = max(dp[i][mask], dp[i - 1][pmask] + cur_cost);
                    }
                }
            }
        }
    }
    cout << dp[n][MASK - 1] << '\n';
}