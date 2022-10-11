#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

bool setmax(int &a, int b) {
    if (a < b) return a = b, true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    const int INF = n + 1;
    vector dp(n, array{array{-INF, -INF}, array{-INF, -INF}});
    vector par(n, array{array{array{-1, -1}, array{-1, -1}}, array{array{-1, -1}, array{-1, -1}}});
    for (int sgn : {0, 1}) {
        int cur = sgn ? a[n - 1] : -a[n - 1];
        dp[n - 1][0][sgn] = INF;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int sgn : {0, 1}) {
            int cur = sgn ? a[i] : -a[i];
            for (int prev_sgn : {0, 1}) {
                int prev = prev_sgn ? a[i + 1] : -a[i + 1];
                if (cur < prev) {
                    if (setmax(dp[i][0][sgn], dp[i + 1][0][prev_sgn])) {
                        par[i][0][sgn] = {0, prev_sgn};
                    }
                } else if (cur < dp[i + 1][0][prev_sgn]) {
                    if (setmax(dp[i][1][sgn], prev)) {
                        par[i][1][sgn] = {0, prev_sgn};
                    }
                }
                if (cur < dp[i + 1][1][prev_sgn]) {
                    if (setmax(dp[i][0][sgn], prev)) {
                        par[i][0][sgn] = {1, prev_sgn};
                    }
                } else if (cur < prev) {
                    if (setmax(dp[i][1][sgn], dp[i + 1][1][prev_sgn])) {
                        par[i][1][sgn] = {1, prev_sgn};
                    }
                }
            }
        }
    }

    for (int id : {0, 1}) {
        for (int sgn : {0, 1}) {
            if (dp[0][id][sgn] == -INF) continue;
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << (sgn ? a[i] : -a[i]) << " \n"[i == n - 1];
                int new_id = par[i][id][sgn][0];
                sgn = par[i][id][sgn][1];
                id = new_id;
            }
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}