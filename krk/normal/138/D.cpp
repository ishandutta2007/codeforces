#include <bits/stdc++.h>
using namespace std;

const int Maxn = 25;
const int Inf = 1000000000;

int n, m;
char A[Maxn][Maxn];
char B[Maxn][Maxn];
int dp[Maxn][Maxn][Maxn][Maxn];

int Get(int r1, int c1, int r2, int c2)
{
    if (r1 > r2 || c1 > c2) return 0;
    if (dp[r1][c1][r2][c2] == -1) {
        set <int> S;
        for (int i = r1; i <= r2; i++)
            for (int j = c1; j <= c2; j++)
                if (B[i][j] == 'L') S.insert(Get(r1, c1, i - 1, c2) ^ Get(i + 1, c1, r2, c2));
                else if (B[i][j] == 'R') S.insert(Get(r1, c1, r2, j - 1) ^ Get(r1, j + 1, r2, c2));
                else if (B[i][j] == 'X')
                    S.insert(Get(r1, c1, i - 1, j - 1) ^ Get(r1, j + 1, i - 1, c2) ^
                             Get(i + 1, c1, r2, j - 1) ^ Get(i + 1, j + 1, r2, c2));
        int res = 0;
        while (S.count(res)) res++;
        dp[r1][c1][r2][c2] = res;
    }
    return dp[r1][c1][r2][c2];
}

int Solve(int val)
{
    int mnr = Inf, mnc = Inf, mxr = -Inf, mxc = -Inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if ((i + j) % 2 == val) {
            mnr = min(mnr, i + j);
            mnc = min(mnc, i - j);
            mxr = max(mxr, i + j);
            mxc = max(mxc, i - j);
        }
    fill((char*)B, (char*)B + Maxn * Maxn, '?');
    if (mnr > mxr || mnc > mxc) return 0;
    fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * Maxn, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if ((i + j - mnr) % 2 == 0)
            B[(i + j - mnr) / 2][(i - j - mnc) / 2] = A[i][j];
    return Get(0, 0, (mxr - mnr) / 2, (mxc - mnc) / 2);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", A[i]);
    int res = (Solve(0) ^ Solve(1));
    printf("%s\n", res? "WIN": "LOSE");
    return 0;
}