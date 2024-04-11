#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

const int N = 501;
const int K = 11;

int dp[N][N][K];
int hor[N][N];
int ver[N][N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << " \n"[j + 1 == m];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            cin >> hor[i][j];
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ver[i][j];
        }
    }

    k /= 2;
    for (int len = 1; len <= k; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j][len] = 1e9;
                if (i) {
                    dp[i][j][len] = min(dp[i][j][len], dp[i - 1][j][len - 1] + ver[i - 1][j]);
                }
                if (j) {
                    dp[i][j][len] = min(dp[i][j][len], dp[i][j - 1][len - 1] + hor[i][j - 1]);
                }
                if (i + 1 < n) {
                    dp[i][j][len] = min(dp[i][j][len], dp[i + 1][j][len - 1] + ver[i][j]);
                }
                if (j + 1 < m) {
                    dp[i][j][len] = min(dp[i][j][len], dp[i][j + 1][len - 1] + hor[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j][k] * 2 << " \n"[j + 1 == m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}