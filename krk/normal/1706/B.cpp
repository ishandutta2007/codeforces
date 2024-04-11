#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int dp[Maxn][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i][1] = 0;
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            int j = i % 2;
            dp[a][j] = max(dp[a][j], dp[a][1 - j] + 1);
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", max(dp[i][0], dp[i][1]), i + 1 <= n? ' ': '\n');
    }
    return 0;
}