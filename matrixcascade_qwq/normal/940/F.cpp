#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
const int maxn = 5e5 + 10;
int n, m, blo, a[maxn], S[maxn], tot, bl[maxn], l = 1, r = 0, t, tot1, tot2, ans[maxn], cnt[maxn], mex[maxn];
struct node
{
    int l, r, t, id;
} q[maxn];

struct upt
{
    int pos, x;
} c[maxn];

bool cmp(node a, node b)
{
    return (bl[a.l] ^ bl[b.l]) ? bl[a.l] < bl[b.l] : ((bl[a.r] ^ bl[b.r]) ? bl[a.r] < bl[b.r] : a.t < b.t);
}
void add(int x)
{
    --mex[cnt[x]];
    ++mex[++cnt[x]];
}
void del(int x)
{
    --mex[cnt[x]];
    //assert(cnt[x] > 0);
    ++mex[--cnt[x]];
}
void update(int id, int time)
{
    if (c[time].pos >= q[id].l && c[time].pos <= q[id].r)
    {
        del(a[c[time].pos]), add(c[time].x);
    }
    swap(a[c[time].pos], c[time].x);
}
int main()
{
    n = read(), m = read();
    blo = pow(n, 0.66666);
    blo = 3000;
    for (int i = 1; i <= n; ++i)
        a[i] = read(), S[++tot] = a[i], bl[i] = (i - 1) / blo + 1;
    for (int i = 1; i <= m; ++i)
    {
        int opt, x, y;
        opt = read(), x = read(), y = read();
        if (opt == 1)
        {
            q[++tot2].l = x;
            q[tot2].r = y;
            q[tot2].id = tot2;
            q[tot2].t = tot1;
        }
        if (opt == 2)
        {
            c[++tot1].pos = x;
            c[tot1].x = y;
            S[++tot] = y;
        }
    }
    sort(S + 1, S + tot + 1);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(S + 1, S + tot + 1, a[i]) - S;
    }
    for (int i = 1; i <= tot1; ++i)
    {
        c[i].x = lower_bound(S + 1, S + tot + 1, c[i].x) - S;
    }
    sort(q + 1, q + tot2 + 1, cmp);
    for (int i = 1; i <= tot2; ++i)
    {
        while (l < q[i].l)
            del(a[l++]);
        while (l > q[i].l)
            add(a[--l]);
        while (r < q[i].r)
            add(a[++r]);
        while (r > q[i].r)
            del(a[r--]);
        while (t < q[i].t)
            update(i, ++t);
        while (t > q[i].t)
            update(i, t--);
        for (ans[q[i].id] = 1; mex[ans[q[i].id]] > 0; ++ans[q[i].id])
            ;
    }
    for (int i = 1; i <= tot2; ++i)
    {
        printf("%d\n", ans[i]);
    }
}