#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
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
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int N = 10;
    vector<vector<int>> h(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> h[i][j];
        }
    }
    vector<vector<double>> dp(N, vector<double>(N));
    for (int j = 1; j < 6; j++) {
        dp[0][j] = 6;
    }
    for (int i = 0; i < N; i++) {
        if (i % 2) { 
            for (int j = N - 1; j >= 0; j--) {
                for (int k = 1; k <= 6; k++) {
                    int x = i - (j + k >= N);
                    int y = (j + k >= N ? N - 1 - (j + k - N) : j + k);
                    dp[i][j] += min(dp[x][y], dp[x - h[x][y]][y]) + 1;
                }
                dp[i][j] /= 6;
            }
            continue;
        }
        for (int j = 0; j < N; j++) {
            if (i == 0 && j < 6) continue;
            for (int k = 1; k <= 6; k++) {
                int x = i - (j - k < 0);
                int y = (j - k < 0 ? -(j - k + 1) : j - k);
                dp[i][j] += min(dp[x][y], dp[x - h[x][y]][y]) + 1;
            }
            dp[i][j] /= 6;
        }
    }
    cout << fixed << setprecision(25) << dp[N - 1][0] << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}