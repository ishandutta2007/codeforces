#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename A, typename B>
bool setmin(A &a, const B &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n;
    array<string, 2> a;
    cin >> n >> a[0] >> a[1];
    while (a[0][n - 1] == '.' && a[1][n - 1] == '.') {
        n--;
    }

    const int INF = 100 * n + 228;
    array<int, 3> dp;
    dp.fill(INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        array<int, 3> new_dp;
        new_dp.fill(INF);

        int cur_mask = 0;
        for (int j : {0, 1}) {
            if (a[j][i] == '*') cur_mask ^= 1 << j;
        }

        if (cur_mask == 0) {
            for (int j : {0, 1, 2}) {
                setmin(new_dp[j], dp[j] + (j != 0));
            }
        } else if (cur_mask == 3) {
            for (int j : {0, 1}) {
                setmin(new_dp[1 << j], dp[0] + 1);
                setmin(new_dp[1 << j], min(dp[1], dp[2]) + 2);
            }
        } else {
            int who = cur_mask % 2 ? 0 : 1;
            assert(cur_mask >> who & 1);

            setmin(new_dp[1 << who], dp[0]);
            setmin(new_dp[1 << who], dp[1 << who] + 1);
            setmin(new_dp[1 << who], dp[1 << (who ^ 1)] + 2);

            setmin(new_dp[1 << (who ^ 1)], dp[0] + 1);
            setmin(new_dp[1 << (who ^ 1)], min(dp[1], dp[2]) + 2);
        }

        swap(dp, new_dp);
    }
    cout << min(dp[1], dp[2]) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}