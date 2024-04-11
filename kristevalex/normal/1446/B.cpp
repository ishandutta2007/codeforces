#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)


long long a, b, k, n, m, tmp, ans = 0;




int main()
{
    FAST;

    cin >> n >> m;

    vector<vector<int>> dp (n+1, vector<int>(m+1, 0));

    string a, b;

    cin >> a >> b;


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i-1] == b[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);

            dp[i][j] = max(dp[i][j], dp[i][j-1] - 1);
            dp[i][j] = max(dp[i][j], dp[i-1][j] - 1);

            ans = max(ans, (long long)dp[i][j]);
        }
    }



    cout << ans;

    return 0;
}