#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxd = 2;
const int Maxn = 1000005;

int n;
ll x, y;
int mod;
int a[Maxn];
int sum;

struct matrix {
    int m[Maxd][Maxd];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int k = 0; k < Maxd; k++)
                    c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % mod;
        return c;
    }
};

ii getVal(int fir, int sec, matrix A, ll n)
{
    matrix R(1);
    while (n) {
        if (n & 1ll) R = R * A;
        n >>= 1ll; A = A * A;
    }
    return ii((ll(R.m[0][0]) * fir + ll(R.m[0][1]) * sec) % mod,
              (ll(R.m[1][0]) * fir + ll(R.m[1][1]) * sec) % mod);
}

matrix fibMatrix()
{
    matrix R;
    R.m[0][0] = R.m[0][1] = R.m[1][0] = 1;
    return R;
}

matrix valMatrix()
{
    matrix R;
    R.m[0][0] = 3 % mod;
    R.m[0][1] = mod - 1;
    R.m[1][1] = 1;
    return R;
}

int main()
{
    scanf("%d %I64d %I64d %d", &n, &x, &y, &mod);
    int cx = getVal(1, 1, valMatrix(), x).first;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] %= mod;
        if (n == 1) { printf("%d\n", a[i]); return 0; }
        int mult = i == 0 || i == n - 1? cx: (2ll * cx + ll(mod) - 1ll) % mod;
        sum = (sum + ll(mult) * a[i]) % mod;
    }
    int cy = getVal(1, 1, valMatrix(), y).first;
    int othsum = (a[0] + getVal(a[n - 1], a[n - 2], fibMatrix(), x).first) % mod;
    int mult = (2ll * cy + ll(mod) - 1ll) % mod;
    int res = (ll(mult) * ((sum - othsum + mod) % mod) + ll(cy) * othsum) % mod;
    printf("%d\n", res);
    return 0;
}