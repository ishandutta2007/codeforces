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
    template <typename T>
    using vec = std::vector<T>;

} 

#include <experimental/optional>

namespace asl
{
    
    template <typename C, typename R = C>
    class Dinic
    {
    public:
        typedef C flow_type;
        typedef R result_type;

        static_assert(std::is_arithmetic<flow_type>::value, "flow_type must be arithmetic");
        static_assert(std::is_arithmetic<result_type>::value, "result_type must be arithmetic");

        static const flow_type oo = std::numeric_limits<flow_type>::max();

        struct edge
        {
            int src; 
            int dst;
            int rev;
            flow_type cap, flow;

            edge(int src, int dst, int rev, flow_type cap) : src(src), dst(dst), rev(rev), cap(cap), flow(0) {}
        };

        Dinic(int n) : adj(n), que(n), level(n), edge_pos(n) {}

        int add_edge(int src, int dst, flow_type cap, flow_type rcap = 0)
        {
            adj[src].emplace_back(src, dst, (int)adj[dst].size(), cap);
            if (src == dst)
                adj[src].back().rev++;
            adj[dst].emplace_back(dst, src, (int)adj[src].size() - 1, rcap);
            return (int)adj[src].size() - 1 - (src == dst);
        }

        result_type max_flow(int source, int sink)
        {
            result_type flow = 0;
            while (true)
            {
                int front = 0, back = 0;
                std::fill(level.begin(), level.end(), -1);
                for (level[que[back++] = sink] = 0; front < back && level[source] == -1; ++front)
                {
                    int u = que[front];
                    for (const edge &e : adj[u])
                        if (level[e.dst] == -1 && rev(e).flow < rev(e).cap)
                            level[que[back++] = e.dst] = 1 + level[u];
                }
                if (level[source] == -1)
                    break;
                std::fill(edge_pos.begin(), edge_pos.end(), 0);
                std::function<flow_type(int, flow_type)> find_path = [&](int from, flow_type res) {
                    if (from == sink)
                        return res;
                    for (int &ept = edge_pos[from]; ept < (int)adj[from].size(); ++ept)
                    {
                        edge &e = adj[from][ept];
                        if (e.flow == e.cap || level[e.dst] + 1 != level[from])
                            continue;
                        flow_type push = find_path(e.dst, std::min(res, e.cap - e.flow));
                        if (push > 0)
                        {
                            e.flow += push;
                            rev(e).flow -= push;
                            if (e.flow == e.cap)
                                ++ept;
                            return push;
                        }
                    }
                    return static_cast<flow_type>(0);
                };
                for (flow_type f; (f = find_path(source, oo)) > 0;)
                    flow += f;
            }
            return flow;
        }

        std::vector<std::vector<edge>> adj;
        std::vector<int> que;
        std::vector<int> level;
        std::vector<int> edge_pos;

        inline edge &rev(const edge &e) { return adj[e.dst][e.rev]; }
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
    int n, m;
    cin >> n >> m;

    vec<tuple<int, int, int>> edge(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edge[i] = {w, u, v};
    }

    sort(edge.begin(), edge.end());

    int lo = 0, hi = m + 1;

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;

        Dinic<int> dinic(2 * n + 2);

        for (int i = 0; i < mid; ++i)
        {
            int w, u, v;
            tie(w, u, v) = edge[i];

            dinic.add_edge(u + 2, v + n + 2, 1);
        }

        for (int i = 0; i < n; ++i)
        {
            dinic.add_edge(0, i + 2, 1);
            dinic.add_edge(i + n + 2, 1, 1);
        }

        if (dinic.max_flow(0, 1) == n)
            hi = mid;
        else
            lo = mid;
    }

    if (hi == m + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << get<0>(edge[hi - 1]) << endl;
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