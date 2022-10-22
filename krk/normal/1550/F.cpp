#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 1000000000;

struct node {
    int flag;
    ii best;
    ii bestind;
};

int n, q, s, d;
int a[Maxn];
node st[2][Maxm];
int cur, res[Maxn];

void downOn(int t, int v, int f)
{
    st[t][v].flag = min(st[t][v].flag, f);
    st[t][v].best = min(st[t][v].best, ii(f + st[t][v].bestind.first, st[t][v].bestind.second));
}

void Down(int t, int v)
{
    if (st[t][v].flag < Inf) {
        downOn(t, 2 * v, st[t][v].flag);
        downOn(t, 2 * v + 1, st[t][v].flag);
        st[t][v].flag = Inf;
    }
}

void Union(int t, int v)
{
    st[t][v].best = min(st[t][2 * v].best, st[t][2 * v + 1].best);
    st[t][v].bestind = min(st[t][2 * v].bestind, st[t][2 * v + 1].bestind);
}

void Create(int t, int v, int l, int r)
{
    st[t][v].flag = Inf;
    st[t][v].best = ii(Inf, Inf);
    if (l == r)
        st[t][v].bestind = ii((t == 0? -a[l]: a[l]), l);
    else {
        int m = l + r >> 1;
        Create(t, 2 * v, l, m);
        Create(t, 2 * v + 1, m + 1, r);
        Union(t, v);
    }
}

void Update(int t, int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(t, v, val);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (a <= m) Update(t, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(t, v);
    }
}

void Remove(int t, int v, int l, int r, int x)
{
    if (l == r) st[t][v].best = st[t][v].bestind = ii(Inf, Inf);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (x <= m) Remove(t, 2 * v, l, m, x);
        else Remove(t, 2 * v + 1, m + 1, r, x);
        Union(t, v);
    }
}

void Add(int x)
{
    int ind = lower_bound(a + 1, a + n + 1, x) - a;
    if (ind > 1) Update(0, 1, 1, n, 1, ind - 1, x);
    if (ind <= n) Update(1, 1, 1, n, ind, n, -x);
}

int main()
{
    scanf("%d %d %d %d", &n, &q, &s, &d);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Create(0, 1, 1, n);
    Create(1, 1, 1, n);
    Remove(0, 1, 1, n, s);
    Remove(1, 1, 1, n, s);
    Add(a[s] - d);
    Add(a[s] + d);
    for (int i = 0; i < n - 1; i++) {
        ii got1 = st[0][1].best;
        ii got2 = st[1][1].best;
        if (got1.first > got2.first)
            swap(got1, got2);
        cur = max(cur, got1.first);
        int ind = got1.second;
        res[ind] = cur;
        Remove(0, 1, 1, n, ind);
        Remove(1, 1, 1, n, ind);
        Add(a[ind] - d);
        Add(a[ind] + d);
    }
    while (q--) {
        int ind, k; scanf("%d %d", &ind, &k);
        printf("%s\n", res[ind] <= k? "Yes": "No");
    }
    return 0;
}