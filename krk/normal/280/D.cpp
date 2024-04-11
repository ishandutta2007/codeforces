#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxk = 41;
const int Inf = 1000000001;

struct node {
    int mn[Maxk];
    int mx[Maxk];
    int sum;
    node() {
        fill(mn, mn + Maxk, Inf);
        fill(mx, mx + Maxk, -Inf);
        sum = 0;
    }
};

int n;
int a[Maxn];
node st[Maxm];
int m;

node Union(const node &a, const node &b)
{
    node c;
    for (int i = 0; i < Maxk; i++)
        for (int j = 0; i + j < Maxk; j++) {
            int add = j % 2? -a.sum: 0;
            c.mn[i + j] = min(c.mn[i + j], a.mn[i] + (i % 2 == 0? (b.mn[j] + add): -(b.mx[j] + add)));
            c.mx[i + j] = max(c.mx[i + j], a.mx[i] + (i % 2 == 0? (b.mx[j] + add): -(b.mn[j] + add)));
        }
    c.sum = a.sum + b.sum;
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].sum = a[l];
        for (int i = 0; i < Maxk; i++)
            st[v].mn[i] = st[v].mx[i] = i % 2? -a[l]: 0;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x, int val)
{
    if (l == r) {
        st[v].sum = val;
        for (int i = 0; i < Maxk; i++)
            st[v].mn[i] = st[v].mx[i] = i % 2? -val: 0;
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, val);
        else Update(2 * v + 1, m + 1, r, x, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, min(m, b));
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 0, n);
    scanf("%d", &m);
    while (m--) {
        int typ, a, b; scanf("%d %d %d", &typ, &a, &b);
        if (typ == 0) Update(1, 0, n, a, b);
        else {
            int k; scanf("%d", &k);
            printf("%d\n", Get(1, 0, n, a - 1, b).mx[2 * k]);
        }
    }
    return 0;
}