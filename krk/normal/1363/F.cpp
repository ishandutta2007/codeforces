#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Maxl = 26;
const int Inf = 1000000000;

int T;
int n;
char A[Maxn], B[Maxn];
int sumA[Maxn][Maxl], sumB[Maxn][Maxl];
int imp[Maxn];
int dp[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        for (int i = 0; i <= n; i++) {
            imp[i] = Inf;
            for (int j = 0; j <= n; j++)
                dp[i][j] = Inf;
        }
        for (int j = 0; j < Maxl; j++)
            sumA[n][j] = sumB[n][j] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < Maxl; j++) {
                sumA[i][j] = sumA[i + 1][j];
                sumB[i][j] = sumB[i + 1][j];
            }
            sumA[i][A[i] - 'a']++;
            sumB[i][B[i] - 'a']++;
        }
        bool ok = true;
        for (int j = 0; j < Maxl; j++)
            if (sumA[0][j] != sumB[0][j])
                ok = false;
        if (!ok) { printf("-1\n"); continue; }
        dp[n][n] = 0;
        for (int j = n; j > 0; j--) {
            int let = B[j - 1] - 'a';
            for (int i = n; i >= 0; i--) {
                imp[j] = min(imp[j], dp[i][j] + i);
                if (sumA[i][let] > sumB[j][let])
                    dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);
                if (i > 0 && A[i - 1] == B[j - 1] && sumA[i - 1][let] >= sumB[j - 1][let])
                    dp[i - 1][j - 1] = min(dp[i - 1][j - 1], imp[j] - i);
            }
        }
        printf("%d\n", dp[0][0]);
    }
    return 0;
}