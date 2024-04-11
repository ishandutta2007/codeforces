#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector c(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> c[i][j];
        }
    }
    
    std::vector cost(n + 1, std::vector<i64>(n + 1));
    for (int l = 0; l < n; l++) {
        i64 v = 0;
        for (int r = l + 1; r <= n; r++) {
            for (int i = 0; i < n; i++) {
                if (i == r - 1) {
                    continue;
                }
                if (l <= i && i < r) {
                    v -= c[r - 1][i];
                } else {
                    v += c[r - 1][i];
                }
            }
            cost[l][r] = v;
        }
    }
    
    std::vector dp(n + 1, std::vector<i64>(n + 1, inf));
    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 0; l--) {
            for (int i = l; i < r; i++) {
                dp[l][r] = std::min(dp[l][r], dp[l][i] + dp[i + 1][r]);
            }
            dp[l][r] += cost[l][r];
        }
    }
    
    std::vector<int> ans(n);
    auto rec = [&](auto rec, int l, int r, int x) {
        if (l == r) {
            return;
        }
        for (int i = l; i < r; i++) {
            if (dp[l][r] == dp[l][i] + dp[i + 1][r] + cost[l][r]) {
                ans[i] = x;
                rec(rec, l, i, i + 1);
                rec(rec, i + 1, r, i + 1);
                return;
            }
        }
    };
    rec(rec, 0, n, 0);
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}