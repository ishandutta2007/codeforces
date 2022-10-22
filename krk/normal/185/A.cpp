#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;
const int Maxn = 2;

struct matrix {
    ll m[Maxn][Maxn];
    matrix() { fill((ll*)m, (ll*)m + Maxn * Maxn, 0LL); }
};

ll n;
matrix M, E;

matrix Mult(const matrix &A, const matrix &B)
{
    matrix C;
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++)
            for (int l = 0; l < Maxn; l++)
                C.m[i][j] = (C.m[i][j] + A.m[i][l] * B.m[l][j] % mod) % mod;
    return C;
}

matrix toPower(ll p)
{
    if (p == 0) return E;
    matrix tmp = toPower(p / 2LL);
    tmp = Mult(tmp, tmp);
    if (p % 2LL) return Mult(tmp, M);
    return tmp;
}

int main()
{
    M.m[0][0] = 2; M.m[0][1] = 1;
    M.m[1][0] = 0; M.m[1][1] = 4;
    E.m[0][0] = 1; E.m[0][1] = 0;
    E.m[1][0] = 0; E.m[1][1] = 1;
    scanf("%I64d", &n);
    M = toPower(n);
    printf("%I64d\n", (M.m[0][0] + M.m[0][1]) % mod);
    return 0;
}