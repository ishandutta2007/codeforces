#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 50005, Q = 5005, MAX = 1E6 + 5;

struct SQuery
{
    int l, r, ind;
} que[Q];
struct SNode
{
    int va;
    bool ty;
    SNode *ch[2];

    SNode(int _va, bool _ty)
    {
        va = _va;
        ty = _ty;
        ch[0] = ch[1] = nullptr;
    }
} *mi = new SNode(MAX, false), *ma = new SNode(0, true);
int l, r, lst = -1, n, q, d, cur = 0, f[MAX], a[N], ans[Q];

inline bool operator<(const SQuery &a, const SQuery &b)
{
    return a.l / d < b.l / d || (a.l / d == b.l / d && a.r < b.r);
}

void init()
{
    for (int i = 1; i < MAX; i++)
        f[i] = f[i - 1] ^ i;
}

void reinit(SNode *cur)
{
    for (int i = 0; i < 2; i++)
        if (cur->ch[i] != nullptr)
        {
            reinit(cur->ch[i]);
            delete cur->ch[i];
        }
}

int func(const int &u, const int &v)
{
    return (u <= v ? f[u - 1] ^ f[v] : f[v - 1] ^ f[u]);
}

int mx(SNode *cur, int mx)
{
    if ((cur->ty && cur->va < mx) || (!cur->ty && cur->va > mx))
        return 0;
    int v = (cur->ty ? f[mx - 1] : f[mx]);
    int ret = 0;
    for (int i = 19; i >= 0; i--)
    {
        int b = (v >> i & 1) ^ 1;
        if (cur->ch[b] != nullptr && ((cur->ty && cur->ch[b]->va >= mx) || (!cur->ty && cur->ch[b]->va <= mx)))
        {
            cur = cur->ch[b];
            ret += (1 << i);
        }
        else
            cur = cur->ch[b ^ 1];
    }
    return ret;
}

void insert(SNode *cur, int mx)
{
    cur->va = (cur->ty ? max(cur->va, mx) : min(cur->va, mx));
    int v = (cur->ty ? f[mx] : f[mx - 1]);
    for (int i = 19; i >= 0; i--)
    {
        int b = (v >> i & 1);
        if (cur->ch[b] == nullptr)
            cur->ch[b] = new SNode(mx, cur->ty);
        cur = cur->ch[b];
        cur->va = (cur->ty ? max(cur->va, mx) : min(cur->va, mx));
    }
}

void get_ans(const SQuery &q)
{
    int &ret = ans[q.ind];
    for (int i = q.l; i <= q.r; i++)
        for (int j = i; j <= q.r; j++)
            ret = max(ret, func(a[i], a[j]));
}

void process(const SQuery &q)
{
    int &ret = ans[q.ind], buc = q.l / d;
    if (buc != lst)
    {
        reinit(mi);
        reinit(ma);
        mi = new SNode(MAX, false);
        ma = new SNode(0, true);
        l = (buc + 1) * d;
        r = q.r;
        cur = 0;
        for (int i = l; i <= r; i++)
        {
            insert(mi, a[i]);
            insert(ma, a[i]);
            cur = max(cur, max(mx(mi, a[i]), mx(ma, a[i])));
        }
        lst = buc;
    }
    while (r < q.r)
    {
        ++r;
        insert(mi, a[r]);
        insert(ma, a[r]);
        cur = max(cur, max(mx(mi, a[r]), mx(ma, a[r])));
    }
    ret = cur;
    for (int i = q.l; i < l; i++)
    {
        for (int j = i; j < l; j++)
            ret = max(ret, func(a[i], a[j]));
        ret = max(ret, max(mx(mi, a[i]), mx(ma, a[i])));
    }
}

int main()
{
    init();
    scanf("%d%d", &n, &q);
    d = sqrt(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &que[i].l, &que[i].r);
        que[i].ind = i;
    }
    sort(que + 1, que + q + 1);
    for (int i = 1; i <= q; i++)
        if (que[i].r - que[i].l <= d)
            get_ans(que[i]);
        else
            process(que[i]);
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
}