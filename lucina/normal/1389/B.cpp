#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
int k, z;


void solve () {
    cin >> n >> k >> z;

    int dp[n + 2][7];

    memset(dp, -1, sizeof(dp));

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    dp[1][z] = a[1];

    for (int i = 1 ; i < n ; ++ i) {
        for (int j = 0 ; j < 6 ; ++ j) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1]);
            int t = a[i] + a[i + 1];
            for (int x = 1 ; j - x >= 0; ++ x) {
                dp[i + 1][j - x] = max(dp[i + 1][j - x], dp[i][j] + a[i + 1] + t * x);
            }

        }
    }

    int ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 0 ; j <= z ; ++ j) {
            if (dp[i][j] == -1) continue;
            int u = z - j;
            if (i + 2 * u - 1 <= k) ans = max(ans, dp[i][j]);
            if (j >= 1 && i - 1 + 2 * u < k) ans = max(ans, dp[i][j] + a[i - 1]);
        }
    }

    cout << ans << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/