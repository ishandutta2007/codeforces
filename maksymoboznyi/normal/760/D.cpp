#include <bits/stdc++.h>

using namespace std;

long long a[int(1e5) + 5];
long long n;
int dp[int(1e5) + 5];
long long sum[int(1e5)+5];


int main()
{
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 2000000000;
    }
    dp[1] = 20;
    for (int i = 2; i <= n; i++)
    {
        if (i > 5 && a[i] - a[i-5] < 1440)

        {
            int y = i-5;
            while (y > 1 && a[i] - a[y-1] < 1440)
                y--;
            if (y == 1)
                dp[i] = min(dp[i], 120);
            else
                dp[i] = min(dp[i], 120 + dp[y-1]);
        }
        if (i > 2 && a[i] - a[i-2] < 90)
        {
            int y = i-2;
            while (y > 1 && a[i] - a[y-1] < 90)
                y--;
            if (y == 1)
                dp[i] = min(dp[i], 50);
            else
                dp[i] = min(dp[i], 50 + dp[y-1]);
        }
        dp[i] = min(dp[i], dp[i-1]+20);
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = dp[i] - sum[i-1];
        cout << sum[i] << endl;
        sum[i] = sum[i-1]+sum[i];
    }
    return 0;
}