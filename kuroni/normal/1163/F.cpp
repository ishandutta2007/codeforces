#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 2E5 + 5, M = 2E5 + 5;
const long long INF = 1E18 + 7;

int n, m, q, ed, nw, mx, u[M], v[M], w[M], ind[M];
int tr[N], le[N], ri[N];
bool on_path[N];
long long dis[2][N];

struct TNode
{
    int u;
    long long val;

    TNode(int _u, long long _val)
    {
        u = _u;
        val = _val;
    }

    inline bool operator>(const TNode &oth) const
    {
        return val > oth.val;
    }
};
priority_queue<TNode, vector<TNode>, greater<TNode>> pq;

struct TEdge
{
    int v, w, ind;

    TEdge(int _v, int _w, int _ind)
    {
        v = _v;
        w = _w;
        ind = _ind;
    }
};
vector<TEdge> adj[N];

struct TTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

    long long tr[4 * M];

    void build(int l, int r, int i)
    {
        tr[i] = INF;
        if (l == r)
            return;
        build(l, m, lc);
        build(m + 1, r, rc);
    }

    void upd(int l, int r, int i, int L, int R, long long v)
    {
        if (l > R || r < L || L > R)
            return;
        if (L <= l && r <= R)
        {
            tr[i] = min(tr[i], v);
            return;
        }
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
    }

    long long que(int l, int r, int i, int u)
    {
        if (l == r)
            return tr[i];
        return min(tr[i], u <= m ? que(l, m, lc, u) : que(m + 1, r, rc, u));
    }

#undef m
#undef lc
#undef rc
} seg;

void dijkstra(int st, long long dis[], int get = 0)
{
    fill(dis + 1, dis + n + 1, INF);
    pq.push(TNode(st, dis[st] = 0));
    while (!pq.empty())
    {
        TNode u = pq.top(); pq.pop();
        if (u.val > dis[u.u])
            continue;
        for (TEdge &v : adj[u.u])
            if (dis[v.v] > u.val + v.w)
            {
                tr[v.v] = v.ind;
                if (get == 1 && !on_path[v.v])
                    le[v.v] = le[u.u];
                else if (get == 2 && !on_path[v.v])
                    ri[v.v] = ri[u.u];
                pq.push(TNode(v.v, dis[v.v] = u.val + v.w));
            }
    }
}

void trace()
{
    on_path[1] = true; le[1] = ri[1] = 0;
    for (int i = 1, cur = 1; cur != n; i++)
    {
        int edge = tr[cur];
        ind[edge] = mx = i;
        cur = u[edge] ^ v[edge] ^ cur;
        on_path[cur] = true;
        le[cur] = ri[cur] = i;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", u + i, v + i, w + i);
        ind[i] = -1;
        adj[u[i]].push_back(TEdge(v[i], w[i], i));
        adj[v[i]].push_back(TEdge(u[i], w[i], i));
    }
    dijkstra(n, dis[1]); // reverse the initial dijkstra for the trace to increase from 1 -> n
    trace();
    dijkstra(1, dis[0], 1);
    dijkstra(n, dis[1], 2);
    seg.build(1, mx, 1);
    for (int i = 1; i <= m; i++)
        if (ind[i] == -1)
        {
            seg.upd(1, mx, 1, le[u[i]] + 1, ri[v[i]], dis[0][u[i]] + w[i] + dis[1][v[i]]);
            seg.upd(1, mx, 1, le[v[i]] + 1, ri[u[i]], dis[0][v[i]] + w[i] + dis[1][u[i]]);
        }
    while (q--)
    {
        scanf("%d%d", &ed, &nw);
        long long ans;
        if (ind[ed] > 0)
        {
            ans = dis[0][n] - w[ed] + nw;
            if (nw > w[ed])
                ans = min(ans, seg.que(1, mx, 1, ind[ed]));
        }
        else
        {
            ans = dis[0][n];
            if (nw < w[ed])
            {
                ans = min(ans, dis[0][u[ed]] + nw + dis[1][v[ed]]);
                ans = min(ans, dis[0][v[ed]] + nw + dis[1][u[ed]]);
            }
        }
        printf("%lld\n", ans);
    }
}