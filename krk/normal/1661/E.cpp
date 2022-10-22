#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Maxd = 3;
const int Maxm = 2097152;
const int Maxk = 10;

struct node {
    int A[Maxd], B[Maxd];
    int sz;
    int comp;
};

int n;
char B[Maxd][Maxn];
node st[Maxm];
int par[Maxk], siz[Maxk];
int un[Maxk], ulen;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a);
    b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

node Union(const node &a, const node &b)
{
    node c;
    int n1 = a.sz, n2 = b.sz;
    for (int i = 1; i <= n1 + n2; i++)
        par[i] = i, siz[i] = 1;
    c.comp = a.comp + b.comp;
    for (int i = 0; i < Maxd; i++)
        if (a.B[i] && b.A[i])
            if (unionSet(a.B[i], n1 + b.A[i]))
                c.comp--;
    ulen = 0;
    for (int i = 0; i < Maxd; i++) {
        if (a.A[i]) un[ulen++] = getPar(a.A[i]);
        if (b.B[i]) un[ulen++] = getPar(n1 + b.B[i]);
    }
    sort(un, un + ulen);
    ulen = unique(un, un + ulen) - un;
    c.sz = ulen;
    for (int i = 0; i < Maxd; i++) {
        if (a.A[i]) c.A[i] = lower_bound(un, un + ulen, getPar(a.A[i])) - un + 1;
        else c.A[i] = 0;
        if (b.B[i]) c.B[i] = lower_bound(un, un + ulen, getPar(n1 + b.B[i])) - un + 1;
        else c.B[i] = 0;
    }
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        int pnt = 0;
        for (int i = 0, j; i < Maxd; i = j) {
            j = i;
            if (B[j][l] == '0') {
                j++; continue;
            }
            pnt++;
            while (j < Maxd && B[j][l] == '1') {
                st[v].A[j] = st[v].B[j] = pnt;
                j++;
            }
        }
        st[v].comp = st[v].sz = pnt;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
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
    scanf("%d", &n);
    for (int i = 0; i < Maxd; i++)
        scanf("%s", B[i] + 1);
    Create(1, 1, n);
    int q; scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", Get(1, 1, n, l, r).comp);
    }
    return 0;
}