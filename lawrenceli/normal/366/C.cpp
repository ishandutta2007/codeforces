#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int MAXA = 100010;

int n, k, a[MAXN], b[MAXN];
int dp[2*MAXA][2];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);
    for (int i=0; i<2*MAXA; i++) dp[i][0] = dp[i][1] = -1;
    dp[MAXA][0] = dp[MAXA][1] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<2*MAXA; j++) {
            if (dp[j][0] == -1) continue;
            int x = j + a[i] - k * b[i];
            if (x >= 0 && x < 2*MAXA) dp[x][1] = max(dp[x][1], dp[j][0] + a[i]);
        }
        for (int j=0; j<2*MAXA; j++) dp[j][0] = dp[j][1];
    }
    if (dp[MAXA][0] <= 0) printf("-1\n");
    else printf("%d\n", dp[MAXA][0]);
    return 0;
}