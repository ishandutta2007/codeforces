#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
using namespace std;
const int N = 80 + 10;
int n, k, M;
int dp[N][N];
int fac[N], ifac[N], p2[N], und[N][N];

int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = 1ll * a * a % M) if(b & 1) c = 1ll * c * a % M;
    return c;
}

void initmath(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % M;
    ifac[n] = power(fac[n], M - 2);
    for(int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % M;
    p2[0] = 1;
    for(int i = 1; i <= n; i++) p2[i] = 2ll * p2[i - 1] % M;
    for(int i = 0; i <= n; i++) {
        und[i][0] = 1;
        for(int j = 1; j <= n; j++) und[i][j] = 1ll * und[i][j - 1] * (p2[i] - j + M) % M;
        for(int j = 0; j <= n; j++) und[i][j] = 1ll * und[i][j] * ifac[j] % M;
    }
    return;
}

int binom(int n, int m) {return n < m || m < 0 ? 0 : 1ll * fac[n] * ifac[m] % M * ifac[n - m] % M; }

void Add(int &x, int y) {if((x += y) >= M && (x -= M));}
void Sub(int &x, int y) {if((x -= y) < 0 && (x += M)); }
int main() {
    scanf("%d%d%d", &n, &k, &M);
    initmath(max(n, k));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = 1ll * power(p2[j], i) * ifac[i] % M;
            for(int pi = 0; pi <= i; pi++) {
                for(int pj = 0; pj < j; pj++) {
                    Sub(dp[i][j], 1ll * dp[pi][pj] * power(p2[pj], i - pi) % M * und[j - pj][i - pi] % M * binom(j, pj) % M);
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= k; j++) {
        Add(ans, 1ll * dp[n][j] * binom(k, j) % M);
        if(n & 1) Add(ans, 1ll * dp[n - 1][j] * (p2[k - j] - 1) % M * p2[j] % M * binom(k, j) % M);
    }
    ans = 1ll * ans * fac[n] % M;
    printf("%d\n", ans);
    return 0;
}