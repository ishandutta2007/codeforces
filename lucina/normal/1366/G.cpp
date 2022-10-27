#include<bits/stdc++.h>
using namespace std;
const int nax = 1e4 + 2;
const int inf = 1e9;
inline void upd_min (int &a, int b) {
    a = min(a, b);
}

int dp[nax][nax];
char s[nax], t[nax];
int n, m;
int match[nax];

int main () {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);

    for (int i = 0 ; i <= n ; ++ i)
    for (int j = 0 ; j <= m ; ++ j)
        dp[i][j] = inf;

    memset(match, -1, sizeof(match));
    for (int i = 1 ; i <= n ; ++ i) {
        if (s[i] == '.') continue;
        int bal = 0;
        for (int j = i ; j <= n ; ++ j) {
            bal += (s[j] == '.' ? -1 : 1);
            if (bal == 0) {
                match[i] = j;
                break;
            }
        }

    }
    dp[0][0] = 0;

    for (int i = 0 ; i <= n ; ++ i) {
        for (int j = 0 ; j <= m ; ++ j) {
            if (i > 0) upd_min(dp[i][j], dp[i - 1][j] + 1);
            if (i && j && s[i] == t[j]) upd_min(dp[i][j], dp[i - 1][j - 1]);
            if (match[i] != -1 && i > 0) upd_min(dp[match[i]][j], dp[i - 1][j]);
        }
    }

    printf("%d\n", dp[n][m]);
}