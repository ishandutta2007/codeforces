#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 250005;
const int Maxm = 20;
const int Maxb = 17;

int n, k, mod;
int mx[1 << Maxb];
int fac[Maxn], inv[Maxn];
int dp[Maxm][1 << Maxb];
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

void Add(int i, int rem, int my, int his)
{
    if (rem == 0)
        dp[i + 1][my ^ his] = (dp[i + 1][my ^ his] + ll(dp[i][my]) * C(2 * my, 2 * his)) % mod;
    else {
        int b = mx[rem];
        Add(i, (rem ^ (1 << b)), (my ^ (1 << b)), his);
        Add(i, (rem ^ (1 << b)), (my ^ (1 << b)), (his ^ (1 << b)));
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &mod);
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    for (int i = 1; i < 1 << Maxb; i++) {
        int b = Maxb - 1;
        while (!(i & 1 << b)) b--;
        mx[i] = b;
    }
    res = toPower(k, n);
    if (n % 2) {
        printf("%d\n", res);
        return 0;
    }
    dp[0][n / 2] = 1;
    for (int i = 0; i + 1 < Maxm; i++) {
        if (dp[i][0])
            res = (res - ll(C(k, i)) * fac[i] % mod * dp[i][0] % mod + mod) % mod;
        for (int j = 1; j < 1 << Maxb; j++) if (dp[i][j]) {
            int b = mx[j];
            Add(i, (j ^ (1 << b)), (1 << b), (1 << b));
        }
    }
    printf("%d\n", res);
    return 0;
}