#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 100;
typedef long long ll;
const int maxN = 5010;
int dp[maxN][maxN / 2][2][2];
int a[maxN];
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -(int)1e9;
    a[n + 1] = -(int)1e9;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (n + 1) / 2; j++) {
            for (int ok = 0; ok < 2; ok++) {
                dp[i][j][ok][0] = INF;
                dp[i][j][ok][1] = INF;
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (int i = 0; i + 1 <= n; i++) {
        for (int j = 0; j <= (n + 1) / 2; j++) {
            for (int last1 = 0; last1 < 2; last1++) {
                for (int last2 = 0; last2 < 2; last2++) {
                    dp[i + 1][j][last2][0] = min(dp[i + 1][j][last2][0], dp[i][j][last1][last2]);
                    if (last2 == 1) continue;
                    if (last1 == 0) {
                        int sh = 0;
                        if (a[i] >= a[i + 1]) sh = a[i] - a[i + 1] + 1;
                        int sh2 = 0;
                        if (a[i + 2] >= a[i + 1]) sh2 = a[i + 2] - a[i + 1] + 1;
                        dp[i + 1][j + 1][0][1] = min(dp[i + 1][j + 1][0][1], dp[i][j][last1][last2] + sh + sh2);
                    }
                    else {
                        int cur = 0;
                        if (i == 0) continue;
                        cur = min(a[i], a[i - 1] - 1);
                        int sh = 0;

                        if (cur >= a[i + 1]) sh = cur - a[i + 1] + 1;
                        int sh2 = 0;
                        if (a[i + 2] >= a[i + 1]) sh2 = a[i + 2] - a[i + 1] + 1;
                        dp[i + 1][j + 1][0][1] = min(dp[i + 1][j + 1][0][1], dp[i][j][last1][last2] + sh + sh2);
                    }
                }
            }
        }
    }
    for (int k = 1; k <= (n + 1) / 2; k++) {
        int mn = dp[n][k][0][0];
        for (int ok1 = 0; ok1 < 2; ok1++) {
            for (int ok2 = 0; ok2 < 2; ok2++) {
                mn = min(mn, dp[n][k][ok1][ok2]);
            }
        }

        cout << mn << " ";
    }
    return 0;
}