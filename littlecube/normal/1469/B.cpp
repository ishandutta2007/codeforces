#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r[100], b[100], n, m, dp[101][101] = {{0}},  re = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> r[i];
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 && j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + b[j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + r[i - 1];
                else
                    dp[i][j] = max(dp[i][j - 1] + b[j - 1], dp[i - 1][j] + r[i - 1]);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                re = max(re, dp[i][j]);
        cout << re << '\n';
    }
}