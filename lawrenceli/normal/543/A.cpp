#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, m, b, mod, a[MAXN];
int dp[2][MAXN][MAXN];

void add(int& a, int b) { a = (a+b)%mod; }

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> b >> mod;
    for (int i=0; i<n; i++) cin >> a[i];
    dp[0][0][0] = 1;
    for (int ii=0; ii<m; ii++) {
        for (int i=0; i<n; i++)
            for (int j=0; j<=b; j++) {
                add(dp[0][i+1][j], dp[0][i][j]);
                if (j+a[i]<=b) add(dp[1][i][j+a[i]], dp[0][i][j]);
            }

        for (int i=0; i<=n; i++)
            for (int j=0; j<=b; j++)
                dp[0][i][j] = dp[1][i][j], dp[1][i][j] = 0;
    }

    int ans = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<=b; j++)
            add(ans, dp[0][i][j]);

    cout << ans;
}