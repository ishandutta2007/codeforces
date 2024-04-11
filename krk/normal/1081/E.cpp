#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
int dp[Maxn], par[Maxn];
ll res[Maxn];

int main()
{
    dp[0] = 0;
    scanf("%d", &n); n /= 2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i + 1] = Maxn;
        for (int j = 1; j * j < a[i]; j++) {
            int lft = a[i] - j * j;
            if (lft % (2 * j) == 0) {
                int m = lft / (2 * j);
                if (m > dp[i]) {
                    if (m + j < dp[i + 1]) {
                        dp[i + 1] = m + j;
                        par[i + 1] = m;
                    }
                }
            }
        }
        if (dp[i + 1] >= Maxn) { printf("No\n"); return 0; }
    }
    for (int i = n - 1; i >= 0; i--) {
        res[2 * i + 1] = a[i];
        res[2 * i] = ll(par[i + 1]) * par[i + 1] - ll(dp[i]) * dp[i];
    }
    printf("Yes\n");
    for (int i = 0; i < 2 * n; i++)
        printf("%I64d%c", res[i], i + 1 < 2 * n? ' ': '\n');
    return 0;
}