#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 3005;
ll dp[maxN][maxN][2];
const ll INF = (ll)1e18;
ll p[maxN];
int n, k;
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= k; j++) {
            for (int flag = 0; flag < 2; flag++) {
                dp[i][j][flag] = -INF;
            }
        }
    }
    dp[1][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int flag = 0; flag < 2; flag++) {
                if (flag == 1) {
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][1] + p[i]);
                    dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1]);
                }
                else {
                    if (j + 1 <= k) {
                        dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0] - p[i]);
                    }
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0]);
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= k; j++) {
        ans = max(ans, dp[n + 1][j][0]);
    }
    cout << ans;
    return 0;
}