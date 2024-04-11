#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30100;
const int INF = 1e9;

int sgn[2] = {1, -1};
int n, k, ar[MAXN], p[MAXN], dp[MAXN], ma[2][5][MAXN], tmp[2][MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        p[i+1] = p[i] + ar[i];
    }

    for (int c=0; c<2; c++)
        for (int d=-2; d<=2; d++) {
            tmp[c][0] = ma[c][d+2][0] = -INF;
            int m = 0, m2 = -INF;
            for (int i=1; i<=n; i++) {
                m2 = max(m2, m-sgn[c]*p[i]);
                ma[c][d+2][i] = max(ma[c][d+2][i-1], m2+d*p[i]);
                m = max(m, sgn[c]*p[i]);
            }
        }

    for (int k1=0; k1<k-1; k1++) {
        for (int i=1; i<=n; i++) {
            dp[i] = max(ma[0][-1+2][i-1]+p[i], ma[1][1+2][i-1]-p[i]);
            tmp[0][i] = max(ma[0][0+2][i-1], ma[1][2+2][i-1]-2*p[i]);
            tmp[1][i] = max(ma[0][-2+2][i-1]+2*p[i], ma[1][0+2][i-1]);
        }

        for (int c=0; c<2; c++)
            for (int d=-2; d<=2; d++)
                for (int i=1; i<=n; i++) {
                    tmp[c][i] = max(tmp[c][i], tmp[c][i-1]);
                    ma[c][d+2][i] = max(ma[c][d+2][i-1], tmp[c][i]+d*p[i]);
                }
    }

    int ans = -INF;
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}