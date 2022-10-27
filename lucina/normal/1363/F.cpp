#include<bits/stdc++.h>
using namespace std;
int const nax = 2048;
int const inf = 2e8;
int n;
int dp[nax][nax];
int sum_s[26][nax];
int sum_t[26][nax];
char s[nax];
char t[nax];

int rec (int x, int y) {
    if (x > y || x < 0 || y < 0) return inf;
    if (y == 0) return 0;

    if (dp[x][y] != -1) return dp[x][y];

    int &res = dp[x][y];
    res = inf;

    if (x > 0 && s[x] == t[y]) {
        res = min(res, rec(x - 1, y - 1));
    }

    if (x > 0)
        res = min(res, rec(x - 1, y) + 1);
        /// add s[x] to pending list

    int c = t[y] - 'a';
/*
    ......x[        ] <- this range
    ................y
*/

    if (sum_t[c][y] > sum_s[c][x]) {
        res = min(res, rec(x, y - 1));
    }

    return res;
}

int solve() {
    scanf("%d%s%s", &n, s + 1, t + 1);

    for (int i = 0 ; i <= n ; ++ i)
    for (int j = 0 ; j <= n ; ++ j) {
        dp[i][j] = -1;
    }

    for (int i = 0 ; i < 26 ; ++ i) {
        sum_s[i][n + 1] = sum_t[i][n + 1] = 0;
    }

    for (int i = 1 ; i <= n ; ++ i)
    for (int c = 0 ; c < 26 ; ++ c) {
        sum_s[c][i] = sum_s[c][i - 1];
        sum_t[c][i] = sum_t[c][i - 1];
        sum_s[s[i] - 'a'][i] ++ ;
        sum_t[t[i] - 'a'][i] ++ ;
    }

    for (int i = 0 ; i < 26 ; ++ i) {
        sum_s[i][n + 1] = sum_s[i][n];
        sum_t[i][n + 1] = sum_t[i][n];
    }


    for (int c = 0 ; c < 26 ; ++ c) {
        if (sum_s[c][n] != sum_t[c][n])
            return -1;
    }

    return rec(n, n);
}



int main () {

    int T;
    for (cin >> T ; T -- ; ) {
        printf("%d\n", solve());
    }
}
/*
    Good Luck
        -Lucina
*/