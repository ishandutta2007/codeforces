#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
const int MAXB = (1<<20) + 5;

int n, m, a[MAXN][MAXN], sum[MAXN][MAXN], ma[MAXN][MAXN], mask[MAXN][MAXN];
int dp[MAXB][2];
char s[MAXN][MAXN];

void setmin(int& x, int y) { if (x > y) x = y; }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for (int i=0; i<m; i++)
        for (int j=0; j<26; j++)
            for (int k=0; k<n; k++)
                if (s[k][i]-'a' == j) {
                    sum[i][j] += a[k][i];
                    ma[i][j] = max(ma[i][j], a[k][i]);
                    mask[i][j] ^= 1<<k;
                }

    int st = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            bool b = 1;
            for (int k=0; k<n; k++)
                if (k!=i && s[k][j] == s[i][j])
                    b = 0;
            if (b) st |= 1<<i;
        }

    for (int i=0; i<MAXB; i++)
        dp[i][0] = dp[i][1] = 1e9;

    dp[st][0] = 0;

    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++) {
            for (int k=0; k<1<<n; k++)
                if (dp[k][0] < 1e9) {
                    setmin(dp[k][1], dp[k][0]);
                    setmin(dp[k|1<<j][1], dp[k][0]+a[j][i]);
                    int c = s[j][i]-'a';
                    setmin(dp[k | mask[i][c]][1], dp[k][0]+sum[i][c]-ma[i][c]);
                }

            for (int k=0; k<1<<n; k++)
                dp[k][0] = dp[k][1], dp[k][1] = 1e9;
        }

    cout << dp[(1<<n)-1][0];
}