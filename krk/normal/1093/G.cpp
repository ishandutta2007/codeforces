#include <bits/stdc++.h>
using namespace std;

const int Maxd = 1 << 4;
const int Maxn = 200005;
const int Maxk = 5;
const int Maxm = 1048576;
const int Inf = 1000000000;

int n, k;
int a[Maxn][Maxk];
int mn[Maxm][Maxd], mx[Maxm][Maxd];
int qmn[Maxd], qmx[Maxd];

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    for (int j = 0; j < 1 << (k - 1); j++) {
        mn[v][j] = min(mn[lc][j], mn[rc][j]);
        mx[v][j] = max(mx[lc][j], mx[rc][j]);
    }
}

void Output(int v, int a[])
{
    for (int j = 0; j < 1 << (k - 1); j++) {
        int sum = 0;
        for (int z = 0; z < k - 1; z++)
            if (j & 1 << z) sum += a[z];
            else sum -= a[z];
        sum += a[k - 1];
        mn[v][j] = mx[v][j] = sum;
    }
}

void Create(int v, int l, int r)
{
    if (l == r) Output(v, a[l]);
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) Output(v, a[l]);
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        Union(v);
    }
}

void Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b)
        for (int i = 0; i < 1 << (k - 1); i++) {
            qmn[i] = min(qmn[i], mn[v][i]);
            qmx[i] = max(qmx[i], mx[v][i]);
        }
    else {
        int m = l + r >> 1;
        if (a <= m) Get(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &a[i][j]);
    Create(1, 1, n);
    int q; scanf("%d", &q);
    while (q--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int ind; scanf("%d", &ind);
            for (int j = 0; j < k; j++)
                scanf("%d", &a[ind][j]);
            Update(1, 1, n, ind);
        } else {
            fill(qmn, qmn + (1 << (k - 1)), Inf);
            fill(qmx, qmx + (1 << (k - 1)), -Inf);
            int l, r; scanf("%d %d", &l, &r);
            Get(1, 1, n, l, r);
            int res = 0;
            for (int i = 0; i < 1 << (k - 1); i++)
                res = max(res, qmx[i] - qmn[i]);
            printf("%d\n", res);
        }
    }
    return 0;
}