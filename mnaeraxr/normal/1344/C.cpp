#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


namespace asl
{
    class Graph
    {
    public:
        int nodes;
        std::vector<std::vector<int>> adj;

        
        Graph(int nodes) : adj(nodes), nodes(nodes) {}

        std::vector<int> &operator[](int u)
        {
            return adj[u];
        }

        void add_directed_edge(int u, int v)
        {
            adj[u].push_back(v);
        }

        Graph reverse()
        {
            Graph rev(nodes);

            for (int u = 0; u < nodes; ++u)
            {
                for (auto v : adj[u])
                {
                    rev.add_directed_edge(v, u);
                }
            }

            return rev;
        }
    };

    /*
        @param base Read nodes from [base, base + nodes)

        Use base = 1 when the first node is 1, and base = 0 when the first node is 0.
        Ultimately the graph will be stored in base 0.
    */
    Graph read_directed_graph(int nodes, int edges, int base = 1)
    {
        Graph g(nodes);

        for (int i = 0; i < edges; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            u -= base;
            v -= base;
            g.add_directed_edge(u, v);
        }

        return g;
    }
 // namespace asl


    std::vector<int> toposort(Graph &graph)
    {
        std::vector<int> deg(graph.nodes);

        for (int u = 0; u < graph.nodes; ++u)
        {
            for (auto v : graph[u])
            {
                deg[v]++;
            }
        }

        std::vector<int> order;

        for (int u = 0; u < graph.nodes; ++u)
        {
            if (deg[u] == 0)
                order.push_back(u);
        }

        for (int i = 0; i < order.size(); ++i)
        {
            int u = order[i];

            for (auto v : graph[u])
            {
                deg[v]--;

                if (deg[v] == 0)
                {
                    order.push_back(v);
                }
            }
        }

        return order;
    }
} // namespace asl


 // namespace asl

 // namespace asl

 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl


namespace asl
{
    class Permutation : public std::vector<int>
    {
    public:
        Permutation(std::vector<int> v) : std::vector<int>(v) {}

        Permutation inverse()
        {
            int sz = size();

            std::vector<int> res(sz);

            for (int i = 0; i < sz; ++i)
            {
                res[(*this)[i]] = i;
            }

            return Permutation(res);
        }
    };
} // namespace asl


#define endl '\n'

using namespace std;
using namespace asl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto graph = read_directed_graph(n, m);
    auto rev = graph.reverse();
    auto order = toposort(graph);

    if (order.size() != n)
    {
        cout << -1 << endl;
        return 0;
    }

    auto rank = Permutation(order).inverse();

    vector<int> le = order, ri = order;

    for (int i = 0; i < n; ++i)
    {
        int u = order[i];
        for (auto v : rev[u])
            le[i] = min(le[i], le[rank[v]]);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        int u = order[i];
        for (auto v : graph[u])
            ri[i] = min(ri[i], ri[rank[v]]);
    }

    int answer = 0;

    for (int i = 0; i < n; ++i)
        if (le[i] == ri[i])
            answer++;

    cout << answer << endl;

    for (int i = 0; i < n; ++i)
    {
        int r = rank[i];
        cout << "EA"[le[r] == ri[r]];
    }
    cout << endl;

    return 0;
}