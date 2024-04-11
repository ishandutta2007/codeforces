#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int n, k;
int a[Maxn];
int dp[2], ndp[2];

bool Check(int wh, int x)
{
    dp[0] = dp[1] = -Inf;
    dp[wh] = 0;
    for (int i = 0; i < n; i++) {
        ndp[0] = max(dp[0], (a[i] <= x? dp[1] + 1: -Inf));
        ndp[1] = max(dp[1], dp[0] + 1);
        dp[0] = ndp[0]; dp[1] = ndp[1];
    }
    return dp[0] >= k || dp[1] >= k;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int lef = 0, rig = 1000000007;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(0, mid) || Check(1, mid))
            rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", lef);
    return 0;
}