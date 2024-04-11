#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 500005;

class CTree
{
#define m ((l + r) >> 1)
#define lc (i << 1)
#define rc (i << 1) + 1
  private:
    struct SNode
    {
        int l, r, val;
    } tree[4 * N];

  public:
    void build(int l, int r, int i)
    {
        tree[i].l = l;
        tree[i].r = r;
        if (l < r)
        {
            build(l, m, lc);
            build(m + 1, r, rc);
        }
    }
    
    void upd(int l, int r, int i, int u, int v)
    {
        if (l == r)
            tree[i].val = v;
        else
        {
            if (u <= m)
                upd(l, m, lc, u, v);
            else
                upd(m + 1, r, rc, u, v);
            tree[i].val = __gcd(tree[lc].val, tree[rc].val);
        }
    }

    int que(int l, int r, int i, int L, int R, int x)
    {
        if (l > R || r < L)
            return -1;
        else if (L <= l && r <= R)
            return (tree[i].val % x == 0 ? -1 : i);
        else
        {
            int a = que(l, m, lc, L, R, x), b = que(m + 1, r, rc, L, R, x);
            if (a == 0 || b == 0)
                return 0;
            else if (a != -1 && b != -1)
                return 0;
            else
                return (a == -1 ? b : a);
        }
    }

    bool chk(int i, int x)
    {
        while (tree[i].l != tree[i].r)
        {
            if (tree[lc].val % x != 0 && tree[rc].val % x != 0)
                return false;
            else
                i = (tree[lc].val % x == 0 ? rc : lc);
        }
        return true;
    }
#undef m
#undef lc
#undef rc
} tr;
int n, q, t, l, r, x;

int main()
{
    scanf("%d", &n);
    tr.build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        tr.upd(1, n, 1, i, x);
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d%d%d", &l, &r, &x);
            int que = tr.que(1, n, 1, l, r, x);
            if (que == -1)
                printf("YES\n");
            else if (que == 0)
                printf("NO\n");
            else printf("%s\n", tr.chk(que, x) ? "YES" : "NO");
        }
        else
        {
            scanf("%d%d", &l, &x);
            tr.upd(1, n, 1, l, x);
        }
    }
}