#include<bits/stdc++.h>
using namespace std;
int const N = 256;
int n, k;
char s[N];
char t[5];
int dp[N][N][N];
int ans;

void upd_max(int &a, int b) {
    a = max(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k >> s + 1 >> t;

    memset(dp, -1, sizeof(dp));

    if (t[0] == t[1]) {
        int v = count(s + 1, s + 1 + n, t[0]);
        v = min(n, v + k);
        cout << v * (v - 1) / 2 << '\n';
        return 0;
    }

    dp[0][0][0] = 0;

    for (int i = 0 ; i < n ; ++ i)
    for (int j = 0 ; j <= k ; ++ j)
    for (int x = 0 ; x <= n ; ++ x) {
        if (dp[i][j][x] == -1) continue;
        if (s[i + 1] == t[0]) {
            upd_max(dp[i + 1][j][x + 1], dp[i][j][x]);
        }
        if (s[i + 1] == t[1]) {
            upd_max(dp[i + 1][j][x], dp[i][j][x] + x);
        }
        upd_max(dp[i + 1][j][x], dp[i][j][x]);
        if (j < k) {
            upd_max(dp[i + 1][j + 1][x + 1], dp[i][j][x]);
            upd_max(dp[i + 1][j + 1][x], dp[i][j][x] + x);
        }
    }

    int ans = 0;
    for (int j = 0 ; j <= k ; ++ j)
    for (int x = 0 ; x <= n ; ++ x) {
     //   cout << dp[n][j][x] << '\n';
        ans = max(ans, dp[n][j][x]);
    }

    cout << ans << '\n';
}
/*
    I have been too lazy, lately.
*/