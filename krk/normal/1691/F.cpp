#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int fac[Maxn], ifac[Maxn];
int n, k;
vector <int> neigh[Maxn];
int siz[Maxn];
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
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

void Traverse(int v, int p)
{
    siz[v] = 1;
    int sum = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        siz[v] += siz[u];
        sum = (sum + C(siz[u], k)) % mod;
    }
    res = (res + ll(n - siz[v]) * ((C(siz[v], k) - sum + mod) % mod) % mod * siz[v]) % mod;
    sum = (sum + C(n - siz[v], k)) % mod;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        sum = (sum - C(siz[u], k) + mod) % mod;
        res = (res + ll(siz[u]) * ((C(n - siz[u], k) - sum + mod) % mod) % mod * (n - siz[u])) % mod;
        sum = (sum + C(siz[u], k)) % mod;
    }
    res = (res + ll((C(n, k) - sum + mod) % mod) % mod * n) % mod;
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    printf("%d\n", res);
    return 0;
}