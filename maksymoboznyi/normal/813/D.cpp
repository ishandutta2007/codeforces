#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5001], dp[5001][5001], maxmod[5001], maxnum[100005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = 1;
        for (int j = 1; j < i; j++)
            if (abs(a[i] - a[j]) == 1 || a[i] % 7 == a[j] % 7)
                dp[0][i] = max(dp[0][j]+1, dp[0][i]);
        dp[i][0] = dp[0][i];
    }
    for (int y = 0; y <= n; y++)
    {
        for (int i = 0; i <= 7; i++)
            maxmod[i] = 0;
        for (int j = 1; j <= 100000; j++)
            maxnum[j] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == y)
            {
                dp[i][y] = 0;
                continue;
            }
            if (i < y)
            {
                dp[i][y] = dp[y][i];
                maxmod[a[i] % 7] = max(maxmod[a[i] % 7], dp[i][y]);
                maxnum[a[i]] = max(maxnum[a[i]], dp[i][y]);
                continue;
            }
            dp[i][y] = 1 + max(dp[0][y], max(maxmod[a[i] % 7], max(maxnum[a[i]+1], maxnum[a[i]-1])));
            maxmod[a[i] % 7] = max(maxmod[a[i] % 7], dp[i][y]);
            maxnum[a[i]] = max(maxnum[a[i]], dp[i][y]);
 //jj
        }
    }
    ll ma = 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ma = max(ma, dp[i][j]);
    cout << ma;
    return 0;
}