#include <bits/stdc++.h>
using namespace std;

const int Maxb = 20;
const int Maxn = 100005;
const int Inf = 1000000000;

int n, m;
char B[Maxb][Maxn];
int dp[Maxb + 1][1 << Maxb];
int res = Inf;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int j = 0; j < m; j++) {
        int mask = 0;
        for (int i = 0; i < n; i++)
            if (B[i][j] == '1') mask |= 1 << i;
        dp[0][mask]++;
    }
    for (int b = 0; b < n; b++)
        for (int i = b; i >= 0; i--)
            for (int j = 0; j < 1 << n; j++)
                dp[i + 1][j ^ (1 << b)] += dp[i][j];
    for (int j = 0; j < 1 << n; j++) {
        int cand = 0;
        for (int i = 0; i <= n; i++)
            cand += dp[i][j] * min(i, n - i);
        res = min(res, cand);
    }
    printf("%d\n", res);
    return 0;
}