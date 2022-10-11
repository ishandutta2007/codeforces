#include <bits/stdc++.h>
using namespace std;

const int N = 100005, INF = 1E9 + 7;

int n, q, t, p, u, a[N];
long long tar;

struct SNode
{
    int cnt, mi;
    long long sum;
    SNode *lc, *rc;

    SNode()
    {
        cnt = 0;
        sum = 0;
        lc = rc = nullptr;
    }
} *rt = new SNode();

double maxima(long long tar, int cnt)
{
    return 1.0 * tar / cnt;
}

#define m (l + r) / 2

int get(SNode *cur)
{
    return cur == nullptr ? 0 : cur->cnt;
}

void update(SNode *rt, int l, int r, int u, int add)
{
    rt->cnt += add;
    rt->sum += u * add;
    if (l == r)
    {
        rt->mi = l;
        return;
    }
    if (u <= m)
    {
        if (rt->lc == nullptr)
            rt->lc = new SNode();
        update(rt->lc, l, m, u, add);
    }
    else
    {
        if (rt->rc == nullptr)
            rt->rc = new SNode();
        update(rt->rc, m + 1, r, u, add);
    }
    if (rt->cnt > 0)
        rt->mi = (get(rt->lc) > 0 ? rt->lc : rt->rc)->mi;
}

double walk(SNode *rt, int l, int r, long long tar, int cnt)
{
    if (l == r)
        return maxima(tar + rt->sum, cnt + rt->cnt);
    else if (get(rt->lc) == 0)
        return walk(rt->rc, m + 1, r, tar, cnt);
    else if (get(rt->rc) == 0)
        return walk(rt->lc, l, m, tar, cnt);
    else if (maxima(tar + rt->lc->sum, cnt + rt->lc->cnt) > rt->rc->mi)
        return walk(rt->rc, m + 1, r, tar + rt->lc->sum, cnt + rt->lc->cnt);
    else
        return walk(rt->lc, l, m, tar, cnt);
}

#undef m

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(4);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(rt, 0, INF, a[i], 1);
    }
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> p >> u;
            update(rt, 0, INF, a[p], -1);
            update(rt, 0, INF, a[p] = u, 1);
        }
        else
        {
            cin >> tar;
            cout << walk(rt, 0, INF, tar, 0) << '\n';
        }
    }
}