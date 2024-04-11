#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000000;
const int Maxn = 200005;
const int Maxs = 1048576;
const int Maxd = 2;

struct matrix {
    int x[Maxd][Maxd];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                x[i][j] = (i == j) * diag;
    }
    matrix operator *(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int k = 0; k < Maxd; k++)
                    c.x[i][j] = (c.x[i][j] + ll(x[i][k]) * b.x[k][j]) % mod;
        return c;
    };
};

int n, m;
int fib[Maxn];
matrix M[Maxn];
int a[Maxn];
int st[Maxs][2];
int flag[Maxs];

void makeShift(int has[], int len, int res[])
{
    res[1] = (ll(has[1]) * M[len].x[0][0] + ll(has[0]) * M[len].x[0][1]) % mod;
    res[0] = (ll(has[1]) * M[len].x[1][0] + ll(has[0]) * M[len].x[1][1]) % mod;
}

void Union(int fir[], int sec[], int len, int res[])
{
    int tmp[2]; makeShift(sec, len, tmp);
    res[0] = (fir[0] + tmp[0]) % mod;
    res[1] = (fir[1] + tmp[1]) % mod;
}

void Down(int v, int l, int m, int r)
{
    if (flag[v]) {
        int add = ll(fib[m - l + 1]) * flag[v] % mod;
        st[2 * v][0] = (st[2 * v][0] + add) % mod;
        add = ll(fib[m - l + 2] - fib[1] + mod) * flag[v] % mod;
        st[2 * v][1] = (st[2 * v][1] + add) % mod;
        flag[2 * v] = (flag[2 * v] + flag[v]) % mod;

        add = ll(fib[r - m]) * flag[v] % mod;
        st[2 * v + 1][0] = (st[2 * v + 1][0] + add) % mod;
        add = ll(fib[r - m + 1] - fib[1] + mod) * flag[v] % mod;
        st[2 * v + 1][1] = (st[2 * v + 1][1] + add) % mod;
        flag[2 * v + 1] = (flag[2 * v + 1] + flag[v]) % mod;

        flag[v] = 0;
    }
}

void Create(int v, int l, int r)
{
    if (l == r) st[v][0] = st[v][1] = a[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
        Union(st[2 * v], st[2 * v + 1], m - l + 1, st[v]);
    }
}

void Change(int v, int l, int r, int x, int val)
{
    if (l == r) st[v][0] = st[v][1] = val;
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (x <= m) Change(2 * v, l, m, x, val);
        else Change(2 * v + 1, m + 1, r, x, val);
        Union(st[2 * v], st[2 * v + 1], m - l + 1, st[v]);
    }
}

void Inc(int v, int l, int r, int a, int b, int d)
{
    if (l == a && r == b) {
        int add = ll(fib[r - l + 1]) * d % mod;
        st[v][0] = (st[v][0] + add) % mod;
        add = ll(fib[r - l + 2] - fib[1] + mod) * d % mod;
        st[v][1] = (st[v][1] + add) % mod;
        flag[v] = (flag[v] + d) % mod;
    } else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (a <= m) Inc(2 * v, l, m, a, min(m, b), d);
        if (m + 1 <= b) Inc(2 * v + 1, m + 1, r, max(m + 1, a), b, d);
        Union(st[2 * v], st[2 * v + 1], m - l + 1, st[v]);
    }
}

void getRes(int v, int l, int r, int a, int b, int res[])
{
    if (l == a && r == b) { res[0] = st[v][0]; res[1] = st[v][1]; }
    else {
        int m = l + r >> 1;
        Down(v, l, m, r);
        if (b <= m) getRes(2 * v, l, m, a, b, res);
        else if (m + 1 <= a) getRes(2 * v + 1, m + 1, r, a, b, res);
        else {
            int res2[2];
            getRes(2 * v, l, m, a, m, res); getRes(2 * v + 1, m + 1, r, m + 1, b, res2);
            Union(res, res2, m - a + 1, res);
        }
    }
}

int main()
{
    fib[1] = fib[2] = 1;
    for (int i = 3; i < Maxn; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    for (int i = 1; i < Maxn; i++)
        fib[i] = (fib[i] + fib[i - 1]) % mod;
    M[1].x[0][0] = M[1].x[0][1] = M[1].x[1][0] = 1;
    for (int i = 2; i < Maxn; i++)
        M[i] = M[i - 1] * M[1];

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    while (m--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int x, v; scanf("%d %d", &x, &v);
            Change(1, 1, n, x, v);
        } else if (t == 2) {
            int l, r; scanf("%d %d", &l, &r);
            int res[2]; getRes(1, 1, n, l, r, res);
            printf("%d\n", res[0]);
        } else if (t == 3) {
            int l, r, d; scanf("%d %d %d", &l, &r, &d);
            Inc(1, 1, n, l, r, d);
        }
    }
    return 0;
}