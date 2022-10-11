#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, k, a[N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int pt = 1, i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        while (a[i] - a[pt] > 5) {
            pt++;
        }
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i][j], dp[pt - 1][j - 1] + i - pt + 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][k] << '\n';
}