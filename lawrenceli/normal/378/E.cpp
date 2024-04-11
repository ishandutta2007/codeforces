#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const int inf = 1e9 + 5;

int n, m, s[maxn];
int dp[21][1<<20];
bool qa[maxn], qb[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
    scanf("%d\n", &m);
    sort(s, s + n); reverse(s, s + n);

    for (int i = 0; i < m; i++) {
        char c; int x;
        scanf("%c %d\n", &c, &x);
        qa[i] = (c == 'p');
        qb[i] = x - 1;
    }

    for (int i = m - 1; i >= 0; i--)
        for (int j = 0; j < 1<<m; j++) {
            int& ret = dp[i][j];
            if (qb[i]) ret = 1e9;
            else ret = -1e9;

            if (!qa[i]) ret = dp[i + 1][j];

            for (int k = 0; k < m; k++)
                if (j & 1<<k) {
                    int add = int(qa[i]) * (qb[i] ? -1 : 1) * s[k];
                    if (qb[i]) ret = min(ret, add + dp[i + 1][j ^ 1<<k]);
                    else ret = max(ret, add + dp[i + 1][j ^ 1<<k]);
                }
        }

    printf("%d\n", dp[0][(1<<m) - 1]);
}