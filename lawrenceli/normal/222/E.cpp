#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

const int MAXM = 55;
const int MAXL = 55;
const int MOD = 1e9 + 7;

int m, k, b[MAXM][MAXM], dp[MAXM][MAXM][MAXL], tmp[MAXM][MAXM], ans;
ll n;

void dfs(int cur, ll len) {
    if (len == 1) {
        for (int i=0; i<m; i++) dp[i][i][cur] = 1;
    } else {
        if (len%2) {
            dfs(cur + 1, (len + 1) / 2);
            for (int i=0; i<m; i++) {
                for (int j=0; j<m; j++) {
                    for (int k=0; k<m; k++) {
                        dp[i][j][cur] = (dp[i][j][cur] + ll(dp[i][k][cur+1]) * dp[k][j][cur+1]) % MOD;
                    }
                }
            }
        } else {
            dfs(cur + 1, len / 2);
            for (int i=0; i<m; i++) {
                for (int j=0; j<m; j++) {
                    for (int k=0; k<m; k++) {
                        dp[i][j][cur] = (dp[i][j][cur] + ll(dp[i][k][cur+1]) * dp[k][j][cur+1]) % MOD;
                    }
                }
            }
            for (int i=0; i<m; i++) {
                for (int j=0; j<m; j++) {
                    tmp[i][j] = dp[i][j][cur]; dp[i][j][cur] = 0;
                }
            }
            for (int i=0; i<m; i++) {
                for (int j=0; j<m; j++) {
                    for (int k=0; k<m; k++) {
                        dp[i][k][cur] = (dp[i][k][cur] + ll(tmp[i][j]) * b[j][k]) % MOD;
                    }
                }
            }
        }
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%I64d %d %d\n", &n, &m, &k);
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            b[i][j] = 1;
        }
    }
    for (int i=0; i<k; i++) {
        char c1, c2;
        int x, y;
        scanf("%c%c\n", &c1, &c2);
        if (c1 >= 'a') x = c1 - 'a';
        else x = c1 - 'A' + 26;
        if (c2 >= 'a') y = c2 - 'a';
        else y = c2 - 'A' + 26;
        b[x][y] = 0;
    }
    dfs(0, n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            ans = (ans + dp[i][j][0]) % MOD;
        }
    }
    printf("%d\n", ans);
}