#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 200005;
const string lets = "LR";

int T;
int n;
char str[Maxn];
int dp[Maxn][2][3];

int Try(int l, int r)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = Inf;
    int a = r, b = 1 + (l == r);
    dp[2][a][b] = (str[0] != lets[l]) + (str[1] != lets[r]);
    for (int i = 2; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                for (int z = 0; z < 2; z++) {
                    int na = z, nb = j == z? k + 1: 1;
                    if (nb < 3)
                        dp[i + 1][na][nb] = min(dp[i + 1][na][nb], dp[i][j][k] + (str[i] != lets[z]));
                }
    int c = l, d = 1 + (l == r);
    int res = Inf;
    for (int j = 0; j < 2; j++)
        for (int k = 0; k < 3; k++)
            if (j != c || d + k < 3) res = min(res, dp[n][j][k]);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int res = min(min(Try(0, 0), Try(0, 1)), min(Try(1, 0), Try(1, 1)));
        printf("%d\n", res);
    }
    return 0;
}