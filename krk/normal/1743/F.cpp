#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 300005;
const int Maxm = 1048576;
const int Maxd = 2;

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
    bool One()
    {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                if (m[i][j] != int(i == j))
                    return false;
        return true;
    }
};

int n;
int L, R;
matrix st[Maxm], fl[Maxm];
matrix zer, one;
int res;

void Clear(int v, int l, int r)
{
    fl[v] = matrix(1);
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

void downOn(int v, const matrix &m)
{
    fl[v] = m * fl[v];
}

void Down(int v)
{
    if (!fl[v].One()) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = matrix(1);
    }
}

void Update(int v, int l, int r, int a, int b, const matrix &mt)
{
    if (a > b) return;
    if (l == a && r == b) downOn(v, mt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), mt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, mt);
    }
}

void Print(int v, int l, int r)
{
    if (l == r) res = (res + (L <= l && l <= R? fl[v].m[1][1]: fl[v].m[1][0])) % mod;
    else {
        Down(v);
        int m = l + r >> 1;
        Print(2 * v, l, m);
        Print(2 * v + 1, m + 1, r);
    }
}

int main()
{
    scanf("%d", &n);
    zer.m[0][0] = 3; zer.m[0][1] = 1;
    zer.m[1][1] = 2;
    one.m[0][0] = one.m[0][1] = 1;
    one.m[1][0] = one.m[1][1] = 2;
    scanf("%d %d", &L, &R);
    Clear(1, 0, Maxn);
    for (int i = 1; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        Update(1, 0, Maxn, 0, l - 1, zer);
        Update(1, 0, Maxn, l, r, one);
        Update(1, 0, Maxn, r + 1, Maxn, zer);
    }
    Print(1, 0, Maxn);
    printf("%d\n", res);
    return 0;
}