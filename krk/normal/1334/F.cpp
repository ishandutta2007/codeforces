#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 2097152;
const ll Inf = 4000000000000000000ll;
const ll sInf = 100000000000000000ll;

ll st[Maxm], fl[Maxm];
int n;
int a[Maxn];
int p[Maxn];
int m;
int b[Maxn];
int prv[Maxn];

void downOn(int v, ll f)
{
    st[v] += f; fl[v] += f;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Union(int v)
{
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

void Create(int v, int l, int r)
{
    if (l == r)
        st[v] = l == 0? 0: Inf;
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Add(int v, int l, int r, int a, int b, ll val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

void Set(int v, int l, int r, int x, ll val)
{
    if (l == r) st[v] = min(st[v], val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (x <= m) Set(2 * v, l, m, x, val);
        else Set(2 * v + 1, m + 1, r, x, val);
        Union(v);
    }
}

ll Get(int v, int l, int r, int x)
{
    if (l == r) return st[v];
    else {
        Down(v);
        int m = l + r >> 1;
        if (x <= m) return Get(2 * v, l, m, x);
        else return Get(2 * v + 1, m + 1, r, x);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    fill(prv, prv + n + 1, -1);
    scanf("%d", &m);
    int lst = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        prv[b[i]] = lst;
        lst = b[i];
    }
    Create(1, 0, n);
    for (int i = 1; i <= n; i++) {
        Add(1, 0, n, a[i], n, min(0, p[i]));
        ll sav = Inf;
        if (prv[a[i]] != -1) sav = Get(1, 0, n, prv[a[i]]);
        Add(1, 0, n, 0, a[i] - 1, p[i]);
        Set(1, 0, n, a[i], sav);
    }
    ll got = Get(1, 0, n, b[m]);
    if (got < sInf)
        printf("YES\n%I64d\n", got);
    else printf("NO\n");
    return 0;
}