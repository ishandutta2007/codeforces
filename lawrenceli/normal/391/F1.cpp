#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int MAXN = 3005;
const ll INF = 1e18;

int n, k;
ll p[MAXN];
ll dp[MAXN][MAXN], best1[MAXN][MAXN], best2[MAXN][MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> p[i];
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            dp[i][j] = best1[i][j] = best2[i][j] = -INF;

    dp[0][0] = 0;
    best1[0][0] = 0;
    best2[0][0] = -p[1];

    ll ans = 0;

    for (int i=1; i<=n; i++)
        for (int j=0; j<=k; j++) {
            if (i > 1 && j > 0) dp[i][j] = p[i] + best2[i-2][j-1];
            ans = max(ans, dp[i][j]);
            best1[i][j] = max(best1[i-1][j], dp[i][j]);
            best2[i][j] = max(best2[i-1][j], best1[i][j] - p[i+1]);
        }

    cout << ans << endl;
    return 0;
}