#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxm = 10;

int n, m;
int B[Maxn][Maxn];
int dp[Maxn][Maxn];
int lg2[Maxn];
int mx[Maxn][Maxn][Maxm][Maxm];

int getMax(int r1, int c1, int r2, int c2)
{
    int a = lg2[r2 - r1 + 1];
    int b = lg2[c2 - c1 + 1];
    return max(max(mx[r1][c1][a][b], mx[r1][c2 - (1 << b) + 1][a][b]),
               max(mx[r2 - (1 << a) + 1][c1][a][b], mx[r2 - (1 << a) + 1][c2 - (1 << b) + 1][a][b]));
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &B[i][j]);
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--) {
            dp[i][j] = B[i][j] == 1? min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]) + 1: 0;
            mx[i][j][0][0] = dp[i][j];
        }
    for (int i = 0; i < Maxm; i++)
        for (int j = 1 << i; j < Maxn && j < (1 << i + 1); j++)
            lg2[j] = i;
    for (int a = 0; a < Maxm; a++)
        for (int b = 0; b < Maxm; b++)
            for (int i = 1; i + (1 << a) <= n + 1; i++)
                for (int j = 1; j + (1 << b) <= m + 1; j++)
                    if (a > 0) mx[i][j][a][b] = max(mx[i][j][a - 1][b], mx[i + (1 << a - 1)][j][a - 1][b]);
                    else if (b > 0) mx[i][j][a][b] = max(mx[i][j][a][b - 1], mx[i][j + (1 << b - 1)][a][b - 1]);
    int q; scanf("%d", &q);
    while (q--) {
        int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int lef = 1, rig = min(r2 - r1 + 1, c2 - c1 + 1);
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (getMax(r1, c1, r2 - mid + 1, c2 - mid + 1) >= mid)
                lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", rig);
    }
    return 0;
}