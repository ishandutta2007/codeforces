#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 2050;
static constexpr int inf = 2e9;

long long dp[maxn][maxn];
int a[maxn];

int main() {
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            dp[i][j] = -1LL * inf * inf;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (a[i] + dp[i][j] >= 0) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], a[i] + dp[i][j]);
            }
        }
    }
    for (int i = n; i >= 0; --i) {
        if (dp[n][i] >= 0) {
            return cout << i << endl, 0;
        }
    }
}