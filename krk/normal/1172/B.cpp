#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int fac[Maxn];
int n;
vector <int> neigh[Maxn];
int siz[Maxn];
int res = 1;

void Traverse1(int v, int p = 0)
{
    siz[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        siz[v] += siz[u];
    }
    int ch = int(neigh[v].size()) - (p != 0);
    if (v == 1) res = ll(res) * siz[v] % mod * fac[ch] % mod;
    else res = ll(res) * fac[ch + 1] % mod;
}

int main()
{
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = ll(fac[i - 1]) * i % mod;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse1(1);
    printf("%d\n", res);
    return 0;
}