
#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int dp[500][501];
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector <int> a(n);
        vector <int> b(n + 1);
        b[n] = x;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        for(int i = 0;i < n; i++)
        {
            for(int j = 0; j <= 500; j++)
            {
                dp[i][j] = 1e9;
            }
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++)
        {
            if(i >= 2 && a[i - 1] < a[i - 2])
            {
                break;
            }
            if((i == 0 || a[i - 1] <= x) && a[i] > x)
            {
                dp[i][x] = 1;
                bool fl = 1;
                for(int j = i + 1; j < n; j++)
                {
                    if(j == i + 1 && a[j] < x || j != i + 1 && a[j] < a[j - 1])
                    {
                        fl = 0;
                    }
                }
                if(fl)
                {
                    ans = 1;
                }
            }
            if(i == n - 1 && (i == 0 || a[i - 1] <= a[i]))
            {
                ans = 0;
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(j != i - 1 && a[j + 1] > a[j + 2])
                {
                    break;
                }
                if(a[j] >= a[i - 1] && a[j] < a[i])
                {
                    for(int t = 0; t <= 500; t++)
                    {
                        if(j != i - 1 && t > a[j + 1])
                        {
                            break;
                        }
                        dp[i][a[j]] = min(dp[i][a[j]], dp[j][t] + 1);
                    }
                }
            }
            bool fl1 = 1;
            for(int j = i + 1; j < n - 1; j++)
            {
                if(a[j] > a[j + 1])
                {
                    fl1 = 0;
                }
            }
            for(int t =0; t <= 500; t++)
            {
                if(i != n - 1 && t > a[i + 1] || !fl1)
                {
                    break;
                }
                ans = min(ans, dp[i][t]);
            }
        }
        if(ans == 1e9)
        {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}