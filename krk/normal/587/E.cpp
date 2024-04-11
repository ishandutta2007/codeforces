#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxb = 30;
const int Maxm = 1048576;

struct node {
    ii m[Maxb];
    bool has;
    node() {
        fill(m, m + Maxb, ii(0, 0));
        has = false;
    }
    void Insert(int x, int f) {
        for (int i = Maxb - 1; i >= 0; i--) if (x & 1 << i)
            if (m[i].first == 0) {
                m[i] = ii(x, f);
                return;
            } else {
                x ^= m[i].first;
                f = (f + m[i].second) % 2;
            }
        if (f) has = true;
    }
};

int n, q;
int a[Maxn];
node st[Maxm];
int fl[Maxm];

void downOn(int v, int f)
{
    node c;
    for (int i = 0; i < Maxb; i++) if (st[v].m[i].first) {
        int x = st[v].m[i].first;
        if (st[v].m[i].second) x ^= f;
        c.Insert(x, st[v].m[i].second);
    }
    if (st[v].has)
        c.Insert(f, 1);
    st[v] = c;
    fl[v] ^= f;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

node Union(const node &a, const node &b)
{
    node c = a;
    for (int i = 0; i < Maxb; i++) if (b.m[i].first)
        c.Insert(b.m[i].first, b.m[i].second);
    if (b.has) c.has = true;
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) st[v].Insert(a[l], 1);
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(1, 1, n);
    while (q--) {
        int typ, l, r; scanf("%d %d %d", &typ, &l, &r);
        if (typ == 1) {
            int k; scanf("%d", &k);
            Update(1, 1, n, l, r, k);
        } else {
            auto got = Get(1, 1, n, l, r);
            int cnt = 0;
            for (int i = 0; i < Maxb; i++) if (got.m[i].first)
                cnt++;
            printf("%d\n", 1 << cnt);
        }
    }
    return 0;
}