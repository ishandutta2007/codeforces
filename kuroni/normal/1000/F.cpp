#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 500005, Q = 500005;

int n, q, l, r, a[N], f[N], lst[N], ans[Q];
vector<pair<int, int>> que[N];

class CTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1
  private:
    int tr[4 * N];

  public:
    void build(int l, int r, int i)
    {
        tr[i] = l;
        if (l == r)
            return;
        build(l, m, lc);
        build(m + 1, r, rc);
    }
    
    void upd(int l, int r, int i, int u)
    {
        if (l == r)
            return;
        if (u <= m)
            upd(l, m, lc, u);
        else
            upd(m + 1, r, rc, u);
        tr[i] = (f[tr[lc]] < f[tr[rc]] ? tr[lc] : tr[rc]);
    }

    int que(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (L <= l && r <= R)
            return tr[i];
        int x = que(l, m, lc, L, R), y = que(m + 1, r, rc, L, R);
        return (f[x] < f[y] ? x : y);
    }
#undef m
#undef lc
#undef rc
} seg;

int main()
{
    f[0] = N;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &l, &r);
        que[r].push_back(make_pair(l, i));
    }
    seg.build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        if (lst[a[i]] != 0)
        {
            f[lst[a[i]]] = N;
            seg.upd(1, n, 1, lst[a[i]]);
        }
        f[i] = lst[a[i]];
        seg.upd(1, n, 1, lst[a[i]] = i);
        for (pair<int, int> u : que[i])
        {
            int ret = seg.que(1, n, 1, u.fi, i);
            ans[u.se] = (f[ret] >= u.fi ? 0 : a[ret]);
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
}