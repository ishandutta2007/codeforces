#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    int a, alen;
    int b, blen;
    int len;
    ll ans;
    node(): a(0), alen(0), b(0), blen(0), len(0), ans(0ll) {}
};

int n, q;
int a[Maxn];
node st[Maxm];

node Union(const node &fir, const node &sec)
{
    node res;
    res.a = fir.a;
    res.alen = fir.alen == fir.len && fir.b <= sec.a? fir.alen + sec.alen: fir.alen;
    res.b = sec.b;
    res.blen = sec.blen == sec.len && fir.b <= sec.a? sec.blen + fir.blen: sec.blen;
    res.len = fir.len + sec.len;
    res.ans = fir.ans + sec.ans;
    if (fir.b <= sec.a) res.ans += ll(fir.blen) * sec.alen;
    return res;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].a = st[v].b = a[l];
        st[v].alen = st[v].blen = st[v].len = st[v].ans = 1;
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
        else if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        else return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

void Update(int v, int l, int r, int x, int val)
{
    if (l == r) {
        st[v].a = st[v].b = val;
        st[v].alen = st[v].blen = st[v].len = st[v].ans = 1;
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, val);
        else Update(2 * v + 1, m + 1, r, x, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    while (q--) {
        int typ, a, b; scanf("%d %d %d", &typ, &a, &b);
        if (typ == 1) Update(1, 1, n, a, b);
        else printf("%I64d\n", Get(1, 1, n, a, b).ans);
    }
    return 0;
}