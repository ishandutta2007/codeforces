#include<bits/stdc++.h>
using namespace std;
int const nax = 3000 + 10, mod = 998244353;

void plusle (int &a, int b) {
    if (( a += b) >= mod ) a -= mod ;
}
void minun (int &a, int b) {
    if ((a -= b) < 0) a += mod ;
}
int add (int a, int b) {
    return (( a += b ) >= mod ) ? a - mod  : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + mod : a;
}

int dp[nax][nax], n, m;

char s[nax], t[nax];


int rec (int l, int r) {

    if (l > n || r > n || l > r) return 0;

    if (dp[l][r] != -1) return dp[l][r];
    int &res = dp[l][r];


    if (l > r) return 0;


    res = 0;

    if (l == r) {
        if (l > m || (l <= m && t[l] == s[1])) return res = 2;
        else return res = 0;
    }

    int has = r - l + 1;

    if ((l > m) || (l <= m && t[l] == s[has])) {
        plusle(res, rec(l + 1, r));
    }

    if (( r > m) || (r <= m && t[r] == s[has])) {
        plusle(res, rec(l, r - 1));
    }


   // printf("l r res %d %d %d\n", l, r, res);

    return res;
}

int main () {
    scanf("%s", s + 1);
    scanf("%s", t + 1);

    n = strlen(s + 1);
    m = strlen(t + 1);

    memset(dp, -1, sizeof(dp));

    rec(1, n);

    int ans = 0;

    for (int i = m ; i <= n ; ++ i) {
        plusle(ans, dp[1][i]);
    }

    printf("%d\n", ans);

}
/*
    Good Luck
        -Lucina
*/