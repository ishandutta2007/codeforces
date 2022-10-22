#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

struct node {
    ll B, A;
    ll tojoin, forjoin;
    node(): B(0ll), A(0ll), tojoin(0ll), forjoin(0ll) {}
};

int n, q;
int a[Maxn];
int b[Maxn];
node st[Maxm];

node Union(const node &a, const node &b)
{
    node c;
    ll tk = min(a.A, b.B);
    c.B = a.B + b.B - tk;
    c.A = a.A - tk + b.A;
    tk = min(a.forjoin, b.tojoin);
    c.tojoin = a.tojoin + b.tojoin - tk;
    c.forjoin = a.forjoin + b.forjoin - tk;
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r)
        if (a[l] <= b[l]) { st[v].A += b[l] - a[l]; st[v].tojoin += b[l] - a[l]; }
        else { st[v].B += a[l] - b[l]; st[v].forjoin += a[l] - b[l]; }
    else {
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
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    Create(1, 1, n);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        node got = Get(1, 1, n, l, r);
        if (got.B != 0 || got.A != 0) printf("-1\n");
        else printf("%I64d\n", got.tojoin);
    }
    return 0;
}