#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e9 + 7;

int n, a, b, k;
int dp[MAXN][MAXN], pre[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> a >> b >> k;
    if (a<b) {
        a = n+1-a;
        b = n+1-b;
    }
    dp[0][a] = 1;
    for (int i=1; i<=n; i++)
        pre[0][i] = (pre[0][i-1]+dp[0][i])%MOD;

    for (int i=1; i<=k; i++) {
        for (int j=b+1; j<=n; j++) {
            int x = (j+b)/2;
            dp[i][j] = ((pre[i-1][n]-pre[i-1][x]+MOD)%MOD-dp[i-1][j]+MOD)%MOD;
        }
        for (int j=1; j<=n; j++)
            pre[i][j] = (pre[i][j-1]+dp[i][j])%MOD;
    }

    int ans = 0;
    for (int i=1; i<=n; i++) ans = (ans+dp[k][i])%MOD;
    cout << ans << '\n';
    return 0;
}