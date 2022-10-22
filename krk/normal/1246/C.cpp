#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
int D[Maxn][Maxn], R[Maxn][Maxn];
int tp[Maxn][Maxn], lft[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            if (i + 1 < n) D[i][j] = D[i + 1][j] + (B[i + 1][j] == '.');
            if (j + 1 < m) R[i][j] = R[i][j + 1] + (B[i][j + 1] == '.');
        }
    int len = R[0][0] + 1;
    lft[0][0] = 1; lft[0][len] = mod - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            // from top
            if (i > 0) tp[i][j] = (tp[i][j] + tp[i - 1][j]) % mod;
            if (R[i][j]) {
                lft[i][j + 1] = (lft[i][j + 1] + tp[i][j]) % mod;
                lft[i][j + R[i][j] + 1] = (lft[i][j + R[i][j] + 1] - tp[i][j] + mod) % mod;
            }
            // from lft
            if (j > 0) lft[i][j] = (lft[i][j] + lft[i][j - 1]) % mod;
            if (D[i][j]) {
                tp[i + 1][j] = (tp[i + 1][j] + lft[i][j]) % mod;
                tp[i + D[i][j] + 1][j] = (tp[i + D[i][j] + 1][j] - lft[i][j] + mod) % mod;
            }
        }
    int res = (lft[n - 1][m - 1] + tp[n - 1][m - 1]) % mod;
    printf("%d\n", res);
    return 0;
}