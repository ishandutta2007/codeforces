#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxp = 31595;
const int Maxk = 105;

struct matrix {
    int m[Maxk][Maxk];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxk; i++)
            for (int j = 0; j < Maxk; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator*(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxk; i++)
            for (int j = 0; j < Maxk; j++)
                for (int k = 0; k < Maxk; k++)
                    c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % (mod - 1);
        return c;
    }
};

int k;
int b[Maxk];
int n, m;
int root = 3;
int root_inv;
map <int, int> M;

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

int getX(int ind)
{
    matrix R(1), A;
    for (int j = 1; j <= k; j++)
        A.m[0][j - 1] = b[j];
    for (int i = 1; i < k; i++)
        A.m[i][i - 1] = 1;
    ind -= k;
    while (ind) {
        if (ind & 1) R = R * A;
        ind >>= 1; A = A * A;
    }
    return R.m[0][0];
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void gcd(ll a, ll &x, ll b, ll &y)
{
    if (a == 0) { x = 0; y = 1; }
    else {
        ll xx, yy; gcd(b % a, xx, a, yy);
        x = yy - b / a * xx; y = xx;
    }
}

void Solve(ll a, ll &x, ll b, ll &y)
{
    gcd(a, x, b, y);
    x %= b;
    if (x < 0) x += b;
}

int main()
{
    root_inv = Inv(root);
    int my = 1;
    int pw = toPower(root, Maxp);
    for (int i = 0; i <= Maxp; i++) {
        M[my] = i * Maxp;
        my = ll(my) * pw % mod;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        scanf("%d", &b[i]);
    scanf("%d %d", &n, &m);
    int Y;
    int cur = 1;
    for (int i = 0; ; i++) {
        map <int, int>::iterator it = M.find(ll(m) * cur % mod);
        if (it != M.end()) { Y = i + it->second; break; }
        cur = ll(cur) * root_inv % mod;
    }
    int X = getX(n);
    if (X == 0)
        if (Y == 0) printf("1\n");
        else printf("-1\n");
    else {
        int M = mod - 1;
        int g = gcd(X, M);
        if (Y % g != 0) { printf("-1\n"); return 0; }
        ll a, tmp;
        Solve(X / g, a, M / g, tmp);
        a = a * ll(Y / g) % M;
        printf("%d\n", toPower(root, a));
        int r = toPower(root, a);
    }
    return 0;
}