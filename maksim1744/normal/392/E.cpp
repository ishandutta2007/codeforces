#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    v.insert(v.begin(), 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            v[i] = max(v[i], v[j] + v[i - j]);
        }
    }

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    auto getv = [&](int ln) {
        if (ln < v.size()) return v[ln];
        return -inf;
    };

    vector<vector<ll>> dp_all(n, vector<ll>(n, -inf));
    vector<vector<ll>> dp_mon(n, vector<ll>(n, -inf));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp_mon[i][i] = 0;
        dp_all[i][i] = v[1];
        if (i != 0)
            dp_all[i][i - 1] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int l = 0; l < n; ++l) {
            int r = l + k - 1;
            if (r >= n) break;

            for (int j = l + 1; j <= r; ++j) {
                dp_all[l][r] = max(dp_all[l][r], dp_all[l][j - 1] + dp_all[j][r]);
            }

            if (w[l] != w[r]) {
                if (abs(w[l] - w[r]) == 1) {
                    dp_mon[l][r] = dp_all[l + 1][r - 1];
                } else {
                    for (int j = l + 1; j < r; ++j) {
                        if (w[l] != w[j] && w[r] != w[j] && ((w[l] < w[j]) == (w[j] < w[r]))) {
                            dp_mon[l][r] = max(dp_mon[l][r], dp_mon[l][j] + dp_mon[j][r]);
                        }
                    }
                }
            }

            for (int j = l; j <= r; ++j)
                if (w[j] >= w[l] && w[j] >= w[r])
                    dp_all[l][r] = max(dp_all[l][r], dp_mon[l][j] + dp_mon[j][r] + getv(abs(w[l] - w[j]) + abs(w[j] - w[r]) + 1));

            dp[l][r] = max(dp[l][r], dp_all[l][r]);
            for (int j = l + 1; j <= r; ++j)
                dp[l][r] = max(dp[l][r], dp[l][j - 1] + dp[j][r]);
        }
    }


    cout << dp[0][n - 1] << '\n';

    return 0;
}