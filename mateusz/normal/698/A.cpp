#include <bits/stdc++.h>

using namespace std;

const int N = 100005, INF = 1e9;

int n, x;
int dp[N][3];

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = INF;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if ((x & 1) == 1) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if ((x & 2) == 2) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
    }

    printf("%d\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));

    return 0;
}