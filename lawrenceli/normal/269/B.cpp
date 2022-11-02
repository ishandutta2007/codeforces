#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1e9;

int n, m, s[MAXN], dp[MAXN][MAXN];

void setmin(int& a, int b) { if (a > b) a = b; }

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        double junk;
        cin >> s[i] >> junk;
    }
    for (int i=1; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            dp[i][j] = INF;
    for (int i=0; i<MAXN; i++) dp[0][i] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (j > 0) dp[i][j] = dp[i][j-1];
            setmin(dp[i][j], dp[i-1][j] + 1);
            if (j == s[i-1]) setmin(dp[i][j], dp[i-1][j]);
        }
    }
    int ans = INF;
    for (int i=0; i<=m; i++) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}