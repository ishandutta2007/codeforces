#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 101;

int n, m, dp1[N][N], dp2[N][N], a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int ans = 5e18;
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= m; y++) {

                dp2[x][y] = 0;
                for (int i = x; i <= n; i++)
                    for (int j = y; j <= m; j++) if (i != x || j != y){
                        int need = (i - x) + (j - y) + a[x][y];
                        if (need > a[i][j]) {
                            dp2[i][j] = 5e18;
                            continue;
                        }
                        dp2[i][j] = 5e18;
                        if (i != x)
                            dp2[i][j] = min(dp2[i][j], dp2[i - 1][j]);
                        if (j != y)
                            dp2[i][j] = min(dp2[i][j], dp2[i][j - 1]);
                        if (dp2[i][j] != 5e18)
                            dp2[i][j] += (a[i][j] - need);
                    }

                dp1[x][y] = 0;
                for (int i = x; i > 0; i--)
                    for (int j = y; j > 0; j--) if (i != x || j != y) {
                        int need = a[x][y] - ((x - i) + (y - j));
                        if (need > a[i][j]) {
                            dp1[i][j] = 5e18;
                            continue;
                        }
                        dp1[i][j] = 5e18;
                        if (i != x)
                            dp1[i][j] = min(dp1[i][j], dp1[i + 1][j]);
                        if (j != y)
                            dp1[i][j] = min(dp1[i][j], dp1[i][j + 1]);
                        if (dp1[i][j] != 5e18)
                            dp1[i][j] += (a[i][j] - need);
                    }
                if (dp1[1][1] != 5e18 && dp2[n][m] != 5e18)
                    ans = min(ans, dp1[1][1] + dp2[n][m]);//, cout << x << ' ' << y << ' ' << dp1[1][2] << endl;
            }
        cout << ans << "\n";
    }
    return 0;
}