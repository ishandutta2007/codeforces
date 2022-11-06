#include <bits/stdc++.h>

using namespace std;

const int N = 4005, S = 89;

int n;
int pref[N];
int dp[2][N][N][2];
int prefSumEven[N], prefSumOdd[N];

inline int sum(int from, int to) {
    return pref[to] - pref[from - 1];
}

inline bool goodInterval(int k, int i, int j) {
    return min(i - 1, n - j) >= min(prefSumEven[k], prefSumOdd[k]);
}

int main() {

    scanf("%d", &n);
    for (int i = 2; i <= 100; i++) {
        prefSumEven[i] = prefSumEven[i - 1] + (i % 2 == 0 ? i : 0);
        prefSumOdd[i] = prefSumOdd[i - 1] + (i % 2 == 1 ? i : 0);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pref[i]);
        pref[i] += pref[i - 1];
    }

    for (int k = S; k >= 1; k--) {
        int toI = min(prefSumOdd[k], prefSumEven[k]) + 1;
        for (int i = n; i >= toI; i--) {
            if (n - (i + k - 1) >= min(prefSumEven[k], prefSumOdd[k])) {
                dp[1][i][i + k - 1][0] = sum(i, i + k - 1);
                dp[1][i][i + k - 1][1] = -sum(i, i + k - 1);
            }
            int to = n - min(prefSumEven[k], prefSumOdd[k]);
            for (int j = i + k; j <= to; j++) {
                dp[1][i][j][0] = max(sum(i, i + k - 1) + dp[1][i + k][j][1],
                                     sum(i, i + k) + dp[0][i + k + 1][j][1]);
                dp[1][i][j][1] = min(-sum(j - k + 1, j) + dp[1][i][j - k][0],
                                     -sum(j - k, j) + dp[0][i][j - k - 1][0]);
            }
        }
        for (int i = n; i >= toI; i--) {
            if (n - (i + k - 1) >= min(prefSumEven[k], prefSumOdd[k])) {
                dp[0][i][i + k - 1][0] = sum(i, i + k - 1);
                dp[0][i][i + k - 1][1] = -sum(i, i + k - 1);
            }
            int to = n - min(prefSumEven[k], prefSumOdd[k]);
            for (int j = i + k; j <= to; j++) {
                dp[0][i][j][0] = dp[1][i][j][0];
                dp[0][i][j][1] = dp[1][i][j][1];
            }
        }
    }

    printf("%d\n", dp[0][1][n][0]);

    return 0;
}