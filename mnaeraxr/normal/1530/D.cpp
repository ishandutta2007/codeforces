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

} 

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

struct Ds
{
    vec<int> p;

    Ds(int n) : p(n)
    {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }

};

void solve()
{
    int n;
    cin >> n;
    vec<int> a(n);
    cin >> a;
    for (auto &x : a)
        --x;

    vec<bool> in(n), out(n);
    vec<int> p(n), r(n, -1);

    Ds ds(n);

    auto point = [&](int u, int v)
    {
        p[u] = v;
        r[v] = u;
        out[u] = true;
        in[v] = true;
    };

    for (int i = 0; i < n; ++i)
    {
        int u = a[i];

        if (!in[u])
            point(i, u);
    }

    vec<int> rin, rout;
    for (int i = 0; i < n; ++i)
        if (!in[i] && !out[i])
        {
            rin.push_back(i);
            rout.push_back(i);
        }

    for (int i = 0; i < n; ++i)
        if (!in[i] && out[i])
            rin.push_back(i);

    for (int i = 0; i < n; ++i)
        if (in[i] && !out[i])
            rout.push_back(i);

    if (rin.size() == 1)
    {
        if (rin[0] == rout[0])
        {
            int i = rin[0];
            int u = a[i];
            int v = r[u];
            point(v, i);
            point(i, u);
        }
        else
        {
            point(rout[0], rin[0]);
        }
    }
    else
    {
        int t = rin.size();
        for (int i = 0; i < t; ++i)
            point(rout[i], rin[(i + 1) % t]);
    }

    vec<bool> used(n);
    int good = 0;
    for (int i = 0; i < n; ++i)
    {
        assert(p[i] != i);
        assert(!used[p[i]]);
        used[p[i]] = true;

        if (p[i] == a[i])
            good++;
    }

    cout << good << endl;
    for (int i = 0; i < n; ++i)
        cout << p[i] + 1 << " ";
    cout << endl;
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