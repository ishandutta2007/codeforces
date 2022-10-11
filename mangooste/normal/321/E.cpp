#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e8;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    cin >> ws;
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        for (int j = 1; j <= n; j++) {
            g[i][j] = (int) (s[2 * (j - 1)] - '0');
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + g[i][j];
        }
    }
    auto getSum = [&](int x1, int y1, int x2, int y2) {
        x1--, y1--;
        return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
    };

    vector<vector<int>> seg(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            seg[i][j] = getSum(i, i, j, j) / 2;
        }
    }

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    vector<int> nDp(n + 1);

    for (int i = 0; i < k; i++) {
        function<void(int, int, int, int)> calcDp = [&](int l, int r, int validL, int validR) {
            if (l >= r) {
                return;
            }
            if (l + 1 == r && l < 1) {
                nDp[l] = INF;
                return;
            }

            int m = (l + r) / 2;
            assert(validL <= validR && validL < m);

            int optimalPos = validL;
            int optimalSum = dp[validL] + seg[validL + 1][m];
            for (int i = validL + 1; i <= validR && i < m; i++) {
                int curSum = dp[i] + seg[i + 1][m];
                if (curSum < optimalSum) {
                    optimalSum = curSum;
                    optimalPos = i;
                }
            }

            nDp[m] = optimalSum;

            calcDp(l, m, validL, optimalPos);
            calcDp(m + 1, r, optimalPos, validR);
        };

        calcDp(0, n + 1, 0, n);
        swap(dp, nDp);
        for (auto &x : dp) {
            x = min(x, INF);
        }
    }

    cout << dp.back() << '\n';
}