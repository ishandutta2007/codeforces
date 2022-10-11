#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5, LG = 21, MOD = 1E9 + 7;

int r, u, q, di[N], dp[N][LG];

void init() {
    for (int i = 2; i < N; i++) {
        if (di[i] == 0) {
            for (int j = i; j < N; j += i) {
                di[j] = i;
            }
        }
    }
    dp[0][0] = 1;
    fill(dp[0] + 1, dp[0] + LG, 2);
    for (int i = 1; i < N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < LG; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> q;
    while (q--) {
        cin >> r >> u;
        long long ans = 1;
        while (u > 1) {
            int d = di[u], lg = 0;
            while (u % d == 0) {
                lg++;
                u /= d;
            }
            (ans *= dp[r][lg]) %= MOD;
        }
        cout << ans << '\n';
    }
}