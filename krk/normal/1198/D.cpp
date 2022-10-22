#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int n;
char B[Maxn][Maxn];
int dp[Maxn][Maxn][Maxn][Maxn];

int Solve(int r1, int c1, int r2, int c2)
{
    if (dp[r1][c1][r2][c2] == -1)
        if (r1 == r2 && c1 == c2 && B[r1][c1] == '.') return dp[r1][c1][r2][c2] = 0;
        else {
            int res = max(r2 - r1 + 1, c2 - c1 + 1);
            for (int i = r1; i < r2; i++)
                res = min(res, Solve(r1, c1, i, c2) + Solve(i + 1, c1, r2, c2));
            for (int j = c1; j < c2; j++)
                res = min(res, Solve(r1, c1, r2, j) + Solve(r1, j + 1, r2, c2));
            return dp[r1][c1][r2][c2] = res;
        }
    return dp[r1][c1][r2][c2];
}

int main()
{
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * Maxn, -1);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    printf("%d\n", Solve(0, 0, n - 1, n - 1));
    return 0;
}