#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000002;
const int Maxm = 4194304;

int n, m;
int a[Maxn], b[Maxn];
int pref[Maxn];
int st[Maxm], fl[Maxm];

void Union(int v)
{
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

void downOn(int v, int x)
{
    st[v] += x; fl[v] += x;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Create(int v, int l, int r)
{
    if (l == r) st[v] = pref[l];
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) downOn(v, delt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

int Get(int v, int l, int r)
{
    if (l == r) return l;
    else {
        Down(v);
        int m = l + r >> 1;
        if (st[2 * v + 1] < 0) return Get(2 * v + 1, m + 1, r);
        return Get(2 * v, l, m);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pref[a[i]]--;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        pref[b[i]]++;
    }
    pref[0] = -m - 1;
    for (int i = Maxn - 2; i >= 0; i--)
        pref[i] += pref[i + 1];
    Create(1, 0, Maxn - 1);
    int q; scanf("%d", &q);
    while (q--) {
        int typ, u, v; scanf("%d %d %d", &typ, &u, &v);
        if (typ == 1) {
            int old = a[u];
            if (old < v) Update(1, 0, Maxn - 1, old + 1, v, -1);
            else if (v < old) Update(1, 0, Maxn - 1, v + 1, old, 1);
            a[u] = v;
        } else if (typ == 2) {
            int old = b[u];
            if (old < v) Update(1, 0, Maxn - 1, old + 1, v, 1);
            else if (v < old) Update(1, 0, Maxn - 1, v + 1, old, -1);
            b[u] = v;
        }
        int res = Get(1, 0, Maxn - 1);
        if (res == 0) res = -1;
        printf("%d\n", res);
    }
    return 0;
}