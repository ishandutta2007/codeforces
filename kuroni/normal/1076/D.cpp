#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 300005, M = 300005;
const long long INF = 1E18 + 7;

int n, m, k, u, v, w, tr[N];
long long dst[N];

struct SEdge
{
    int v, w, ind;
};
vector<SEdge> adj[N];

struct SNode
{
    int u;
    long long v;
};

inline bool operator>(const SNode &a, const SNode &b)
{
    return a.v > b.v;
}
priority_queue<SNode, vector<SNode>, greater<SNode>> pq;

void Dijkstra()
{
    pq.push((SNode){1, 0});
    for (int i = 1; i <= min(n, k + 1); i++)
    {
        SNode u = pq.top();
        pq.pop();
        if (u.u != 1)
            printf("%d ", tr[u.u]);
        for (SEdge &v : adj[u.u])
            if (dst[v.v] > u.v + v.w)
            {
                tr[v.v] = v.ind;
                pq.push((SNode){v.v, dst[v.v] = u.v + v.w});
            }
        while (!pq.empty() && dst[pq.top().u] < pq.top().v)
            pq.pop();
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    fill(dst + 2, dst + n + 1, INF);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back((SEdge){v, w, i});
        adj[v].push_back((SEdge){u, w, i});
    }
    printf("%d\n", min(n - 1, k));
    Dijkstra();
}