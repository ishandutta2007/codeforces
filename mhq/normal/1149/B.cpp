#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 100;
const int maxK = 255;
int nxt[maxN][26];
char s[maxN];
int n, q;
int dp[maxK][maxK][maxK];
int len[3];
int a[3][maxK];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 26; i++) {
        nxt[n][i] = n + 1;
        for (int j = n - 1; j >= 0; j--) {
            nxt[j][i] = nxt[j + 1][i];
            if (s[j + 1] == i + 'a') nxt[j][i] = j + 1;
        }
    }
    for (int i = 0; i < maxK; i++) {
        for (int j = 0; j < maxK; j++) {
            for (int k = 0; k < maxK; k++) {
                dp[i][j][k] = n + 1;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= q; i++) {
        char tp;
        int v;
        char c;
        cin >> tp >> v;
        v--;
        if (tp == '-') {
            len[v]--;
        }
        else {
            cin >> c;
            int sy = c - 'a';
            a[v][len[v]] = sy;
            if (v == 0) {
                len[0]++;
                for (int j = 0; j <= len[1]; j++) {
                    for (int k = 0; k <= len[2]; k++) {
                        dp[len[0]][j][k] = n + 1;
                    }
                }
                for (int j = 0; j <= len[1]; j++) {
                    for (int k = 0; k <= len[2]; k++) {
                        int pref = dp[len[0] - 1][j][k];
                     //   cout << pref << " " << nxt[pref][sy] << " " << dp[len[0] - 1][j][k] << '\n';
                        if (pref >= n) continue;
                        dp[len[0]][j][k] = min(dp[len[0]][j][k], nxt[pref][sy]);
                    }
                }
                for (int j = 0; j <= len[1]; j++) {
                    for (int k = 0; k <= len[2]; k++) {
                        int pref = dp[len[0]][j][k];
                        if (pref >= n) continue;
                        if (j + 1 <= len[1]) {
                            dp[len[0]][j + 1][k] = min(dp[len[0]][j + 1][k], nxt[pref][a[1][j]]);
                        }
                        if (k + 1 <= len[2]) {
                            dp[len[0]][j][k + 1] = min(dp[len[0]][j][k + 1], nxt[pref][a[2][k]]);
                        }
                    }
                }
            }
            else if (v == 1){
                len[1]++;
                for (int j = 0; j <= len[0]; j++) {
                    for (int k = 0; k <= len[2]; k++) {
                        dp[j][len[1]][k] = n + 1;
                    }
                }
                for (int j = 0; j <= len[0]; j++) {
                    for (int k = 0; k <= len[2]; k++) {
                        int pref = dp[j][len[1] - 1][k];
                        if (pref >= n) continue;
                        dp[j][len[1]][k] = min(dp[j][len[1]][k], nxt[pref][sy]);
                    }
                }
                for (int j = 0; j <= len[0]; j++) {
                    for (int k = 0; k <= len[2]; k++) {
                        int pref = dp[j][len[1]][k];
                        if (pref >= n) continue;
                        if (j + 1 <= len[0]) {
                            dp[j + 1][len[1]][k] = min(dp[j + 1][len[1]][k], nxt[pref][a[0][j]]);
                        }
                        if (k + 1 <= len[2]) {
                            dp[j][len[1]][k + 1] = min(dp[j][len[1]][k + 1], nxt[pref][a[2][k]]);
                        }
                    }
                }
            }
            else {
                len[2]++;
                for (int j = 0; j <= len[0]; j++) {
                    for (int k = 0; k <= len[1]; k++) {
                        dp[j][k][len[2]] = n + 1;
                    }
                }
                for (int j = 0; j <= len[0]; j++) {
                    for (int k = 0; k <= len[1]; k++) {
                        int pref = dp[j][k][len[2] - 1];
                        if (pref >= n) continue;
                        dp[j][k][len[2]] = min(dp[j][k][len[2]], nxt[pref][sy]);
                    }
                }
                for (int j = 0; j <= len[0]; j++) {
                    for (int k = 0; k <= len[1]; k++) {
                        int pref = dp[j][k][len[2]];
                        if (pref >= n) continue;
                        if (j + 1 <= len[0]) {
                            dp[j + 1][k][len[2]] = min(dp[j + 1][k][len[2]], nxt[pref][a[0][j]]);
                        }
                        if (k + 1 <= len[1]) {
                            dp[j][k + 1][len[2]] = min(dp[j][k + 1][len[2]], nxt[pref][a[1][k]]);
                        }
                    }
                }
            }
        }
        if (dp[len[0]][len[1]][len[2]] <= n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}