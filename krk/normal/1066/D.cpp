#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m, k;
ll a[Maxn];
int dp[Maxn];
int res;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1 + dp[upper_bound(a, a + n + 1, a[i] + k) - a - 1];
        if (dp[i] <= m) res = n - i;
    }
    printf("%d\n", res);
    return 0;
}