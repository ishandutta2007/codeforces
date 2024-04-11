#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 105;
const int MOD = 1e9 + 7;

int n, a[10];
int C[MAXN][MAXN];
int dp[10][MAXN];

void init() {
    C[0][0] = 1;
    for (int i=1; i<MAXN; i++) {
        C[i][0] = 1;
        for (int j=1; j<=i; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
}

int go() {
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=n-a[0]; i++)
        dp[0][i] = C[n-1][n-i];

    for (int i=1; i<10; i++)
        for (int j=0; j<=n; j++)
            for (int k=j+a[i]; k<=n; k++)
                if (k <= n)
                    dp[i][j] = (dp[i][j] + ll(dp[i-1][k]) * C[k][j]) % MOD;

    return dp[9][0];
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    init();

    int m; cin >> m;
    for (int i=0; i<10; i++) cin >> a[i];

    int ans = 0;
    for (n=1; n<=m; n++) ans = (ans + go()) % MOD;

    cout << ans << '\n';
    return 0;
}