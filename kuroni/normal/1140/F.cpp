#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 300005, Q = 300005;

int q, u, v;
long long ans = 0;
map<pair<int, int>, int> ma;

struct SNode
{
    int par, a, b, sz;

    SNode(int _par = 0, int _a = 0, int _b = 0)
    {
        par = _par;
        a = _a;
        b = _b;
        sz = a + b;
    }

    long long get_ans()
    {
        return 1LL * a * b;
    }

    SNode operator+(SNode oth)
    {
        return SNode(par, a + oth.a, b + oth.b);
    }
} dsu[2 * N];

int trace(int u)
{
    return dsu[u].par == u ? u : trace(dsu[u].par);
}

void connect(int u, int v, vector<SNode> &st)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u].sz < dsu[v].sz)
        swap(u, v);
    st.push_back(dsu[v]);
    ans -= dsu[u].get_ans() + dsu[v].get_ans();
    dsu[u] = dsu[u] + dsu[v];
    dsu[v].par = u;
    ans += dsu[u].get_ans();
}

void rollback(vector<SNode> &st)
{
    for (; !st.empty(); st.pop_back())
    {
        SNode cur = st.back();
        int v = cur.par, u = dsu[v].par;
        ans -= dsu[u].get_ans();
        dsu[u] = dsu[u] + SNode(v, -cur.a, -cur.b);
        dsu[v] = cur;
        ans += dsu[u].get_ans() + dsu[v].get_ans();
    }
}

class CTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

  private:
    vector<pair<int, int>> que[4 * Q];
    vector<SNode> st[4 * Q];

  public:
    void upd(int l, int r, int i, int L, int R, pair<int, int> v)
    {
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            que[i].push_back(v);
            return;
        }
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
    }

    void answer(int l, int r, int i)
    {
        for (pair<int, int> &v : que[i])
            connect(v.fi, v.se, st[i]);
        if (l == r)
            printf("%lld ", ans);
        else
        {
            answer(l, m, lc);
            answer(m + 1, r, rc);
        }
        rollback(st[i]);
    }

#undef m
#undef lc
#undef rc
} seg;

void init()
{
    for (int i = 0; i < N; i++)
        dsu[i] = SNode(i, 1, 0);
    for (int i = N; i < 2 * N; i++)
        dsu[i] = SNode(i, 0, 1);
}

int main()
{
    init();
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &u, &v);
        pair<int, int> cur = mp(u, v + N);
        if (ma.count(cur) == 1)
        {
            seg.upd(1, q, 1, ma[cur], i - 1, cur);
            ma.erase(cur);
        }
        else
            ma[cur] = i;
    }
    for (auto v : ma)
        seg.upd(1, q, 1, v.se, q, v.fi);
    seg.answer(1, q, 1);
}