#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
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
    class DisjointSet
    {
    public:
        std::vector<int> ds;

        DisjointSet(int n)
        {
            ds = std::vector<int>(n, -1);
        }

        int root(int a)
        {
            return ds[a] < 0 ? a : ds[a] = root(ds[a]);
        }

        bool join(int u, int v)
        {
            u = root(u), v = root(v);

            if (u == v)
                return false;

            if (ds[u] < ds[v])
                std::swap(u, v);

            ds[v] += ds[u];
            ds[u] = v;

            return true;
        }

    };
 
    void asl_assert(bool condition)
    {

    }
} 

#include <experimental/optional>
#define optional std::experimental::optional

namespace asl
{
    
    template <typename T, typename U = T>
    optional<U> noop_get_lazy(T &p)
    {
        return optional<U>();
    }

    template <typename T>
    T add_merge(T &l, T &r) { return l + r; }

} 

namespace asl
{
    class Empty
    {
    public:
        Empty() {}
    };

    template <typename edge_type>
    class NodeEdges;

    template <typename edge_type = Empty>
    class Graph
    {
    public:
        int num_nodes;
        
        int num_edges, is_directed, base;
        std::vector<int> head, nxt, to;
        std::vector<edge_type> edges;
        std::vector<int> out_degree, in_degree;

        Graph(int num_nodes, int num_edges = 0, bool is_directed = true, int base = 1)
            : num_nodes(num_nodes), num_edges(num_edges), is_directed(is_directed), base(base)
        {
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
            int edge_ix = nxt.size();
            nxt.push_back(head[src]);
            head[src] = edge_ix;
            edges.push_back(data);
            this->to.push_back(to);
            out_degree[src]++;
            in_degree[to]++;
        }

        void add_directed_edge(int src, int to)
        {
            add_directed_edge_d(src, to, edge_type());
        }

        void add_undirected_edge(int src, int to)
        {
            add_directed_edge(src, to);
            add_directed_edge(to, src);
        }

        NodeEdges<edge_type> operator[](int node_ix)
        {
            return NodeEdges<edge_type>(this, node_ix);
        }

        inline int nodes() const
        {
            return num_nodes;
        }
    };

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
 
    template <typename edge_type>
    bool euler_path_exists(Graph<edge_type> &graph, int start = -1, bool tour = false)
    {
        int n = graph.nodes();
        asl_assert(-1 <= start && start < n);
        int total_odd = 0;

        DisjointSet ds(n);

        int comp = n;

        for (int i = 0; i < n; ++i)
        {
            int deg = 0;
            for (auto e : graph[i])
            {
                if (ds.join(i, e.to()))
                {
                    comp--;
                }

                deg++;
            }

            total_odd += deg & 1;

            if (deg == 0)
            {
                comp--;
            }

            if (total_odd > 2)
                return false;
        }

        if (comp > 1)
        {
            return false;
        }

        if (total_odd == 0 && (start == -1 || graph.out_degree[start] != 0))
        {
            return true;
        }

        if (total_odd == 2 && !tour)
        {
            if (start == -1)
            {
                return true;
            }
            else
            {
                return graph.out_degree[start] & 1;
            }
        }

        return false;
    }

    template <typename edge_type>
    bool euler_tour_exists(Graph<edge_type> &graph, int start = -1)
    {
        return euler_path_exists(graph, start, true);
    }

    template <typename edge_type>
    std::vector<int> euler_path(Graph<edge_type> &graph, int start = -1, bool edge_index = false)
    {
        int n = graph.nodes(), m = 0;
        for (int i = 0; i < n; ++i)
        {
            m += graph.out_degree[i];

            if (graph.out_degree[i])
            {
                if (start == -1 || (graph.out_degree[i] & 1) > (graph.out_degree[start] & 1))
                {
                    start = i;
                }
            }
        }

        m /= 2;

        std::vector<int> path;
        auto pos = graph.head;
        std::vector<bool> mark(m);

        std::function<void(int)> visit = [&](int u) {
            for (; pos[u] != -1;)
            {
                int v = graph.to[pos[u]];
                int id = pos[u];
                pos[u] = graph.nxt[pos[u]];

                if (!mark[id / 2])
                {
                    mark[id / 2] = true;
                    visit(v);
                    path.push_back(id);
                }
            }
        };

        visit(start);
        reverse(path.begin(), path.end());

        if (!edge_index)
        {
            std::vector<int> n_path(m + 1);
            int ix = 0;
            n_path[ix++] = start;

            for (auto e : path)
            {
                n_path[ix++] = graph.to[e];
            }

            path.swap(n_path);
        }

        return path;
    }

} 

#include <random>

#define endl '\n'

using namespace asl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(2 * n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[2 * i] >> v[2 * i + 1];
    }

    int lo = 0, hi = 21;

    while (lo + 1 < hi)
    {
        int m = (lo + hi) / 2;

        int mask = (1 << m) - 1;
        Graph<> graph(1 << m);

        for (int i = 0; i < 2 * n; i += 2)
        {
            int a = v[i], b = v[i + 1];
            a &= mask;
            b &= mask;
            graph.add_undirected_edge(a, b);
        }

        if (euler_tour_exists(graph))
        {
            lo = m;
        }
        else
        {
            hi = m;
        }
    }

    cout << lo << endl;

    int mask = (1 << lo) - 1;
    Graph<> graph(1 << lo);

    for (int i = 0; i < 2 * n; i += 2)
    {
        int a = v[i], b = v[i + 1];
        a &= mask;
        b &= mask;
        graph.add_undirected_edge(a, b);
    }

    auto path = euler_path(graph, -1, true);

    for (auto e : path)
    {
        cout << e + 1 << " " << (e ^ 1) + 1 << " ";
    }

    return 0;
}