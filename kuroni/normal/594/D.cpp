#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;

const int N = 200005, Q = 200005, MX = 1000005, MOD = 1E9 + 7;

int n, q, l, r, a[N], pr[MX], ind[MX];
long long inv[MX], bit[N], ans[Q];
vector<pair<int, int>> que[N];

void init()
{
    for (int i = 2; i < MX; i++)
        if (pr[i] == 0)
            for (int j = i; j < MX; j += i)
                pr[j] = i;
    inv[1] = 1;
    for (int i = 2; i < MX; i++)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    fill(bit + 1, bit + n + 1, 1);
    fill(ind + 2, ind + MX, N);
}

void upd(int u, long long v)
{
    for (; u <= n; u += u & -u)
        (bit[u] *= v) %= MOD;
}

long long get(int u)
{
    long long ret = 1;
    for (; u > 0; u -= u & -u)
        (ret *= bit[u]) %= MOD;
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &l, &r);
        que[l].push_back(mp(r, i));
    }
    init();
    for (int i = n; i >= 1; i--)
    {
        upd(i, a[i]);
        while (a[i] != 1)
        {
            int u = pr[a[i]];
            upd(ind[u], inv[u - 1] * u % MOD);
            upd(ind[u] = i, (u - 1) * inv[u] % MOD);
            while (a[i] % u == 0)
                a[i] /= u;
        }
        for (pair<int, int> &v : que[i])
            ans[v.second] = get(v.first);
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
}