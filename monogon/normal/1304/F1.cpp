
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 55, M = 2e4 + 5;
int n, m, k, a[N][M];
ll dp[N][M], pref[N][M], prefmax[M], suffmax[M];

int range(int i, int j) {
    return pref[i][j + k - 1] - pref[i][j - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }
    for(int i = 2; i <= n + 1; i++) {
        for(int j = 1; j <= m - k + 1; j++) {
            prefmax[j] = max(prefmax[j - 1], range(i - 1, j) + range(i, j) + dp[i - 1][j]);
        }
        for(int j = m - k + 1; j >= 1; j--) {
            suffmax[j] = max(suffmax[j + 1], range(i - 1, j) + range(i, j) + dp[i - 1][j]);
        }
        for(int j = 1; j <= m - k + 1; j++) {
            dp[i][j] = max(prefmax[max(0, j - k)], suffmax[min(j + k, m - k + 2)]);
            for(int l = 0; l < k && j + l <= m - k + 1; l++) {
                dp[i][j] = max(dp[i][j], range(i - 1, j + l) + pref[i][j + l + k - 1] - pref[i][j + k - 1] + dp[i - 1][j + l]);
            }
            for(int l = -1; l > -k && j + l >= 1; l--) {
                dp[i][j] = max(dp[i][j], range(i - 1, j + l) + pref[i][j - 1] - pref[i][j + l - 1] + dp[i - 1][j + l]);
            }
        }
    }
    cout << dp[n + 1][1] << endl;
}