#include <bits/stdc++.h>
using namespace std;
int test, n, k;
int a[111111], b[111111];
pair<int, int> arr[111111];
long long dp[111111][2], ans;
void upd(long long &x, long long y)
{
    if (x < y) x = y;
}
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
        for (int i = 2; i <= n; i++) arr[i - 1] = make_pair(a[i], b[i]);
        sort(arr + 1, arr + n);
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = dp[i][1] = -1e18;
        } 
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = arr[i].first;
            dp[i][1] = arr[i].first + arr[i].second;
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                upd(dp[i + 1][0], dp[i][j]);
                upd(dp[i + 1][j], min((long long)arr[i + 1].first, dp[i][j]) + arr[i + 1].second);
                upd(dp[i + 1][1], arr[i + 1].first + arr[i + 1].second);
            }
        }
        ans = -1e9;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        if (min(ans, (long long)a[1]) + b[1] >= k || a[1] >= k) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}