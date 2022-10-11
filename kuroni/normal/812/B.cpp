#include <iostream>
#include <cstdio>
using namespace std;

string s;
int n, m, i, j, f[105], l[105], dp[2][15], save = 0;

int main()
{
    ios_base::sync_with_stdio();
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> s;
        f[n + 1 - i] = m + 1;
        l[n + 1 - i] = 0;
        for (j = 0; j < m + 2; j++)
            if (s[j] == '1')
            {
                if (save == 0)
                    save = n + 1 - i;
                if (f[n + 1 - i] == m + 1)
                {
                    f[n + 1 - i] = j;
                }
                l[n + 1 - i] = j;
            }
    }
    dp[0][0] = 0;
    dp[1][0] = 1000000000;
    n = save;
    for (i = 1; i < n; i++)
    {
        dp[0][i] = min(dp[0][i - 1] + 2 * l[i], dp[1][i - 1] + m + 1) + 1;
        dp[1][i] = min(dp[1][i - 1] + 2 * (m + 1 - f[i]), dp[0][i - 1] + m + 1) + 1;
    }
    cout << min(dp[0][n - 1] + l[n], dp[1][n - 1] + (m + 1 - f[n]));
}