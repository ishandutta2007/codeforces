#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
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
    
    void asl_assert(bool condition)
    {

    }
 
#include <stdint.h>

    template <typename T>
    using vec = std::vector<T>;

} 

#include <experimental/optional>

namespace asl
{
    class Empty
    {
    public:
        Empty() {}
    };

    std::istream &operator>>(std::istream &is, Empty &empty)
    {
        return is;
    }

}

namespace asl
{
    
    template <typename edge_type>
    class NodeEdges;

    template <typename edge_type = Empty>
    class Graph
    {

    public:
        
        int num_edges, is_directed, base;
        int num_nodes;
        std::vector<int> head, nxt, to;
        std::vector<edge_type> edges;
        std::vector<int> out_degree, in_degree;

        Graph(int num_nodes, int num_edges = 0, bool is_directed = true, int base = 1)
            : num_nodes(num_nodes), num_edges(num_edges), is_directed(is_directed), base(base)
        {
            asl_assert(0 <= num_nodes);
            asl_assert(0 <= num_edges);
            head = std::vector<int>(num_nodes, -1);
            out_degree = std::vector<int>(num_nodes, 0);
            in_degree = std::vector<int>(num_nodes, 0);

            if (!is_directed)
                num_edges *= 2;

            to.reserve(num_edges);
            nxt.reserve(num_edges);
            edges.reserve(num_edges);
        }

        void add_directed_edge_d(int src, int to, edge_type data)
        {
            asl_assert(0 <= src && src < num_nodes);
            asl_assert(0 <= to && to < num_nodes);
            int edge_ix = nxt.size();
            nxt.push_back(head[src]);
            head[src] = edge_ix;
            edges.push_back(data);
            this->to.push_back(to);
            out_degree[src]++;
            in_degree[to]++;
        }

        void add_edge_d(int src, int to, edge_type data)
        {
            add_directed_edge_d(src, to, data);
            if (!is_directed)
                add_directed_edge_d(to, src, data);
        }

        NodeEdges<edge_type> operator[](int node_ix)
        {
            asl_assert(0 <= node_ix && node_ix < num_nodes);
            return NodeEdges<edge_type>(this, node_ix);
        }

    };

    template <typename edge_type>
    std::istream &operator>>(std::istream &is, Graph<edge_type> &graph)
    {
        int u, v;
        edge_type data;

        for (int i = 0; i < graph.num_edges; ++i)
        {
            is >> u >> v >> data;
            u -= graph.base;
            v -= graph.base;
            graph.add_edge_d(u, v, data);
        }

        return is;
    }

    template <typename edge_type>
    class EdgeIterator
    {
        Graph<edge_type> *graph;
        int edge_ix;

    public:
        EdgeIterator(Graph<edge_type> *graph, int edge_ix) : graph(graph), edge_ix(edge_ix) {}

        EdgeIterator &operator++()
        {
            asl_assert(edge_ix != -1);
            edge_ix = graph->nxt[edge_ix];
            return *this;
        }

        bool operator!=(const EdgeIterator &edge_it)
        {
            asl_assert(graph == edge_it.graph);
            return edge_ix != edge_it.edge_ix;
        }

        int &to()
        {
            return graph->to[edge_ix];
        }

        EdgeIterator &operator*()
        {
            return *this;
        }
    };

    template <typename edge_type>
    class NodeEdges
    {
        Graph<edge_type> *graph;
        int node_id;

    public:
        NodeEdges(Graph<edge_type> *graph, int node_id) : graph(graph), node_id(node_id) {}

        EdgeIterator<edge_type> begin()
        {
            return EdgeIterator<edge_type>(graph, graph->head[node_id]);
        }

        EdgeIterator<edge_type> end()
        {
            return EdgeIterator<edge_type>(graph, -1);
        }
    };

} 

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    Graph<> g(n, m, false, 1);
    cin >> g;

    vec<int> pos(n);

    int u = 0;
    int nxt = 1;
    pos[u] = nxt++;

    vec<int> path;
    path.push_back(u);

    while (true)
    {
        
        for (auto e : g[u])
        {
            if (pos[e.to()] != 0)
            {
                if (nxt - pos[e.to()] >= k + 1)
                {
                    int tot = nxt - pos[e.to()];
                    cout << tot << endl;
                    for (int i = 0; i < tot; ++i)
                        cout << path[path.size() - i - 1] + 1 << " ";
                    cout << endl;
                    return;
                }
            }
        }

        bool ok = false;

        for (auto e : g[u])
        {
            if (pos[e.to()] == 0)
            {
                u = e.to();
                pos[u] = nxt++;
                path.push_back(u);
                ok = true;
                break;
            }
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}