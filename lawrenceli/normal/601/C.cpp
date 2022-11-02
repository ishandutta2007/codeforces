#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long double ld;

const int maxn = 105;
const int maxm = 1005;

int n, m, x[maxn];
ld dp[maxn * maxm][2], p[maxn * maxm];

int main() {
    cin >> n >> m;

    if (m == 1) {
        cout << "1\n";
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n * m; j++)
            p[j+1] = p[j] + dp[j][0];

        for (int j = 0; j <= n * m; j++) {
            dp[j][1] = (p[j] - p[max(0, j - m)]);
            if (j - x[i] >= 0) dp[j][1] -= dp[j - x[i]][0];
            dp[j][1] /= m - 1;
        }

        for (int j = 0; j <= n * m; j++)
            dp[j][0] = dp[j][1];

        //for (int j = 0; j <= 5; j++) cout << dp[j][0] << ' ';
        //cout << endl;
    }

    ld ans = 1;
    for (int i = 0; i < sum; i++)
        ans += dp[i][0] * (m - 1);

    cout << fixed << setprecision(15) << ans << '\n';
}