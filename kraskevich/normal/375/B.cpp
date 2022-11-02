#include <bits/stdc++.h>

using namespace std;

const int N = 5555;

string s[N];
int dp[N][N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] = '0' + s[i];
    }

    for (int i = 0; i <= m + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            dp[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        int l = -1;
        for (int r = 1; r <= m; r++)
        {
            if (s[i][r] == '1' && l == -1)
                l = r;
            if (s[i][r] == '0')
                l = -1;
            if ((r == m || s[i][r + 1] == '0') && l >= 0)
                dp[l][r]++;
        }
    }
    for (int len = m; len >= 1; len--)
        for (int l = 1, r = len; r <= m; l++, r++)
            dp[l][r] += dp[l - 1][r] + dp[l][r + 1] - dp[l - 1][r + 1];
    int res = 0;
    for (int l = 1; l <= m; l++)
        for (int r = l; r <= m; r++)
            res = max(res, (r - l + 1) * dp[l][r]);
    cout << res;

    return 0;
}