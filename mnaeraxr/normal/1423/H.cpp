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

    class DisjointSet
    {
        bool with_path_compression;

    public:
        std::vector<int> ds;

        DisjointSet(int n, bool with_path_compression = true) : with_path_compression(with_path_compression)
        {
            ds = std::vector<int>(n, -1);
        }

        int root(int a)
        {
            if (ds[a] < 0)
                return a;
            else
            {
                if (with_path_compression)
                    return ds[a] = root(ds[a]);
                else
                    return root(ds[a]);
            }
        }

        bool join(int u, int v)
        {
            u = root(u), v = root(v);

            if (u == v)
            {
                on_equal(u);
                return false;
            }

            if (ds[u] < ds[v])
                std::swap(u, v);

            on_join(u, v);

            ds[v] += ds[u];
            ds[u] = v;

            return true;
        }

        int size(int a)
        {
            return -ds[root(a)];
        }

        virtual void on_join(int u, int v)
        {
        }

        virtual void on_equal(int u)
        {
        }
    };
 
    class DisjointSetWithUndo : public DisjointSet
    {
        std::vector<std::pair<int, int>> history;

    public:
        using DisjointSet::DisjointSet;

        DisjointSetWithUndo(int n) : DisjointSet(n, false) {}

        void on_equal(int r)
        {
            history.push_back({r, ds[r]});
            history.push_back({r, ds[r]});
        }

        void on_join(int u, int v)
        {
            history.push_back({v, ds[v]});
            history.push_back({u, ds[u]});
        }

        void undo(int steps = 1)
        {
            assert(history.size() >= 2 * steps);
            for (int i = 0; i < 2 * steps; ++i)
            {
                int u, v;
                std::tie(u, v) = history.back();
                history.pop_back();
                ds[u] = v;
            }
        }
    };

    class Mo
    {
    public:
        class Query
        {
        public:
            int b, e, block, index;
        };

        int low, high;
        std::vector<Query> query;

        std::function<void(int)> add_left;
        std::function<void(int)> add_right;
        std::function<void(int)> remove_left;
        std::function<void(int)> remove_right;
        std::function<void(int)> solve_query;

        Mo() : low(1e9), high(-1e9),
               add_left([](int) {}),
               add_right([](int) {}),
               remove_left([](int) {}),
               remove_right([](int) {}),
               solve_query([](int) {}) {}

        Mo(std::vector<std::pair<int, int>> queries) : Mo()
        {
            query.reserve(queries.size());
            for (auto [b, e] : queries)
                insert_query(b, e);
        }

        void set_add(std::function<void(int)> add)
        {
            add_left = add;
            add_right = add;
        }

        void set_remove(std::function<void(int)> remove)
        {
            remove_left = remove;
            remove_right = remove;
        }

        void insert_query(int b, int e)
        {
            int index = query.size();
            low = std::min(low, b);
            high = std::max(high, e);
            query.push_back({b, e, -1, index});
        }

        virtual void prepare(bool invert_odd = true)
        {
            
            int n = high - low;
            int q = query.size();
            int block_size = std::max((int)(n / sqrt(q)), 1);

            for (auto &u : query)
                u.block = u.b / block_size;

            std::sort(query.begin(), query.end(), [=](Query &a, Query &b) {
                if (a.block != b.block)
                    return a.block < b.block;
                if (invert_odd && (a.block & 1))
                    return a.e > b.e;
                else
                    return a.e < b.e;
            });
        }

        void run_only_pop()
        {
            prepare(false);

            int n = high - low;
            int q = query.size();
            int block_size = std::max((int)(n / sqrt(q)), 1);

            int last_block = -1;
            int b = 0, e = 0;

            for (auto u : query)
            {
                if (u.block != last_block)
                {
                    while (e > b)
                        remove_right(--e);
                    last_block = u.block;
                    b = e = block_size * (u.block + 1);
                }

                int fin_block = u.e / block_size;

                if (fin_block == last_block)
                {
                    for (int i = u.b; i < u.e; ++i)
                        add_right(i);
                    solve_query(u.index);
                    for (int i = u.e - 1; i >= u.b; --i)
                        remove_right(i);
                }
                else
                {
                    while (e < u.e)
                        add_right(e++);

                    int beg_b = b;

                    while (b > u.b)
                        add_left(--b);

                    solve_query(u.index);

                    while (b < beg_b)
                        remove_left(b++);
                }
            }
        }
    };
} 

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, q, k;
    cin >> n >> q >> k;

    vec<pair<int, int>> join_e;
    
    queue<int> que;
    que.push(0);

    vec<int> answer;

    vec<pair<int, int>> pos;
    vec<int> node_ix_vec;

    for (int i = 0; i < q; ++i)
    {
        int m;
        cin >> m;

        if (m == 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            join_e.push_back({u, v});
        }
        else if (m == 2)
        {
            int u;
            cin >> u;
            u--;

            pos.push_back({que.front(), join_e.size()});
            node_ix_vec.push_back(u);
            answer.push_back(0);

        }
        else
        {
            que.push(join_e.size());
            if (que.size() > k)
                que.pop();
        }
    }

    DisjointSetWithUndo ds(n);
    Mo mo(pos);

    mo.set_add([&](int p) {
        ds.join(join_e[p].first, join_e[p].second);
    });

    mo.set_remove([&](int p) {
        ds.undo();
    });

    mo.solve_query = [&](int p) {
        answer[p] = ds.size(node_ix_vec[p]);
    };

    mo.run_only_pop();

    for (auto x : answer)
        cout << x << endl;
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