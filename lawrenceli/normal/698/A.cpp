#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n, a[maxn], dp[maxn][3];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int k = 0; k < 3; k++)
            dp[i][k] = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 3; j++)
            if (j == 2 || (a[i] & 1<<j))
                for (int k = 0; k < 3; k++)
                    if (k == 2 || k != j)
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + (j == 2));
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}