#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 5005;

int T;
int n, m;
char A[Maxn], B[Maxn];
int dp1[Maxn][Maxn], dp2[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        scanf("%s", A);
        scanf("%s", B);
        int res = Inf;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp1[i][j] = dp2[i][j] = Inf;
        dp1[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= m; j++) if (dp1[i][j] < Inf) {
                if (j < m && A[i] == B[j]) dp1[i + 1][j + 1] = min(dp1[i + 1][j + 1], dp1[i][j] + 1);
                dp1[i + 1][j] = min(dp1[i + 1][j], dp1[i][j] + 2);
            }
        if (dp1[n][m] >= Inf) { printf("-1\n"); continue; }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (A[i] == B[j])
                dp1[i + 1][j + 1] = min(dp1[i + 1][j + 1], dp1[i][j]);
        dp2[n][m] = 0;
        for (int i = n; i > 0; i--)
            for (int j = m; j >= 0; j--) if (dp2[i][j] < Inf) {
                if (dp1[i][j] == 0) res = min(res, dp2[i][j]);
                else res = min(res, dp2[i][j] + 1 + dp1[i][j]);
                dp2[i - 1][j] = min(dp2[i - 1][j], dp2[i][j] + 1);
                if (j > 0 && A[i - 1] == B[j - 1]) dp2[i - 1][j - 1] = min(dp2[i - 1][j - 1], dp2[i][j] + 1);
            }
        res = min(res, dp2[0][0]);
        printf("%d\n", res);
    }
    return 0;
}