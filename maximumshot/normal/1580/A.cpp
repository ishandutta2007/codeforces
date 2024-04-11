#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) dp[i][j] = dp[i - 1][j];
                if (a[i][j] == '1') dp[i][j]++;
            }
        }
        vector<int> f(m), g(m);
        int res = inf;
        for (int i = 0; i < n; i++) {
            for (int j = i + 5 - 1; j < n; j++) {
                for (int p = 0; p < m; p++) {
                    f[p] = 0;
                    if (a[i][p] == '0') f[p]++;
                    if (a[j][p] == '0') f[p]++;
                    f[p] += dp[j - 1][p] - dp[i][p];
                    if (p > 0) f[p] += f[p - 1];

                    g[p] = dp[j - 1][p] - dp[i][p];
                    g[p] = j - i - 1 - g[p];
                }
                int mn = inf;
                for (int q = 0; q < m; q++) {
                    if (q >= 3) mn = min(mn, g[q - 3] - f[q - 3]);
                    if (q > 0)
                        res = min(res, mn + f[q - 1] + g[q]);
                }
            };
        }
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}