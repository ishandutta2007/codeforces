#include <bits/stdc++.h>
using namespace std;

const int mod = 31607;
const int Maxn = 21;

int bits[1 << Maxn], lst[1 << Maxn];
int n;
int A[Maxn][Maxn];
int C[Maxn], col[1 << Maxn];
int row[Maxn][1 << Maxn];
int all;
int dp[2];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1; a = a * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    for (int i = 1; i < 1 << Maxn; i++) {
        bits[i] = __builtin_popcount(i);
        lst[i] = bits[(i & -i) - 1];
    }
    int inv10000 = Inv(10000);
    scanf("%d", &n);
    fill(C, C + n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            A[i][j] = A[i][j] * inv10000 % mod;
            C[j] = C[j] * A[i][j] % mod;
        }
        row[i][0] = 1;
        for (int j = 1; j < 1 << n; j++) {
            int l = lst[j];
            row[i][j] = row[i][j ^ (1 << l)] * A[i][l] % mod;
        }
    }
    col[0] = 1;
    for (int i = 1; i < 1 << n; i++) {
        int l = lst[i];
        col[i] = col[i ^ (1 << l)] * C[l] % mod;
    }
    all = (1 << n) - 1;
    for (int i = 0; i < 1 << n; i++)
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++) {
                dp[0] = dp[1] = 0;
                dp[(bits[i] + a + b) % 2] = col[i];
                for (int z = 0; z < n; z++) {
                    int tk = i;
                    int mult = 1;
                    if (a && !(tk & 1 << z)) {
                        mult = mult * A[z][z] % mod;
                        tk |= 1 << z;
                    }
                    if (b && !(tk & 1 << (n - 1 - z))) {
                        mult = mult * A[z][n - 1 - z] % mod;
                        tk |= 1 << (n - 1 - z);
                    }
                    int ndp0 = (dp[0] + dp[1] * row[z][all ^ tk]) % mod;
                    int ndp1 = (dp[0] * row[z][all ^ tk] + dp[1]) % mod;
                    dp[0] = ndp0 * mult % mod;
                    dp[1] = ndp1 * mult % mod;
                }
                res = (res - dp[1] + mod) % mod;
                res = (res + dp[0]) % mod;
            }
    res = (1 - res + mod) % mod;
    printf("%d\n", res);
    return 0;
}