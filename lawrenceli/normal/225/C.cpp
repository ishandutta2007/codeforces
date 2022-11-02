#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

void setmin(int& a, int b) {
    a = min(a, b);
}

int n, m, x, y, num[MAXN][2], dp[MAXN][MAXN][2], ans = 1e9;
char mat[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i=0; i<n; i++) {
        scanf("%s", mat[i]);
    }
    for (int j=0; j<m; j++) {
        int val = 0;
        for (int i=0; i<n; i++) {
            if (mat[i][j] == '#') val++;
        }
        num[j][0] = val; num[j][1] = n - val;
    }
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<2; k++) {
                dp[i][j][k] = 1e9;
            }
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i=0; i<m; i++) {
        for (int j=x; j<=y; j++) {
            for (int k=0; k<2; k++) {
                setmin(dp[i+1][1][k^1], dp[i][j][k] + num[i][k^1]);
            }
        }
        for (int j=0; j<m; j++) {
            for (int k=0; k<2; k++) {
                setmin(dp[i+1][j+1][k], dp[i][j][k] + num[i][k]);
            }
        }
    }
    for (int i=x; i<=y; i++) {
        for (int k=0; k<2; k++) {
            setmin(ans, dp[m][i][k]);
        }
    }
    printf("%d\n", ans);
}