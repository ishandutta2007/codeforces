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
    T max(std::vector<T> &vec)
    {
        return *std::max_element(vec.begin(), vec.end());
    }

    template <typename T>
    T min(std::vector<T> &vec)
    {
        return *std::min_element(vec.begin(), vec.end());
    }

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
    int n, m;
    cin >> n >> m;

    vec<vec<pair<int, int>>> adj(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        if (w == 0)
        {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
        else
        {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, -1});
        }
    }

    auto check = [&](int source, bool print) {
        vec<int> d(n, n);

        d[source] = 0;

        bool relaxed = true;

        for (int i = 1; i < n && relaxed; ++i)
        {
            relaxed = false;
            for (int u = 0; u < n; ++u)
                for (auto [v, c] : adj[u])
                {
                    if (d[v] > d[u] + c)
                        d[v] = d[u] + c, relaxed = true;
                }
        }

        for (int u = 0; u < n; ++u)
            for (auto [v, c] : adj[u])
            {
                if (c == 1)
                {
                    if (abs(d[u] - d[v]) != 1)
                        return -1;
                }
                else
                {
                    assert(c == -1);
                    if (d[v] - d[u] != -1)
                        return -1;
                }
            }

        int M = max(d);
        int m = min(d);

        if (print)
        {
            cout << M - m << endl;
            for (int i = 0; i < n; ++i)
                cout << d[i] - m << " ";
            cout << endl;
        }

        return M - m;
    };

    int res = -1;
    int val = -1;

    for (int i = 0; i < n; ++i)
    {
        int d = check(i, false);

        if (d > res)
        {
            res = d;
            val = i;
        }
    }

    if (res != -1)
    {
        cout << "YES" << endl;
        check(val, true);
    }
    else
    {
        cout << "NO" << endl;
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