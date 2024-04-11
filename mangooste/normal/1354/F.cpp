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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -INF));
    vector<vector<int>> parent(n + 1, vector<int>(k + 1, -1));
    vector<int> els(n);
    iota(els.begin(), els.end(), 0);
    sort(els.begin(), els.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    dp[0][0] = 0ll;
    for (int i = 1; i <= n; i++) {
        int cur_num = els[i - 1];
        for (int cnt = 1; cnt <= k; cnt++) {
            if (dp[i - 1][cnt - 1] == -INF) {
                continue;
            }
            ll cur_cost = a[cur_num] + 1ll * (cnt - 1) * b[cur_num];
            if (dp[i][cnt] < dp[i - 1][cnt - 1] + cur_cost) {
                dp[i][cnt] = dp[i - 1][cnt - 1] + cur_cost;
                parent[i][cnt] = cnt - 1;
            }
        }
        for (int cnt = 0; cnt <= k; cnt++) {
            if (dp[i - 1][cnt] == -INF) {
                continue;
            }
            ll cur_cost = (k - 1) * b[cur_num];
            if (dp[i][cnt] < dp[i - 1][cnt] + cur_cost) {
                dp[i][cnt] = dp[i - 1][cnt] + cur_cost;
                parent[i][cnt] = cnt;
            }
        }
    }
    // cout << dp[n][k] << '\n';
    vector<int> first_type, second_type;
    for (int i = n, how_many = k; i > 0; i--) {
        assert(parent[i][how_many] != -1);
        if (parent[i][how_many] == how_many) {
            second_type.push_back(els[i - 1]);
        } else {
            first_type.push_back(els[i - 1]);
            how_many--;
        }
    }
    reverse(first_type.begin(), first_type.end());
    cout << n + (n - k) << '\n';
    for (int i = 0; i < k - 1; i++) {
        cout << first_type[i] + 1 << ' ';
    }
    for (int i = 0; i < n - k; i++) {
        cout << second_type[i] + 1 << " -" << second_type[i] + 1 << ' ';
    }
    cout << first_type.back() + 1 << '\n';
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