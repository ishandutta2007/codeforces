#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct data {
    int a, b, c;
    data() {}
    data(int a, int b, int c) : a(a), b(b), c(c) {}
};

const int MAXN = 105;
const int INF = 1e9;

char s1[MAXN], s2[MAXN], vir[MAXN], sub[MAXN];
int n, m, v, dp[MAXN][MAXN][MAXN], p[MAXN], cnt;
data par[MAXN][MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%s\n%s\n%s", s1, s2, vir);
    n = strlen(s1); m = strlen(s2); v = strlen(vir);
    p[0] = 0;
    for (int i=1; i<v; i++) {
        int k = p[i-1];
        while (k > 0 && vir[k] != vir[i]) k = p[k-1];
        if (vir[k] == vir[i]) k++;
        p[i] = k;
    }
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<MAXN; k++)
                dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    for (int sum=0; sum <= n+m; sum++) {
        for (int i=0; i<=min(n, sum); i++) {
            int j = sum - i;
            if (j > m) continue;
            for (int k=0; k<v; k++) {
                if (dp[i][j][k] > dp[i+1][j][k]) {
                    dp[i+1][j][k] = dp[i][j][k];
                    par[i+1][j][k] = data(i, j, k);
                }
                if (dp[i][j][k] > dp[i][j+1][k]) {
                    dp[i][j+1][k] = dp[i][j][k];
                    par[i][j+1][k] = data(i, j, k);
                }
                if (s1[i] == s2[j]) {
                    int l = k;
                    while (l > 0 && s1[i] != vir[l]) l = p[l-1];
                    if (s1[i] == vir[l]) l++;
                    if (dp[i][j][k] + 1 > dp[i+1][j+1][l]) {
                        dp[i+1][j+1][l] = dp[i][j][k] + 1;
                        par[i+1][j+1][l] = data(i, j, k);
                    }
                }
            }
        }
    }
    int a = n, b = m, c, ans = 0;
    for (int i=0; i<v; i++) {
        if (dp[n][m][i] > ans) {
            ans = dp[n][m][i];
            c = i;
        }
    }
    if (ans == 0) {
        printf("0\n");
        return 0;
    }
    while (ans > 0) {
        data d = par[a][b][c];
        if (dp[d.a][d.b][d.c] < dp[a][b][c]) {
            sub[cnt++] = s1[a-1];
            ans--;
        }
        a = d.a, b = d.b, c = d.c;
    }
    for (int i=cnt-1; i>=0; i--) printf("%c", sub[i]);
    printf("\n");
    return 0;
}