#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 5005;

int C[Maxn][Maxn];
int n, m, k;
int hm[Maxn];
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

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %d %d", &n, &m, &k);
    int p = Inv(m);
    int mult = 1;
    for (int i = 1; i <= k; i++) {
        hm[i] = toPower(i, k);
        for (int j = 1; j < i; j++)
            hm[i] = (hm[i] - ll(hm[j]) * C[i][j] % mod + mod) % mod;
        mult = ll(mult) * (n + 1 - i) % mod * Inv(i) % mod;
        res = (res + ll(mult) * hm[i] % mod * toPower(p, i)) % mod;
    }
    printf("%d\n", res);
    return 0;
}