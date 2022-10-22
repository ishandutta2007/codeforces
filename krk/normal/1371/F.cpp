#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Maxm = 2097152;

struct node {
    char a, b;
    int alen, blen;
    int cnt, mx;
};

int n, q;
char str[Maxn];
node st[Maxm][2];
int fl[Maxm];

node Union(const node &a, const node &b)
{
    node c;
    c.cnt = a.cnt + b.cnt;
    c.mx = max(a.mx, b.mx);
    c.a = a.a;
    c.b = b.b;
    if (a.alen == a.cnt && !(a.b == '<' && b.a == '>'))
        c.alen = a.alen + b.alen;
    else c.alen = a.alen;
    if (b.blen == b.cnt && !(a.b == '<' && b.a == '>'))
        c.blen = b.blen + a.blen;
    else c.blen = b.blen;
    if (!(a.b == '<' && b.a == '>'))
        c.mx = max(c.mx, a.blen + b.alen);
    return c;
}

void downOn(int v)
{
    swap(st[v][0], st[v][1]);
    fl[v] ^= true;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v);
        downOn(2 * v + 1);
        fl[v] = false;
    }
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v][0].a = st[v][0].b = '<';
        st[v][0].alen = st[v][0].blen = 1;
        st[v][0].cnt = 1;
        st[v][0].mx = 1;
        st[v][1].a = st[v][1].b = '>';
        st[v][1].alen = st[v][1].blen = 1;
        st[v][1].cnt = 1;
        st[v][1].mx = 1;
        if (str[l] == '>')
            downOn(v);
    } else {
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        Create(lc, l, m);
        Create(rc, m + 1, r);
        st[v][0] = Union(st[lc][0], st[rc][0]);
        st[v][1] = Union(st[lc][1], st[rc][1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) { downOn(v); return st[v][0]; }
    else {
        Down(v);
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        node res;
        if (b <= m) res = Get(lc, l, m, a, b);
        else if (m + 1 <= a) res = Get(rc, m + 1, r, a, b);
        else res = Union(Get(lc, l, m, a, m), Get(rc, m + 1, r, m + 1, b));
        st[v][0] = Union(st[lc][0], st[rc][0]);
        st[v][1] = Union(st[lc][1], st[rc][1]);
        return res;
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    Create(1, 1, n);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", Get(1, 1, n, l, r).mx);
    }
    return 0;
}