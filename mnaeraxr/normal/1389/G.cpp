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

    template <typename T>
    T max(std::vector<T> &vec)
    {
        return *std::max_element(vec.begin(), vec.end());
    }

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
        
    };

}

namespace asl
{
    
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

        void add_undirected_edge_d(int src, int to, edge_type data)
        {
            add_directed_edge_d(src, to, data);
            add_directed_edge_d(to, src, data);
        }

        NodeEdges<edge_type> operator[](int node_ix)
        {
            asl_assert(0 <= node_ix && node_ix < num_nodes);
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

        int index() { return edge_ix; }

        int &to()
        {
            return graph->to[edge_ix];
        }

        edge_type &data()
        {
            return graph->edges[edge_ix];
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

namespace asl
{
    
    template <typename edge_type>
    class Tarjan
    {
        int n, visit_time;
        std::vector<int> num, low;
        std::vector<int> visit_order;

        void dfs(int u, int previous_edge_index)
        {
            num[u] = low[u] = ++visit_time;
            visit_order.push_back(u);

            for (auto e : (*graph)[u])
            {
                int v = e.to();

                if ((e.index() ^ 1) == previous_edge_index)
                    continue;

                if (!num[v])
                {
                    dfs(v, e.index());
                    low[u] = std::min(low[u], low[v]);

                    if (num[u] <= low[v])
                    {
                        if (num[u] != 1 || num[v] > 2)
                            articulations[u] = true;

                        auto &comps = articulations_comps;
                        for (comps.push_back({u}); comps.back().back() != v; visit_order.pop_back())
                            comps.back().push_back(visit_order.back());
                    }

                    if (num[u] < low[v])
                    {
                        int ix = e.index();
                        bridges[ix] = bridges[ix ^ 1] = true;
                    }
                }
                else
                {
                    low[u] = std::min(low[u], num[v]);
                }
            }
        }

        void mark(int u, int comp_id, int p = -1)
        {
            bridges_mapping[u] = comp_id;
            for (auto e : (*graph)[u])
            {
                if (e.to() == p || is_bridge(e.index()) || bridges_mapping[e.to()] != -1)
                    continue;
                mark(e.to(), comp_id, u);
            }
        }

    public:
        std::vector<bool> articulations;
        std::vector<bool> bridges;
        std::vector<std::vector<int>> articulations_comps;
        std::vector<int> bridges_mapping;
        
        Graph<edge_type> *graph;

        Tarjan(Graph<edge_type> *graph) : graph(graph), n(graph->nodes()), visit_time(0)
        {
            articulations.resize(n);
            num.resize(n);
            low.resize(n);
            bridges.resize(graph->edges.size());

            for (int u = 0; u < n; ++u)
            {
                if (num[u] == 0)
                    dfs(u, -1);
            }
        }

        std::vector<int> bridge_node_component_map()
        {
            if (!bridges_mapping.empty())
                return bridges_mapping;

            bridges_mapping.resize(n, -1);
            int comp_id = 0;

            for (int i = 0; i < n; ++i)
                if (bridges_mapping[i] == -1)
                    mark(i, comp_id++);

            return bridges_mapping;
        }

        Graph<edge_type> bridge_tree()
        {
            auto mapping = bridge_node_component_map();
            Graph<edge_type> new_graph(max(mapping) + 1);
            for (int i = 0; i < bridges.size(); i += 2)
            {
                int u = graph->to[i], v = graph->to[i + 1];
                if (is_bridge(i))
                    new_graph.add_undirected_edge_d(mapping[u], mapping[v], graph->edges[i]);
            }
            return new_graph;
        }

        bool is_bridge(int edge_ix) { return bridges[edge_ix]; }

    };
} 

#include <random>

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

#define endl '\n'

using namespace std;
using namespace asl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vec<int> si(k); 
    cin >> si;
    for (auto &x : si)
        x--;

    vec<long long> cost(n);
    cin >> cost;

    vec<long long> weight_cost(m);
    cin >> weight_cost;

    Graph<long long> graph(n, m, false);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph.add_undirected_edge_d(u - 1, v - 1, weight_cost[i]);
    }

    Tarjan t(&graph);

    auto mp = t.bridge_node_component_map();
    auto tree = t.bridge_tree();

    vec<long long> new_cost(tree.nodes());
    vec<int> acc_special(tree.nodes());

    for (int i = 0; i < n; ++i)
        new_cost[mp[i]] += cost[i];

    auto dp = new_cost;
    auto fin_dp = dp;

    for (auto u : si)
        acc_special[mp[u]] = 1;

    int tot_special = 0;
    for (auto x : acc_special)
        tot_special += x;

    auto check = [&](int num) {
        return 0 < num && num < tot_special;
    };

    y_combinator([&](auto self, int s, int p) -> void {
        for (auto e : tree[s])
        {
            if (e.to() == p)
                continue;
            self(e.to(), s);

            dp[s] += max(dp[e.to()] - e.data() * check(acc_special[e.to()]), 0LL);
            acc_special[s] += acc_special[e.to()];
        }
    })(0, -1);

    y_combinator([&](auto self, int s, int p) -> void {
        fin_dp[s] = dp[s];

        for (auto e : tree[s])
        {
            if (e.to() == p)
                continue;

            dp[s] -= max(dp[e.to()] - e.data() * check(acc_special[e.to()]), 0LL);
            acc_special[s] -= acc_special[e.to()];

            dp[e.to()] += max(dp[s] - e.data() * check(acc_special[s]), 0LL);
            acc_special[e.to()] += acc_special[s];

            self(e.to(), s);

            dp[e.to()] -= max(dp[s] - e.data() * check(acc_special[s]), 0LL);
            acc_special[e.to()] -= acc_special[s];

            dp[s] += max(dp[e.to()] - e.data() * check(acc_special[e.to()]), 0LL);
            acc_special[s] += acc_special[e.to()];
        }
    })(0, -1);

    for (int i = 0; i < n; ++i)
        cout << fin_dp[mp[i]] << " ";
    cout << endl;

    return 0;
}