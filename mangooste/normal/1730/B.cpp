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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    for (auto &[x, y] : a) x *= 2, y *= 2;

    auto solve = [&](int value) -> pair<int, int> {
        int max_l = -2e9, min_r = 2e9;
        for (auto &[x, t] : a) {
            max_l = max(max_l, x - value + t);
            min_r = min(min_r, x + value - t);
        }
        return {max_l, min_r};
    };

    int l = -1, r = 1e9;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        auto [valid_l, valid_r] = solve(mid);
        (valid_l <= valid_r ? r : l) = mid;
    }

    int ans = solve(r).first;
    cout << ans / 2 << "." << 5 * (ans % 2) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}