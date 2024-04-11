#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 5005;

int T;
int n;
int a[Maxn];
int dp[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        fill(dp, dp + n + 1, Inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + int(a[i] != 0));
            int cur = a[i];
            for (int j = i + 1; j < n; j++) {
                cur ^= a[j];
                dp[j + 1] = min(dp[j + 1], dp[i] + j - i + int(cur != 0));
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}