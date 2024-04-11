#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
const int INF = 1e9;

int n, m, nxt[MAXN], dp[MAXN][MAXN];
char s[MAXN], p[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s >> p;
    n = strlen(s), m = strlen(p);

    for (int i=0; i<n; i++) {
        int j, k = 0;
        for (j=i; j<n && k<m; j++)
            if (s[j] == p[k]) k++;
        if (k == m) nxt[i] = j;
        else nxt[i] = -1;
    }

    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;

    for (int i=0; i<n; i++)
        for (int j=0; j<=n; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            if (nxt[i] != -1) {
                int j1 = j+nxt[i]-i-m;
                dp[nxt[i]][j1] = max(dp[nxt[i]][j1], dp[i][j]+1);
            }
        }

    for (int i=0; i<=n; i++)
        cout << dp[n][i] << ' ';
    return 0;
}