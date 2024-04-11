#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    char a[n + 1];
    for (int i = 1; i<=n; i++) cin >> a[i];

    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j<101; j++) {
            if (i & 1) dp[i][j] = dp[i - 1][j] + 1;
            else {
                if (j) {
                    bool flag = false;
                    for (int k = 1; k<=i/2; k++) {
                        if (a[k] != a[k + i/2]) {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag) dp[i][j] = min(dp[i - 1][j] + 1, dp[i >> 1][j - 1] + 1);
                    else dp[i][j] = dp[i - 1][j] + 1;
                }
                else dp[i][j] = dp[i - 1][j] + 1;
            }
        }
    }
    cout << dp[n][1];
    return 0;
}