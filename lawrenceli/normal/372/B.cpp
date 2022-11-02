#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
using namespace std;

const int MAXN = 50;

int n, m, q, num[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
bool mat[MAXN][MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m >> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c; cin >> c;
            mat[i][j] = c - '0';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mat[i][j]) num[i][j] = 0;
            else if (i == 0) num[i][j] = 1;
            else num[i][j] = num[i-1][j] + 1;
        }
    }

    for (int r1=0; r1<n; r1++)
        for (int r2=r1; r2<n; r2++)
            for (int c1=0; c1<m; c1++)
                for (int c2=c1; c2<m; c2++) {
                    if (r2 > r1) dp[r1][r2][c1][c2] += dp[r1][r2-1][c1][c2];
                    if (c2 > c1) dp[r1][r2][c1][c2] += dp[r1][r2][c1][c2-1];
                    if (r2 > r1 && c2 > c1) dp[r1][r2][c1][c2] -= dp[r1][r2-1][c1][c2-1];
                    int cur = 1e9;
                    for (int i=c2; i>=c1; i--) {
                        cur = min(cur, min(num[r2][i], r2 - r1 + 1));
                        dp[r1][r2][c1][c2] += cur;
                    }
                }

    for (int i=0; i<q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        cout << dp[a][c][b][d] << endl;
    }

    return 0;
}