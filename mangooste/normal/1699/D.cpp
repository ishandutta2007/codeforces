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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    int ans = 0;
    for (int val = 0; val < n; val++) {
        vector<int> pos;
        pos.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (a[i] == val) pos.push_back(i);
        }
        pos.push_back(n);

        vector<int> dp(len(pos), -1e9);
        dp[0] = 0;
        for (int i = 1; i < len(pos); i++) {
            vector<int> tot(n);
            int cur_max = 0, cur_pos = pos[i] - 1;
            for (int j = i - 1; j >= 0; j--) {
                for (; cur_pos > pos[j]; cur_pos--) {
                    cur_max = max(cur_max, ++tot[a[cur_pos]]);
                }
                if (cur_max * 2 < pos[i] - pos[j] && (pos[i] - pos[j] - 1) % 2 == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        ans = max(ans, dp.back() - 1);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}