#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3005;
const int INF = 1e9;

int n, a[MAXN], b[MAXN], c[MAXN], dp[MAXN][2][2];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);
    for (int i=0; i<n; i++) scanf("%d", &c[i]);
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                dp[i][j][k] = -INF;
    dp[0][0][0] = a[0];
    dp[0][0][1] = b[0];
    for (int i=1; i<n; i++) {
        dp[i][0][0] = max(dp[i-1][0][1], dp[i-1][1][1]) + a[i];
        dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1]) + b[i];
        dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][1][0]) + b[i];
        dp[i][1][1] = max(dp[i-1][0][0], dp[i-1][1][0]) + c[i];
    }
    printf("%d\n", max(dp[n-1][0][0], dp[n-1][1][0]));
    return 0;
}