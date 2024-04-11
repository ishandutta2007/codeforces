#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1005;
const int INF = -1U >> 2;

int n, dp[MAXN][MAXN], par[MAXN][MAXN], ans[MAXN];
string s;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> s;

    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = INF;

    for (int i=1; i<=n; i++) dp[0][i] = i;

    for (int i=1; i<n; i++) {
        int best = INF, ind = -1;
        for (int j=1; j<=n; j++) {
            if (s[i-1] == '=')
                dp[i][j] = dp[i-1][j] + j, par[i][j] = j;
            else if (s[i-1] == 'R')
                dp[i][j] = best + j, par[i][j] = ind;
            if (dp[i-1][j] < best)
                best = dp[i-1][j], ind = j;
        }
        best = INF, ind = -1;
        for (int j=n; j>=1; j--) {
            if (s[i-1] == 'L')
                dp[i][j] = best + j, par[i][j] = ind;
            if (dp[i-1][j] < best)
                best = dp[i-1][j], ind = j;
        }
    }

    int best = INF, cur = -1;
    for (int i=1; i<=n; i++)
        if (dp[n-1][i] < best)
            best = dp[n-1][i], cur = i;

    for (int i=n-1; i>=0; i--) {
        ans[i] = cur;
        cur = par[i][cur];
    }

    for (int i=0; i<n; i++) cout << ans[i] << ' ';
    return 0;
}