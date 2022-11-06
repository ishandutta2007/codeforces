#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

using namespace std;

const int N = 2e3 + 3;

int up[N][N][4], dp[N][N][4];
int n, m;
char a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == a[i][j - 1])
                up[i][j][0] = up[i][j - 1][0] + 1;
            else
                up[i][j][0] = 1;

        for (int j = m; j > 0; j--)
            if (a[i][j] == a[i][j + 1])
                up[i][j][2] = up[i][j + 1][2] + 1;
            else
                up[i][j][2] = 1;
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            if (a[i][j] == a[i - 1][j])
                up[i][j][1] = up[i - 1][j][1] + 1;
            else
                up[i][j][1] = 1;

        for (int i = n; i > 0; i--)
            if (a[i][j] == a[i + 1][j])
                up[i][j][3] = up[i + 1][j][3] + 1;
            else
                up[i][j][3] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == a[i - 1][j - 1])
                dp[i][j][0] = min(dp[i - 1][j - 1][0] + 2, min(up[i][j][0], up[i][j][1]));
            else
                dp[i][j][0] = min(2ll, min(up[i][j][0], up[i][j][1]));
        for (int j = m; j > 0; j--)
            if (a[i][j] == a[i - 1][j + 1])
                dp[i][j][1] = min(dp[i - 1][j + 1][1] + 2, min(up[i][j][1], up[i][j][2]));
            else
                dp[i][j][1] = min(2ll, min(up[i][j][1], up[i][j][2]));
    }
    for (int i = n; i > 0; i--) {
        for(int j = m; j > 0; j--)
            if (a[i][j] == a[i + 1][j + 1])
                dp[i][j][2] = min(dp[i + 1][j + 1][2] + 2, min(up[i][j][2], up[i][j][3]));
            else
                dp[i][j][2] = min(2ll, min(up[i][j][2], up[i][j][3]));;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == a[i + 1][j - 1])
                dp[i][j][3] = min(dp[i + 1][j - 1][3] + 2, min(up[i][j][3], up[i][j][0]));
            else
                dp[i][j][3] = min(2ll, min(up[i][j][3], up[i][j][0]));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += min(min(dp[i][j][0], dp[i][j][1]), min(dp[i][j][2], dp[i][j][3]));//, cout << i << ' ' << j << ' ' << min(min(dp[i][j][0], dp[i][j][1]), min(dp[i][j][2], dp[i][j][3])) << ' ' << up[i][j][0] << endl;
    //cout << up[3][3][1] << ' ' << dp[3][3][0] << ' ' << dp[3][3][1] << ' ' << dp[3][3][2] << ' ' << dp[3][3][3] << endl;
    cout << ans;
    return 0;
}