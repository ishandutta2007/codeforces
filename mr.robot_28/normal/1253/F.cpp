#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
 
struct Edge
{
    Edge(int u, int v, long long w) : start(u), end(v), weight(w) {}
    int start, end;
    long long weight;
 
    bool operator <(const Edge &other) const
    {
        return (other.weight < weight);
    }
};
 
const int MAXN = 2e5;
const int LOGN = 18;
 
std::vector<Edge> graph[MAXN];
std::priority_queue<Edge> dijkstra;
 
int closestSpecial[MAXN];
long long distToClosest[MAXN];
 
std::vector<Edge> paths;
int component[MAXN];
std::vector<Edge> specTree[MAXN];
 
int depth[MAXN];
int ancester[MAXN][LOGN];
long long weightToAnc[MAXN][LOGN];
 
 
void computeinfluence()
{
    while (!dijkstra.empty())
    {
        int special = dijkstra.top().start;
        int node = dijkstra.top().end;
        long long dist = dijkstra.top().weight;
        dijkstra.pop();
 
        if (closestSpecial[node] != -1)
            continue;
        closestSpecial[node] = special;
        distToClosest[node] = dist;
 
        for (Edge &edge : graph[node])
            dijkstra.emplace(special, edge.end, dist + edge.weight);
    }
}
 
int find(int node)
{
    if (node != component[node])
        component[node] = find(component[node]);
    return component[node];
}
 
void merge(Edge &edge)
{
    if (find(edge.start) != find(edge.end))
    {
        component[find(edge.end)] = find(edge.start);
        specTree[edge.start].emplace_back(edge.start, edge.end, edge.weight);
        specTree[edge.end].emplace_back(edge.end, edge.start, edge.weight);
    }
}
 
void root(int node)
{
    for (Edge &edge : specTree[node])
        if (edge.end != ancester[node][0])
        {
            ancester[edge.end][0] = node;
            weightToAnc[edge.end][0] = edge.weight;
            depth[edge.end] = depth[node] + 1;
            root(edge.end);
        }
}
 
int getanc(int node, int exp)
{
    if (ancester[node][exp] == -1)
        ancester[node][exp] = getanc(getanc(node, exp - 1), exp - 1);
    return ancester[node][exp];
}
 
long long getweighttoanc(int node, int exp)
{
    if (weightToAnc[node][exp] == 0)
        weightToAnc[node][exp] = std::max(getweighttoanc(node, exp - 1), getweighttoanc(getanc(node, exp - 1), exp - 1));
    return weightToAnc[node][exp];
}
 
int lift(int node, int dist)
{
    if (dist == 0)
        return node;
    int exp = 31 - __builtin_clz(dist);
    return lift(getanc(node, exp), dist - (1 << exp));
}
 
long long liftw(int node, int dist)
{
    if (dist == 0)
        return 0;
    int exp = 31 - __builtin_clz(dist);
    return std::max(liftw(getanc(node, exp), dist - (1 << exp)), getweighttoanc(node, exp));
}
 
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        std::swap(u, v);
    u = lift(u, depth[u] - depth[v]);
 
    if (u == v)
        return u;
    for (int iExp = 31 - __builtin_clz(depth[u]); iExp > -1; iExp--)
        if (getanc(u, iExp) != getanc(v, iExp))
        {
            u = getanc(u, iExp);
            v = getanc(v, iExp);
        }
 
    return getanc(u, 0);
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
 
    int nodes, edges, special, queries;
    std::cin >> nodes >> edges >> special >> queries;
   
    for (int iEdge = 0; iEdge < edges; iEdge++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
 
        graph[u].emplace_back(u, v, w);
        graph[v].emplace_back(v, u, w);
    }
 
    for (int iSpec = 0; iSpec < special; iSpec++)
        dijkstra.emplace(iSpec, iSpec, 0);
    for (int iNode = 0; iNode < nodes; iNode++)
        closestSpecial[iNode] = -1;
    computeinfluence();
 
    for (int iNode = 0; iNode < nodes; iNode++)
    {
        component[iNode] = iNode;
        for (Edge &edge : graph[iNode])
            if (closestSpecial[iNode] != closestSpecial[edge.end])
                paths.emplace_back(closestSpecial[iNode], closestSpecial[edge.end], distToClosest[iNode] + edge.weight + distToClosest[edge.end]);
    }
 
    std::sort(paths.rbegin(), paths.rend());
    for (Edge &path : paths)
        merge(path);
 
    std::fill_n((int *)ancester, special * LOGN, -1);
    root(0);
 
    for (int iQuery = 0; iQuery < queries; iQuery++)
    {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
 
        int w = lca(u, v);
        std::cout << std::max(liftw(u, depth[u] - depth[w]), liftw(v, depth[v] - depth[w])) << ' ';
    }
 
    std::cout << '\n';
 
    return 0;
}