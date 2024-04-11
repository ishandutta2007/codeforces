#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf)), pr = dp;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i > 0 && j > 0) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = max(dp[i][j], 2);
                    dp[i][j] = max(dp[i][j], pr[i - 1][j - 1] - i - j + 4);
                }
            }
            pr[i][j] = max({dp[i][j] + i + j, i > 0 ? pr[i - 1][j] : -inf, j > 0 ? pr[i][j - 1] : -inf});
        }
    }

    int res = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            res = max(res, dp[i][j]);

    cout << res << "\n";

    return 0;
}