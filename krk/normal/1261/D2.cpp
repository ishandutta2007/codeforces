#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n, k;
int h[Maxn];
int A, B;
int fac[Maxn], inv[Maxn];
int pw2[Maxn], pwk[Maxn];
int inv2;
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

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int Solve(int n)
{
    int tot = pw2[n];
    if (n % 2 == 0)
        tot = (tot - C(n, n / 2) + mod) % mod;
    tot = ll(tot) * inv2 % mod;
    return ll(tot) * C(A, n) % mod * pwk[A - n] % mod;
}

int main()
{
    scanf("%d %d", &n, &k);
    if (k == 1) { printf("0\n"); return 0; }
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    fac[0] = inv[0] = pw2[0] = pwk[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
        pw2[i] = 2ll * pw2[i - 1] % mod;
        pwk[i] = ll(k - 2) * pwk[i - 1] % mod;
    }
    inv2 = Inv(2);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        if (h[i] == h[ni]) B++;
        else A++;
    }
    if (k == 2) res = Solve(A);
    else for (int i = 1; i <= A; i++)
            res = (res + Solve(i)) % mod;
    res = ll(res) * toPower(k, B) % mod;
    printf("%d\n", res);
    return 0;
}