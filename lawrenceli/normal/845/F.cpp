#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, m;
char mat[255][255], mat2[255][255];
int dp[16][1<<15][2][2];

void add(int& a, int b) { a = (a + b) % mod; }

int main() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s\n", &mat2[i]);

    if (n > m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = mat2[i][j];
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[j][i] = mat2[i][j];
        swap(n, m);
    }

    assert(m <= 15);

    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            for (int t = 0; t < 1 << m; t++)
                for (int b1 = 0; b1 < 2; b1++)
                    for (int b2 = 0; b2 < 2; b2++) {
                        int v = dp[j][t][b1][b2];
                        if (!v) continue;
                        if (mat[i][j] == 'x') {
                            add(dp[j + 1][t & ~(1 << j)][0][b2], v);
                        } else if (t & 1 << j) {
                            add(dp[j + 1][t][b1][b2], v);
                            add(dp[j + 1][t][1][b2], v);
                        } else if (b1) {
                            add(dp[j + 1][t][b1][b2], v);
                            add(dp[j + 1][t | 1 << j][1][b2], v);
                        } else {
                            if (!b2) add(dp[j + 1][t][b1][1], v);
                            add(dp[j + 1][t | 1 << j][1][b2], v);
                        }
                    }

        for (int j = 0; j < m; j++) for (int t = 0; t < 1 << m; t++) for (int b1 = 0; b1 < 2; b1++) for (int b2 = 0; b2 < 2; b2++) dp[j][t][b1][b2] = 0;
        for (int t = 0; t < 1 << m; t++) for (int b2 = 0; b2 < 2; b2++) dp[0][t][0][b2] = (dp[m][t][0][b2] + dp[m][t][1][b2]) % mod;
        for (int t = 0; t < 1 << m; t++) for (int b1 = 0; b1 < 2; b1++) for (int b2 = 0; b2 < 2; b2++) dp[m][t][b1][b2] = 0;
    }

    int ans = 0;
    for (int t = 0; t < (1 << m); t++) for (int b2 = 0; b2 < 2; b2++) add(ans, dp[0][t][0][b2]);
    printf("%d\n", ans);
}