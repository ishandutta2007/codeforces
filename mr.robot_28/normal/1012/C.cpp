
#include <bits/stdc++.h>
using namespace std;
#define int long long
int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}
int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dp[2][n + 2][3];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int t = 0; t < 3; t++)
            {
                dp[i][j][t] = 1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int t = 0; t < 3; t++)
            {
                dp[i & 1][j][t] = 1e9;
            }
        }
        for(int j = 0; j <= n; j++)
        {
            dp[i & 1][j][0] = min(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
            int val =0 ;
            if(i != 1)
            {
                val = max(0, a[i - 2] - a[i - 1] + 1);
            }
            dp[i & 1][j + 1][2] = min(dp[i & 1][j + 1][2], dp[(i - 1) & 1][j][0] + val);
            if(i >= 2)
            {
                dp[i & 1][j][1] = min(1e9, dp[(i - 1) & 1][j][2] + max(0, a[i - 1] - a[i - 2] + 1));
            }
            if(i >= 3)
            {
                dp[i & 1][j + 1][2] = min(dp[i & 1][j + 1][2], dp[(i - 1) & 1][j][1] + max(0, -a[i - 1] + min(a[i - 3] - 1, a[i - 2]) + 1));
            }
        }
    }
    for(int j = 1; j <= (n + 1) / 2; j++)
    {
        cout << min(dp[n & 1][j][1], min(dp[n & 1][j][0], dp[n & 1][j][2])) << " ";
    }
    return 0;
}