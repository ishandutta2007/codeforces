#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxm = 260;

int T;
int n;
int a[Maxn];
int dp[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            dp[i] = 1;
            for (int j = max(0, i - Maxm); j < i; j++)
                if ((a[j] ^ i) < (a[i] ^ j))
                    dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}