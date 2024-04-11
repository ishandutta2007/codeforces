#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30100;
const int MAXM = 300;
const int INF = 1e9;

int n, d, ar[MAXN], dp[MAXN][2*MAXM];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> d;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        ar[x]++;
    }

    for (int i=0; i<MAXN; i++)
        for (int j=0; j<2*MAXM; j++)
            dp[i][j] = -INF;
    dp[d][MAXM] = ar[d];
    int ans = 0;
    for (int i=d; i<MAXN; i++)
        for (int j=0; j<2*MAXM; j++)
            if (dp[i][j]>=0) {
                ans = max(ans, dp[i][j]);
                for (int k=-1; k<=1; k++)
                    if (j+k-MAXM+d>0 && i+j+k-MAXM+d < MAXN)
                        dp[i+j+k-MAXM+d][j+k] = max(dp[i+j+k-MAXM+d][j+k], dp[i][j]+ar[i+j+k-MAXM+d]);
            }
    cout << ans << '\n';
    return 0;
}