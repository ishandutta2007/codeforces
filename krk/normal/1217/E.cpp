#include <bits/stdc++.h>
using namespace std;

const int Inf = 2000000007;
const int Maxd = 9;
const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    int mn[Maxd];
    int sum;
};

int n, m;
int a[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
    node c;
    c.sum = min(a.sum, b.sum);
    for (int i = 0; i < Maxd; i++) {
        if (a.mn[i] < Inf && b.mn[i] < Inf)
            c.sum = min(c.sum, a.mn[i] + b.mn[i]);
        c.mn[i] = min(a.mn[i], b.mn[i]);
    }
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].sum = Inf;
        int num = a[l];
        for (int i = 0; i < Maxd; i++) {
            if (num % 10) st[v].mn[i] = a[l];
            else st[v].mn[i] = Inf;
            num /= 10;
        }
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) {
        st[v].sum = Inf;
        int num = a[l];
        for (int i = 0; i < Maxd; i++) {
            if (num % 10) st[v].mn[i] = a[l];
            else st[v].mn[i] = Inf;
            num /= 10;
        }
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    while (m--) {
        int typ, p1, p2; scanf("%d %d %d", &typ, &p1, &p2);
        if (typ == 1) {
            a[p1] = p2;
            Update(1, 1, n, p1);
        } else {
            node got = Get(1, 1, n, p1, p2);
            printf("%d\n", got.sum >= Inf? -1: got.sum);
        }
    }
    return 0;
}