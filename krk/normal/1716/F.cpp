#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 2005;

int S[Maxn][Maxn];
int bigC[Maxn];
int inv[Maxn];
int fac[Maxn];
int T;
int n, m, k;
int odd[Maxn];

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
    S[0][0] = 1;
    for (int i = 1; i < Maxn; i++)
        for (int j = 0; j <= i; j++)
            S[i][j] = (S[i - 1][j - 1] + ll(j) * S[i - 1][j]) % mod;
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        inv[i] = Inv(i);
        fac[i] = ll(fac[i - 1]) * i % mod;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        bigC[0] = 1;
        for (int i = 1; i <= k; i++)
            bigC[i] = ll(bigC[i - 1]) * (n + 1 - i) % mod * inv[i] % mod;
        int o = (m + 1) / 2, a = m;
        odd[0] = 1;
        for (int i = 1; i <= k; i++)
            odd[i] = ll(odd[i - 1]) * o % mod;
        int all = toPower(m, n - 1);
        int mult = Inv(m);
        int res = 0;
        for (int i = 1; i <= k; i++) {
            res = (res + ll(bigC[i]) * fac[i] % mod * S[k][i] % mod * odd[i] % mod * all) % mod;
            all = ll(all) * mult % mod; 
        }
        printf("%d\n", res);
    }
    return 0;
}