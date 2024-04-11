#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int mod = 1000000007;

int n, k;
int a[Maxn];

struct matrix {
    int m[Maxn][Maxn];
    matrix(int diag = 0) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &b) const {
        matrix c;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int l = 0; l <= n; l++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][l]) * b.m[l][j]) % mod;
        return c;
    }
};

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
    scanf("%d %d", &n, &k);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ones += a[i] == 1;
    }
    int zers = n - ones;
    int x = 0;
    for (int i = 0; i < zers; i++)
        x += a[i] == 1;
    matrix R(1), A;
    int all = Inv(ll(n) * (n - 1) / 2);
    for (int i = 0; i <= n; i++) {
        int c = i;
        int d = zers - c;
        int e = ones - c;
        int f = ones - e;
        int inc = ll(d) * e % mod * all % mod;
        int dec = ll(c) * f % mod * all % mod;
        int stay = (1 - inc + mod) % mod;
        stay = (stay - dec + mod) % mod;
        if (inc) A.m[i + 1][i] = inc;
        if (dec) A.m[i - 1][i] = dec;
        A.m[i][i] = stay;
    }
    while (k) {
        if (k & 1) R = R * A;
        k >>= 1; A = A * A;
    }
    printf("%d\n", R.m[0][x]);
    return 0;
}