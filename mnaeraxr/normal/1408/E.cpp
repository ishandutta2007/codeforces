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
} 

#include <experimental/optional>

#include <tuple>

namespace asl
{
    typedef long long i64;
    
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int m, n;
    cin >> m >> n;

    vec<i64> a(m);
    cin >> a;
    vec<i64> b(n);
    cin >> b;

    vec<tuple<i64, int, int>> edges;

    i64 total = 0;

    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;

        vec<int> u(t);
        cin >> u;

        for (auto v : u)
        {
            v--;
            edges.push_back({a[i] + b[v], i, v + m});
            total += a[i] + b[v];
        }
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    DisjointSet ds(n + m);

    for (auto [w, u, v] : edges)
    {
        if (ds.join(u, v))
            total -= w;
    }

    cout << total << endl;
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