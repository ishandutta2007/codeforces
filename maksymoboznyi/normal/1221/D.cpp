#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;

int a[N], b[N], dp[N][3], n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int k = 0; k < q; k++) {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    dp[1][0] = 0;
    dp[1][1] = b[1];
    dp[1][2] = b[1] * 2;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = 1e18 + 1;
        for (int j1 = 0; j1 < 3; j1++)
            for (int j2 = 0; j2 < 3; j2++)
                if (a[i - 1] + j1 != a[i] + j2)
                    dp[i][j2] = min(dp[i][j2], b[i] * j2 + dp[i - 1][j1]);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
    }
    return 0;
}