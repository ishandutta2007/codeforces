#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 255;
const int Maxm = Maxn * Maxn;

int n, k;
int C[Maxn][Maxn];
int all[Maxm], ball[Maxm];
int res;

int getWays(int r, int c)
{
    int normal = (n - r) * (n - c);
    return ll(C[n][r]) * C[n][c] % mod * all[normal] % mod * ball[n * n - normal] % mod;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    all[0] = ball[0] = 1;
    for (int i = 1; i < Maxm; i++) {
        all[i] = ll(all[i - 1]) * k % mod;
        ball[i] = ll(ball[i - 1]) * (k - 1) % mod;
    }
    for (int i = 0; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j <= n; j++)
            if (j % 2 == 0) ans = (ans + getWays(i, j)) % mod;
            else ans = (ans - getWays(i, j) + mod) % mod;
        if (i % 2 == 0) res = (res + ans) % mod;
        else res = (res - ans + mod) % mod;
    }
    printf("%d\n", res);
    return 0;
}