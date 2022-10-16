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

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

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

        virtual void on_join(int u, int v)
        {
        }

        virtual void on_equal(int u)
        {
        }
    };
} 

#include <experimental/optional>

namespace asl
{
    int DX[4] = {-1, 0, +1, 0};
    int DY[4] = {0, +1, 0, -1};

    class VBoard
    {
    public:
        int n, m;

        VBoard(int n = 0, int m = 0) : n(n), m(m) {}

        bool inside(int x, int y)
        {
            return 0 <= x && x < n && 0 <= y && y < m;
        }

        int index(int x, int y)
        {
            return x * m + y;
        }

    };

} 

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

int TOTAL;

vector<int> strongly_connected_components(const vector<vector<int>> &g)
{
    int n = g.size();
    vector<vector<int>> scc;
    vector<int> S, B, I(n, -1);

    function<void(int)> dfs = [&](int u)
    {
        B.push_back(I[u] = S.size());
        S.push_back(u);

        for (int v : g[u])
        {
            if (!~I[v])
                dfs(v);
            else
                while (I[v] < B.back())
                    B.pop_back();
        }

        if (I[u] == B.back())
        {
            scc.push_back({});
            B.pop_back();

            while (I[u] < (int)S.size())
            {
                scc.back().push_back(S.back());
                I[S.back()] = n + scc.size();
                S.pop_back();
            }
        }
    };

    for (int u = 0; u < n; ++u)
        if (!~I[u])
            dfs(u);

    TOTAL = scc.size();
    return I;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vec<string> a(n);
    cin >> a;

    vec<int> b(m);
    cin >> b;

    DisjointSet ds(n * m);
    VBoard vir(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '#')
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + DX[k], y = j + DY[k];
                    if (vir.inside(x, y) && a[x][y] == '#')
                        ds.join(vir.index(i, j), vir.index(x, y));
                }

    vec<vec<int>> adj(n * m);

    for (int j = 0; j < m; ++j)
    {
        int r = -1;

        for (int i = 0; i < n; ++i)
        {
            if (a[i][j] == '#')
                r = ds.root(vir.index(i, j));

            if (r != -1)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + DX[k], y = j + DY[k];
                    if (vir.inside(x, y) && a[x][y] == '#')
                    {
                        int f = ds.root(vir.index(x, y));
                        if (f != r)
                        {
                            adj[r].push_back(f);
                            
                        }
                    }
                }
            }
        }
    }

    auto cur = strongly_connected_components(adj);
    vec<bool> source(TOTAL, true);

    for (auto &x : cur)
        x -= n * m + 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int ix = vir.index(i, j);
            int u = ds.root(ix);

            if (u != ix) 
            {
                source[cur[ix]] = false;
                continue;
            }

            int cc = cur[u];

            if (a[i][j] == '.')
            {
                source[cc] = false;
                continue;
            }

            for (auto v : adj[u])
            {
                if (cur[v] != cc)
                {
                    assert(u != v);
                    source[cur[v]] = false;
                }
            }
        }

    int res = 0;

    for (int i = 0; i < TOTAL; ++i)
    {
        if (source[i])
        {
            
            res++;
        }
    }

    cout << res << endl;
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