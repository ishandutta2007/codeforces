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
 
    const int m1000000007 = 1000000007;
    
    const int m998244353 = 998244353;

    int MOD = m1000000007;

    void set_mod(int mod)
    {
        MOD = mod;
    }

    class Mint
    {
    public:
        int val;

        Mint(long long v = 0)
        {
            if (v >= 0)
            {
                if (v < MOD)
                    val = v;
                else
                    val = v % MOD;
            }
            else
            {
                if (v >= -MOD)
                {
                    val = v + MOD;
                }
                else
                {
                    v %= MOD;
                    if (v < 0)
                        v += MOD;
                    val = v;
                }
            }
        }

        Mint &operator+=(const Mint &other)
        {
            val += other.val;
            if (val >= MOD)
                val -= MOD;
            return *this;
        }

        Mint &operator-=(const Mint &other)
        {
            val -= other.val;
            if (val < 0)
                val += MOD;
            return *this;
        }

        static unsigned fast_mod(uint64_t x, unsigned m = MOD)
        {
#if !defined(_WIN32) || defined(_WIN64)
            return x % m;
#endif
            
            unsigned x_high = x >> 32, x_low = (unsigned)x;
            unsigned quot, rem;
            asm("divl %4\n"
                : "=a"(quot), "=d"(rem)
                : "d"(x_high), "a"(x_low), "r"(m));
            return rem;
        }

        Mint &operator*=(const Mint &other)
        {
            val = fast_mod((uint64_t)val * other.val);
            return *this;
        }

        friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
        friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
        
        Mint pow(long long p) const
        {
            asl_assert(p >= 0);

            Mint a = *this, result = 1;

            while (p > 0)
            {
                if (p & 1)
                    result *= a;

                a *= a;
                p >>= 1;
            }

            return result;
        }

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
 
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

        int index()
        {
            return edge_ix;
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

using namespace std;
using namespace asl;

void fix(pair<int, int> &a)
{
    while (a.second >= (1 << min(a.first, 20)))
    {
        a.second -= (1 << min(a.first, 20));
        a.first++;
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    fix(a);
    fix(b);
    return a < b;
}

void minimize(pair<int, int> &a, pair<int, int> b)
{
    if (compare(b, a))
        a = b;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    Graph<> g(n, m, false);
    cin >> g;

    auto get = [&](i64 cost) {
        typedef tuple<i64, int, int, int> state;
        priority_queue<state, vec<state>, greater<state>> pq;
        vec<i64> dist(2 * n, 2LL * n * 1e9);
        dist[0] = 0;
        pq.push({dist[0], 0, 0, 0});

        int fbad, fgood;

        while (!pq.empty())
        {
            i64 d;
            int bad, good;
            int u;
            tie(d, bad, good, u) = pq.top();
            pq.pop();

            if (u / 2 == n - 1)
            {
                fbad = bad;
                fgood = good;
                break;
            }

            for (auto e : g[u / 2])
            {
                i64 nd, nbad, ngood, v;

                if ((e.index() & 1) == (u & 1))
                {
                    nd = d + 1;
                    ngood = good + 1;
                    nbad = bad;
                }
                else
                {
                    nbad = bad + 1;
                    ngood = good;
                    nd = d + cost;
                }

                v = (2 * e.to()) | (e.index() & 1);

                if (nd < dist[v])
                {
                    dist[v] = nd;
                    pq.push({dist[v], nbad, ngood, v});
                }
            }
        }

        return make_pair(fbad, fgood);
    };

    int lo = 0, hi = 1e9;

    auto vhi = get(hi);
    auto vlo = get(lo);

    pair<int, int> best = vhi;
    minimize(best, vlo);

    auto go = y_combinator([&](auto self, int lo, int hi, int blo, int bhi) -> void {
        if (blo <= bhi + 1)
            return;
        if (hi <= lo + 1)
            return;

        int mid = (lo + hi) / 2;
        auto cur = get(mid);
        minimize(best, cur);

        self(lo, mid, blo, cur.first);
        self(mid, hi, cur.first, bhi);
    });

    go(lo, hi, vlo.first, vhi.first);

    cout << Mint(2).pow(best.first) - 1 + best.second + best.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m998244353);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}