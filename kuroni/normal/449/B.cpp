#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define fi first
#define se second
using namespace std;

const int N = 100005;
const long long INF = 1E18 + 7;

int n, m, k, u, v, w;
long long dis[N];
bool chk[N];

struct SNode
{
    int u, ind;
    long long v;
};
vector<SNode> adj[N];

inline bool operator>(const SNode &a, const SNode &b)
{
    return a.v > b.v || (a.v == b.v && a.ind > b.ind);
}
priority_queue<SNode, vector<SNode>, greater<SNode>> pq;

void Dijkstra()
{
    fill(dis + 1, dis + n + 1, INF);
    for (pq.push((SNode){1, 0, dis[1] = 0}); !pq.empty(); pq.pop())
    {
        SNode u = pq.top();
        if (chk[u.u])
            continue;
        chk[u.u] = true;
        if (u.ind > 0)
            --k;
        for (SNode &v : adj[u.u])
            if (dis[v.u] >= u.v + v.v)
                pq.push((SNode){v.u, v.ind, dis[v.u] = u.v + v.v});
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back((SNode){v, 0, w});
        adj[v].push_back((SNode){u, 0, w});
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &v, &w);
        adj[1].push_back((SNode){v, i, w});
        adj[v].push_back((SNode){1, i, w});
    }
    Dijkstra();
    printf("%d", k);
}