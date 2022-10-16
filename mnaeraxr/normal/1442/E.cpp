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

#include <stdint.h>

namespace asl
{
    
    void asl_assert(bool condition)
    {

    }
 
    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

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

#include <utility>

namespace asl
{
    
    template <class Fun>
    class y_combinator_result
    {
        Fun fun_;

    public:
        template <class T>
        explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

        template <class... Args>
        decltype(auto) operator()(Args &&... args)
        {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template <class Fun>
    decltype(auto) y_combinator(Fun &&fun)
    {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }

} 

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

struct two_set
{
    int big, small;

    two_set() : big(0), small(0) {}

    void insert(int u)
    {
        if (u > big)
            swap(big, u);
        if (u > small)
            swap(small, u);
    }

    int sum() { return big + small; }
};

void solve()
{
    int n;
    cin >> n;
    vec<int> col(n);
    cin >> col;
    Graph<> g(n, n - 1, false, 1);
    cin >> g;

    int res = 0;

    auto dfs = y_combinator([&](auto self, int s, int p) -> pair<int, int> {
        two_set black, white;

        for (auto e : g[s])
        {
            int x = e.to();
            if (e.to() == p)
                continue;

            int w, b;
            tie(w, b) = self(e.to(), s);

            if (col[s] == 0)
            {
                black.insert(b);
                white.insert(w);
            }
            else if (col[s] == 1)
            {
                white.insert(b + 1);
                white.insert(w);
            }
            else
            {
                black.insert(w + 1);
                black.insert(b);
            }
        }

        if (col[s] == 1)
            white.insert(1);
        if (col[s] == 2)
            black.insert(1);

        if (col[s] == 0)
        {
            int opt = (white.big + black.big) / 2 + 1;
            res = max(res, opt);
        }

        res = max({res, (black.sum() - 1) / 2 + 1, (white.sum() - 1) / 2 + 1});
        return {white.big, black.big};
    });

    dfs(0, -1);
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}