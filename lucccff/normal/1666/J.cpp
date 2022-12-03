#include<bits/stdc++.h>
const int N = 2e2 + 10;
int ri() {
    char ch = getchar(); int x = 0, f = 1;
    for(;ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}
int n;
long long c[N][N];
long long f[N][N];
long long dp[N][N];
int gen[N][N];
long long Solve(int L, int R) {
    if(L >= R) return 0;
    if(gen[L][R])
        return dp[L][R];
    for(int k = L;k <= R; ++k) {
        long long ans = Solve(L, k - 1) + Solve(k + 1, R) + f[L][k - 1] + f[k + 1][R];
        if(!gen[L][R] || ans < dp[L][R]) {
            dp[L][R] = ans;
            gen[L][R] = k;
        }
    }
    return dp[L][R];
}
int p[N];
void GetT(int L, int R, int u) {
    if(L > R) return ;
    if(L == R) {
        p[L] = u;
        return ;
    }
    int x = gen[L][R];
    p[x] = u;
    GetT(L, x - 1, x);
    GetT(x + 1, R, x);
}
int main() {
    n = ri();
    for(int i = 1;i <= n; ++i)
        for(int j = 1;j <= n; ++j) {
            c[i][j] = ri();
            c[i][j] += c[i][j - 1];
        }
    for(int L = 1;L <= n; ++L)
        for(int R = L;R <= n; ++R)
            for(int k = L; k <= R; ++k)
                f[L][R] += c[k][n] - (c[k][R] - c[k][L - 1]);
    Solve(1, n);
    GetT(1, n, 0);
    for(int i = 1;i <= n; ++i)
        printf("%d ", p[i]);
    puts("");
    return 0;
}