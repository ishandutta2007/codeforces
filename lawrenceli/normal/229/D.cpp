#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 5005;

int n, h[MAXN], pre[MAXN];
int dp[MAXN][MAXN], best[MAXN][MAXN], pnt[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        pre[i] = pre[i-1] + h[i];
    }

    memset(best, -63, sizeof(best));
    best[0][0] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            while (pnt[j] > 0 && pre[j] - pre[pnt[j]-1] <= pre[i] - pre[j]) pnt[j]--;
            dp[i][j] = best[j][pnt[j]] + 1;
        }
        for (int j=i-1; j>=0; j--)
            best[i][j] = max(best[i][j+1], dp[i][j]);
        pnt[i] = i;
    }

    int ans = 0;
    for (int i=0; i<n; i++)
        ans = max(ans, dp[n][i]);

    cout << n-ans << '\n';
    return 0;
}