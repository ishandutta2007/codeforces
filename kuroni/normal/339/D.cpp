#include <iostream>
#include <cstdio>
using namespace std;

int n, m, i, a[(1 << 17) + 5], tree[(1 << 19) + 105], p, b;

int build(int l, int r, int i, int h)
{
    if (l == r)
        tree[i] = a[l];
    else
    {
        int m = (l + r) / 2;
        if (h & 1)
            tree[i] = build(l, m, 2 * i, h - 1) | build(m + 1, r, 2 * i + 1, h - 1);
        else tree[i] = build(l, m, 2 * i, h - 1) ^ build(m + 1, r, 2 * i + 1, h - 1);
    }
    return tree[i];
}

void upd(int l, int r, int i, int h)
{
    if (l == r)
        tree[i] = a[l];
    else
    {
        int m = (l + r) / 2;
        if (p <= m)
            upd(l, m, 2 * i, h - 1);
        else upd(m + 1, r, 2 * i + 1, h - 1);
        if (h & 1)
            tree[i] = tree[2 * i] | tree[2 * i + 1];
        else tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= (1 << n); i++)
        scanf("%d", a + i);
    build(1, 1 << n, 1, n);
    while (m--)
    {
        scanf("%d%d", &p, &b); a[p] = b;
        upd(1, (1 << n), 1, n);
        printf("%d\n", tree[1]);
    }
}