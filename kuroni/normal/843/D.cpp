#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005, M = 100005;
const long long INF = 1E18 + 7;

int n, m, q, u, t, x, lst[N];
long long dst[N], f[N];
queue<int> add[M];

struct SEdge
{
    int v, w, nxt;
}   e[M];

struct SNode
{
    int u;
    long long v;
};

inline bool operator<(const SNode &a, const SNode &b)
{
    return a.v > b.v;
}

void Dijkstra()
{
    fill(dst + 2, dst + n + 1, INF);
    priority_queue<SNode, vector<SNode>, less<SNode>> pq;
    for (pq.push((SNode){1, 0}); !pq.empty(); pq.pop())
    {
        SNode cur = pq.top();
        for (int v = lst[cur.u]; v != 0; v = e[v].nxt)
            if (dst[e[v].v] > cur.v + e[v].w)
                pq.push((SNode){e[v].v, dst[e[v].v] = cur.v + e[v].w});
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &e[i].v, &e[i].w);
        e[i].nxt = lst[u];
        lst[u] = i;
    }
    Dijkstra();
    while (q--)
    {
        scanf("%d%d", &t, &x);
        if (t == 1)
            printf("%lld\n", dst[x] == INF ? -1 : dst[x]);
        else
        {
            for (int i = 1; i <= x; i++)
            {
                scanf("%d", &t);
                e[t].w++;
            }
            fill(f + 2, f + n + 1, INF);
            add[m = 0].push(1);
            for (int i = 0; i <= m; i++)
                while (!add[i].empty())
                {
                    int u = add[i].front();
                    add[i].pop();
                    if (f[u] < i)
                        continue;
                    dst[u] += f[u];
                    for (int v = lst[u]; v != 0; v = e[v].nxt)
                    {
                        long long d = dst[u] + e[v].w - dst[e[v].v];
                        if (f[e[v].v] > i && f[e[v].v] > d && d <= x)
                        {
                            f[e[v].v] = d;
                            add[d].push(e[v].v);
                            m = max(1LL * m, d);
                        }
                    }
                }
        }
    }
}