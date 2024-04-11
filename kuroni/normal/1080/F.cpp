#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 3E5 + 5, INF = 1E9 + 7;

int n, m, q, l, r, x, y;

struct SLine
{
    int l, r, ind;
} a[M];

inline bool operator<(const SLine &a, const SLine &b)
{
    return a.l < b.l;
}

class CTree
{
#define m (l + r) / 2

  private:
    int ma;
    CTree *lc, *rc;

  public:
    void build(int l, int r)
    {
        ma = INF;
        if (l == r)
            return;
        lc = new CTree;
        rc = new CTree;
        lc->build(l, m);
        rc->build(m + 1, r);
    }

    void upd(int l, int r, int u, int v, CTree *pre)
    {
        ma = pre->ma;
        if (l == r)
        {
            ma = min(ma, v);
            return;
        }
        if (u <= m)
        {
            rc = pre->rc;
            lc = new CTree;
            lc->upd(l, m, u, v, pre->lc);
        }
        else
        {
            lc = pre->lc;
            rc = new CTree;
            rc->upd(m + 1, r, u, v, pre->rc);
        }
        ma = max(lc->ma, rc->ma);
    }

    int que(int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return -INF;
        if (L <= l && r <= R)
            return ma;
        return max(lc->que(l, m, L, R), rc->que(m + 1, r, L, R));
    }
#undef m
} *seg[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].ind;
    sort(a + 1, a + m + 1);
    seg[m + 1] = new CTree;
    seg[m + 1]->build(1, n);
    for (int i = m; i >= 1; i--)
    {
        seg[i] = new CTree;
        seg[i]->upd(1, n, a[i].ind, a[i].r, seg[i + 1]);
    }
    while (q--)
    {
        cin >> l >> r >> x >> y;
        int dis = distance(a, lower_bound(a + 1, a + m + 1, (SLine){x, y, 0}));
        cout << (seg[dis]->que(1, n, l, r) <= y ? "yes" : "no") << endl;
    }
}