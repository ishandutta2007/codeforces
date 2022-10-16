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
    typedef long long i64;
    
#include <stdint.h>

    void asl_assert(bool condition)
    {

    }
 
    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
    {
        bool start = true;

        for (auto x : vec)
        {
            if (start)
            {
                start = false;
            }
            else
            {
                out << " ";
            }

            out << x;
        }
        return out;
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
        Empty() {}
    };

    std::istream &operator>>(std::istream &is, Empty &empty)
    {
        return is;
    }

}

namespace asl
{
    
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

} 

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;

    vec<i64> a(n);
    cin >> a;

    Graph<> g(n, n - 1, false, 1);
    cin >> g;

    set<pair<i64, int>> s;

    i64 sum = 0;

    for (auto x : a)
        sum += x;

    vec<int> order(n);

    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int u, int v) { return a[u] > a[v]; });

    vec<i64> res = {sum};

    for (auto u : order)
    {
        for (int i = 1; i < g.in_degree[u]; ++i)
        {
            sum += a[u];
            res.push_back(sum);
        }
    }

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