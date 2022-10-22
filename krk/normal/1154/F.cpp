#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;
const int Maxk = 2005;

int n, m, k;
int a[Maxn];
ll sum[Maxn];
ll dp[Maxk];
int fre[Maxk];

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        if (x < Maxk) fre[x] = max(fre[x], y);
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    fill((ll*)dp, (ll*)dp + Maxk, Inf);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
        for (int j = 0; i + j <= k; j++) {
            ll pay = sum[i + j - 1];
            if (i - 1 + fre[j] >= 0) pay -= sum[i - 1 + fre[j]];
            dp[i + j] = min(dp[i + j], dp[i] + pay);
        }
    }
    cout << dp[k] << endl;
    return 0;
}