#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 998244353;

int n;
int p[Maxn], notp[Maxn];
int scc[Maxn];
int sep[Maxn][Maxn];
int res[Maxn], tmp[Maxn];

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
    scanf("%d", &n);
    int a, b; scanf("%d %d", &a, &b);
    p[0] = notp[0] = 1;
    p[1] = ll(a) * Inv(b) % mod;
    notp[1] = (1 - p[1] + mod) % mod;
    for (int i = 2; i < Maxn; i++) {
        p[i] = ll(p[i - 1]) * p[1] % mod;
        notp[i] = ll(notp[i - 1]) * notp[1] % mod;
    }
    sep[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int los = 0; los <= i; los++) {
            int win = i - los;
            // more winners
            sep[i + 1][los] = (sep[i + 1][los] + ll(sep[i][los]) * p[los]) % mod;
            // more losers
            sep[i + 1][los + 1] = (sep[i + 1][los + 1] + ll(sep[i][los]) * notp[win]) % mod;
        }
    scc[1] = 1;
    for (int i = 2; i <= n; i++) {
        scc[i] = 1;
        for (int j = 1; j < i; j++) {
            sep[i][j] = ll(sep[i][j]) * scc[j] % mod;
            scc[i] = (scc[i] - sep[i][j] + mod) % mod;
        }
    }
    tmp[1] = res[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++)
            tmp[i] = (tmp[i] + ll(sep[i][j]) * (tmp[i - j] + res[j])) % mod;
        res[i] = (ll(i) * (i - 1) / 2 % mod + ll(tmp[i])) * Inv((1 - scc[i] + mod) % mod) % mod;
        tmp[i] = (tmp[i] + ll(scc[i]) * res[i]) % mod;
    }
    printf("%d\n", res[n]);
    return 0;
}