#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    constexpr int N = 51;
    vector<bool> ok(4 * N * N);
    for (int i = 1; i * i < len(ok); i++) {
        ok[i * i] = true;
    }

    vector dp(N, vector<int>(N, N * N));
    dp[0][0] = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int px = 0; px <= x; px++) {
                for (int py = 0; py <= y; py++) {
                    if (ok[(x - px) * (x - px) + (y - py) * (y - py)]) {
                        dp[x][y] = min(dp[x][y], dp[px][py] + 1);
                    }
                }
            }
        }
    }

    int tests;
    cin >> tests;
    while (tests--) {
        int x, y;
        cin >> x >> y;
        cout << dp[x][y] << '\n';
    }
}