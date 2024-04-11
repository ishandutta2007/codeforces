#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 60;
const int Maxn = 1005;
const int mod = 1000000007;

int C[Maxn][Maxn];
map <ll, int> M[Maxb];
int n;
ll l, r, z;

int Get(int b, ll lim)
{
    if (b < 0) return 1;
    if ((1ll << ll(b + 1)) - 1ll <= lim / n)
        lim = ((1ll << ll(b + 1)) - 1ll) * n;
    auto it = M[b].find(lim);
    if (it == M[b].end()) {
        int ways = 0;
        for (int i = bool(z & 1ll << ll(b)); i <= n && ll(i) * (1ll << ll(b)) <= lim; i += 2)
            ways = (ways + ll(C[n][i]) * Get(b - 1, lim - ll(i) * (1ll << ll(b)))) % mod;
        M[b].insert(make_pair(lim, ways));
        return ways;
    }
    return it->second;
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %I64d %I64d %I64d", &n, &l, &r, &z);
    int res = (Get(Maxb - 1, r) - Get(Maxb - 1, l - 1) + mod) % mod;
    printf("%d\n", res);
    return 0;
}