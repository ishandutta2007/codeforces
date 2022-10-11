#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const long long INF = 1E18 + 7;

int t, n, a, b;
char s[N];
long long dp[N][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> (s + 1);
        dp[0][0] = 0; dp[0][1] = INF;
        for (int i = 1; i <= n; i++)
            if (s[i] == '0')
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + a);
                dp[i][1] = min(dp[i - 1][0] + a, dp[i - 1][1]) + b;
            }
            else
            {
                dp[i][0] = INF;
                dp[i][1] = dp[i - 1][1] + b;
            }
        cout << dp[n][0] + 1LL * n * a + 1LL * (n + 1) * b << '\n';
    }
}