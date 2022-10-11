#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define pa pair<CTree, int>
#define fi first
#define se second
using namespace std;

const int N = 100020, MOD = 1E9 + 7;

int n, m, u, v, x, s, t, pw[N], tr[N];
vector<pair<int, int>> adj[N];
bool vis[N];

class CTree
{
#define m ((l + r) >> 1)
  public:
    int hsh;
    CTree *lc, *rc;

    CTree()
    {
        hsh = 0;
        lc = rc = nullptr;
    }

    void build(int l, int r)
    {
        if (l < r)
        {
            lc = new CTree();
            lc->build(l, m);
            rc = new CTree();
            rc->build(m + 1, r);
        }
    }

    void upd(int l, int r, int u, CTree *pre)
    {
        if (l == r)
        {
            hsh = pw[l] - pre->hsh;
            return;
        }
        if (u <= m)
        {
            rc = pre->rc;
            CTree *nxt = pre->lc;
            lc = new CTree();
            lc->upd(l, m, u, nxt);
        }
        else
        {
            lc = pre->lc;
            CTree *nxt = pre->rc;
            rc = new CTree();
            rc->upd(m + 1, r, u, nxt);
        }
        hsh = (lc->hsh + rc->hsh) % MOD;
    }

    bool que(int l, int r, int u)
    {
        if (l == r)
            return hsh != 0;
        return (u <= m ? lc->que(l, m, u) : rc->que(m + 1, r, u));
    }
#undef m
} tmp, dst[N];

inline bool operator<(const CTree &a, const CTree &b)
{
    if (a.hsh == b.hsh)
        return false;
    else
        if (a.lc == nullptr)
            return a.hsh < b.hsh;
        else
            if (a.rc->hsh != b.rc->hsh)
                return *a.rc < *b.rc;
            else
                return *a.lc < *b.lc;
}

void init()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * 2 % MOD;
}

void upd(const CTree &a, int v)
{
    tmp = a;
    while (tmp.que(0, N - 1, v))
        tmp.upd(0, N - 1, v++, &tmp);
    tmp.upd(0, N - 1, v, &tmp);
}

void trace()
{
    vector<int> ret;
    for (int u = t; u != -1; u = tr[u])
        ret.push_back(u);
    printf("%u\n", ret.size());
    while (!ret.empty())
    {
        printf("%d ", ret.back());
        ret.pop_back();
    }
}

void Dijkstra()
{
    priority_queue<pa, vector<pa>, greater<pa>> pq;
    dst[s] = CTree();
    dst[s].build(0, N - 1);
    tr[s] = -1;
    pq.push(make_pair(dst[s], s));
    while (!pq.empty())
    {
        pa cur = pq.top();
        pq.pop();
        vis[cur.se] = true;
        if (cur.se == t)
        {
            printf("%d\n", cur.fi.hsh);
            trace();
            return;
        }
        for (pair<int, int> &v : adj[cur.se])
        {
            upd(cur.fi, v.se);
            if (tr[v.fi] == 0 || tmp < dst[v.fi])
            {
                tr[v.fi] = cur.se;
                pq.push(make_pair(dst[v.fi] = tmp, v.fi));
            }
        }
        while (!pq.empty() && vis[pq.top().se])
            pq.pop();
    }
    printf("-1");
}

int main()
{
    init();
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &x);
        adj[u].push_back(make_pair(v, x));
        adj[v].push_back(make_pair(u, x));
    }
    scanf("%d%d", &s, &t);
    Dijkstra();
}