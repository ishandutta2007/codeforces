#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, dp[N][11];
long long ans = 0;
char s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        int cur = s[i] - '0';
        for (int j = cur + 1; j < 11; j++)
            dp[i][(j * (j - 1) / 2 + cur + 10) % 11] += dp[i - 1][j];
        if (cur > 0)
            dp[i][cur]++;
        ans += accumulate(dp[i], dp[i] + 11, 0);
    }
    cout << ans;
}