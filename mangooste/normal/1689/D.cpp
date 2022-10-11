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
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    auto get = [&](int mask, int x, int y) {
        return (mask % 2 ? 1 : -1) * x + (mask / 2 ? 1 : -1) * y;
    };

    constexpr int INF = 1e9;
    array<int, 4> mx;
    mx.fill(-INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 'B') continue;
            for (int mask = 0; mask < 4; mask++) {
                mx[mask] = max(mx[mask], get(mask, i, j));
            }
        }
    }

    int ans_x = -1, ans_y = -1, ans = INF;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            int cur = -INF;
            for (int mask = 0; mask < 4; mask++) {
                cur = max(cur, mx[mask] - get(mask, x, y));
            }
            if (ans > cur) {
                ans_x = x;
                ans_y = y;
                ans = cur;
            }
        }
    }

    assert(ans_x != -1);
    cout << ans_x + 1 << ' ' << ans_y + 1 << '\n';
    dbg(ans);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}