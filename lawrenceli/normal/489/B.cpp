#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, m, a[MAXN], b[MAXN], dp[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    for (int i=0; i<m; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    dp[0][0] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            if (abs(a[i]-b[j]) <= 1) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
        }

    int ans = 0;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}