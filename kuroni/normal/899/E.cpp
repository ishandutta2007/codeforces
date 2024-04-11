#include <iostream>
#include <cstdio>
using namespace std;

struct TNode
{
    int l, r, ml;
} tree[800005];
int n, a[200005], len[200005], pt = 0, ans = 0;

void build(int l, int r, int i)
{
    if (l == r)
    {
        if (len[l] == 0)
            tree[i].l = tree[i].r = tree[i].ml = -1;
        else
            tree[i].l = tree[i].r = tree[i].ml = l;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, i << 1);
    build(m + 1, r, (i << 1) + 1);
    if (tree[i << 1].l == -1)
    {
        tree[i].l = tree[(i << 1) + 1].l;
        tree[i].r = tree[(i << 1) + 1].r;
        tree[i].ml = tree[(i << 1) + 1].ml;
    }
    else
    {
        tree[i].l = tree[i << 1].l;
        tree[i].r = (tree[(i << 1) + 1].r == -1 ? tree[i << 1].r : tree[(i << 1) + 1].r);
        if (tree[(i << 1) + 1].ml != -1 && len[tree[(i << 1) + 1].ml] > len[tree[i << 1].ml])
            tree[i].ml = tree[(i << 1) + 1].ml;
        else
            tree[i].ml = tree[i << 1].ml;
    }
}

void upd(int l, int r, int i, int u)
{
    if (l > u || r < u)
        return;
    if (l == r)
    {
        if (len[l] == 0)
            tree[i].l = tree[i].r = tree[i].ml = -1;
        else
            tree[i].l = tree[i].r = tree[i].ml = l;
        return;
    }
    int m = (l + r) >> 1;
    upd(l, m, i << 1, u);
    upd(m + 1, r, (i << 1) + 1, u);
    if (tree[i << 1].l == -1)
    {
        tree[i].l = tree[(i << 1) + 1].l;
        tree[i].r = tree[(i << 1) + 1].r;
        tree[i].ml = tree[(i << 1) + 1].ml;
    }
    else
    {
        tree[i].l = tree[i << 1].l;
        tree[i].r = (tree[(i << 1) + 1].r == -1 ? tree[i << 1].r : tree[(i << 1) + 1].r);
        if (tree[(i << 1) + 1].ml != -1 && len[tree[(i << 1) + 1].ml] > len[tree[i << 1].ml])
            tree[i].ml = tree[(i << 1) + 1].ml;
        else
            tree[i].ml = tree[i << 1].ml;
    }
}

int que(int l, int r, int i, int L, int R, int t)
{
    if (l > R || r < L)
        return -1;
    else if (L <= l && r <= R)
        return (t == 0 ? tree[i].l : tree[i].r);
    int m = (l + r) >> 1, al = que(l, m, i << 1, L, R, t), ar = que(m + 1, r, (i << 1) + 1, L, R, t);
    if (t == 0)
        return (al == -1 ? ar : al);
    else
        return (ar == -1 ? al : ar);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
            pt = i;
        len[pt]++;
    }
    build(1, n, 1);
    while (tree[1].l != -1)
    {
        ++ans;
        int j = tree[1].ml;
        len[j] = 0;
        upd(1, n, 1, j);
        int l = que(1, n, 1, 1, j, 1), r = que(1, n, 1, j, n, 0);
        if (l != -1 && r != -1 && a[l] == a[r])
        {
            len[l] += len[r];
            len[r] = 0;
            upd(1, n, 1, l);
            upd(1, n, 1, r);
        }
    }
    printf("%d", ans);
}