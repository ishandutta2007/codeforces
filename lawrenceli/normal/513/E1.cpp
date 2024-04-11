//slow algorithm
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 405;
const int INF = 1e9;

int sgn[2] = {1, -1};
int n, k, ar[MAXN], p[MAXN], ma[2][MAXN];
int dp[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        p[i+1] = p[i] + ar[i];
    }

    for (int c=0; c<2; c++) {
        fill(ma[c], ma[c]+MAXN, -INF);
        for (int i=1; i<=n; i++) {
            ma[c][i] = ma[c][i-1];
            for (int j=0; j<i; j++)
                ma[c][i] = max(ma[c][i], -sgn[c]*(p[i]-p[j]));
        }
    }

    for (int k1=0; k1<k-1; k1++) {
        for (int i=1; i<=n; i++)
            for (int j=0; j<i; j++)
                dp[i][j] = max(ma[0][j]+(p[i]-p[j]), ma[1][j]-(p[i]-p[j]));

        for (int c=0; c<2; c++) {
            fill(ma[c], ma[c]+MAXN, -INF);
            for (int i=1; i<=n; i++) {
                ma[c][i] = ma[c][i-1];
                for (int j=0; j<i; j++)
                    ma[c][i] = max(ma[c][i], dp[i][j]-sgn[c]*(p[i]-p[j]));
            }
        }
    }

    int ans = -INF;
    for (int i=1; i<=n; i++)
        for (int j=0; j<i; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}