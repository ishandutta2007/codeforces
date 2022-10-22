#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int dp[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (a[i] <= i) dp[i] = max(dp[i], dp[i - a[i]] + 1);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}