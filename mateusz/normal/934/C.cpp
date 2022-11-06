#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int dp[N][5];

int main() {
    
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][2] = dp[i - 1][2];
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]) + 1;
            dp[i][4] = dp[i - 1][4];
        } else {
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
            dp[i][3] = dp[i - 1][3];
            dp[i][4] = max(dp[i - 1][3], dp[i - 1][4]) + 1;
        }
    }
    
    printf("%d\n", max(max(dp[n][1], dp[n][2]), max(dp[n][3], dp[n][4])));
    
    return 0;
}