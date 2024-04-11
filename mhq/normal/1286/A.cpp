#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 105;
int cnt[2];
int p[maxN];
int dp[maxN][maxN][maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cnt[0] = n / 2;
    cnt[1] = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != 0) {
            cnt[p[i] % 2]--;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                for (int c = 0; c < 2; c++) {
                    dp[i][j][k][c] = 1e9;
                }
            }
        }
    }
    if (p[1] != 0) {
        dp[1][0][0][p[1] % 2] = 0;
    }
    else {
        if (cnt[0]) {
            dp[1][1][0][0] = 0;
        }
        if (cnt[1]) {
            dp[1][0][1][1] = 0;
        }
    }
    for (int i = 1; i + 1 <= n; i++) {
        for (int f = 0; f <= cnt[0]; f++) {
            for (int k = 0; k <= cnt[1]; k++) {
                for (int l = 0; l < 2; l++) {
                    if (p[i + 1]) {
                        dp[i + 1][f][k][p[i + 1] % 2] = min(dp[i + 1][f][k][p[i + 1] % 2], dp[i][f][k][l] + ((l % 2) != (p[i + 1] % 2)));
                    }
                    else {
                        for (int r = 0; r < 2; r++) {
                            if (r == 0) {
                                if (f < cnt[0]) {
                                    dp[i + 1][f + 1][k][r] = min(dp[i + 1][f + 1][k][r], dp[i][f][k][l] + (l != r));
                                }
                            }
                            else {
                                if (k < cnt[1]) {
                                    dp[i + 1][f][k + 1][r] = min(dp[i + 1][f][k + 1][r], dp[i][f][k][l] + (l != r));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << min(dp[n][cnt[0]][cnt[1]][0], dp[n][cnt[0]][cnt[1]][1]);
    return 0;
}