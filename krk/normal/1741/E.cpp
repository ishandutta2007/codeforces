#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int b[Maxn];
bool dp[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        fill(dp, dp + n + 1, false);
        dp[0] = true;
        for (int i = 0; i <= n; i++) {
            if (i > 0 && i - b[i - 1] - 1 >= 0 && dp[i - b[i - 1] - 1])
                dp[i] = true;
            if (i < n && dp[i] && i + b[i] + 1 <= n)
                dp[i + b[i] + 1] = true;
        }
        printf("%s\n", dp[n]? "YES": "NO");
    }
    return 0;
}