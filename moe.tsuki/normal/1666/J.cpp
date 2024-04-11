#include <bits/stdc++.h>
using namespace std;
using lld = int64_t;

const lld INF = 1e18;

const int maxn = 205;

lld c[maxn][maxn];
lld dp[maxn][maxn];
int fr[maxn][maxn];
int pa[maxn];

int n;
lld query(int xl, int xr, int yl, int yr) {
    if (xl > xr || yl > yr)
        return 0;
    --xl, --yl;
    return c[xr][yr] - c[xl][yr] - c[xr][yl] + c[xl][yl];
}
int DFS(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return l;
    int k = fr[l][r];
    pa[DFS(l, k-1)] = k;
    pa[DFS(k+1, r)] = k;
    return k;
}
lld cost(int l, int r) {
    if (l > r)
        return 0;
    // [l, r]
    return query(l, r, 1, l - 1) + query(l, r, r + 1, n);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] += c[i-1][j] + c[i][j-1] - c[i-1][j-1];
        }
    }

    for (int l = n; l >= 1; l--) {
        dp[l][l] = 0;
        for (int r = l + 1; r <= n; r++) {
            dp[l][r] = INF;
            for (int k = l; k <= r; k++) {
                lld cur = dp[l][k-1] + dp[k+1][r] + cost(l, k - 1) + cost(k + 1, r);
                if (dp[l][r] > cur) {
                    dp[l][r] = cur;
                    fr[l][r] = k;
                }
            }
        }
    }

    // cerr << dp[1][n] << '\n';
    DFS(1, n);
    for (int i = 1; i <= n; i++)
        cout << pa[i] << (i == n ? '\n' : ' ');
}