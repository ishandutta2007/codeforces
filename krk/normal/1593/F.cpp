#include <bits/stdc++.h>
using namespace std;

const int Maxn = 42;

int T;
int n, A, B;
char X[Maxn];
bool dp[Maxn][Maxn][Maxn][Maxn];
bool wh[Maxn][Maxn][Maxn][Maxn];
int prv[Maxn][Maxn][Maxn][Maxn];
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &A, &B);
        scanf("%s", X);
        dp[0][0][0][0] = true;
        for (int i = 0; i < n; i++)
            for (int a = 0; a <= i; a++)
                for (int m1 = 0; m1 < A; m1++)
                    for (int m2 = 0; m2 < B; m2++) if (dp[i][a][m1][m2]) {
                        dp[i][a][m1][m2] = false;
                        // first
                        int nm1 = (10 * m1 + int(X[i] - '0')) % A;
                        dp[i + 1][a + 1][nm1][m2] = true;
                        wh[i + 1][a + 1][nm1][m2] = true;
                        prv[i + 1][a + 1][nm1][m2] = m1;
                        // second
                        int nm2 = (10 * m2 + int(X[i] - '0')) % B;
                        dp[i + 1][a][m1][nm2] = true;
                        wh[i + 1][a][m1][nm2] = false;
                        prv[i + 1][a][m1][nm2] = m2;
                    }
        int cura = 0, curm1, curm2;
        for (int a = 0; a <= n; a++)
            for (int m1 = 0; m1 < A; m1++)
                for (int m2 = 0; m2 < B; m2++) if (dp[n][a][m1][m2]) {
                    dp[n][a][m1][m2] = false;
                    if (0 < a && a < n && m1 == 0 && m2 == 0 && abs(a - (n - a)) < abs(cura - (n - cura))) {
                        cura = a;
                        curm1 = m1;
                        curm2 = m2;
                    }
                }
        if (cura == 0) { printf("-1\n"); continue; }
        for (int i = n; i > 0; i--)
            if (wh[i][cura][curm1][curm2]) {
                res[i - 1] = 'R';
                curm1 = prv[i][cura][curm1][curm2];
                cura--;
            } else {
                res[i - 1] = 'B';
                curm2 = prv[i][cura][curm1][curm2];
            }
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}