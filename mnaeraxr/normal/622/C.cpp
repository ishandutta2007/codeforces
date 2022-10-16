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

    int maxbit(unsigned long long num)
    {
        if (num == 0)
            return -1;

        int res = 0;

        for (int i = 32; i; i >>= 1)
        {
            auto big = num >> i;
            if (big)
            {
                res += i;
                num = big;
            }
        }

        return res;
    }

    template <typename T = int>
    class RMQ
    {
    public:
        std::vector<std::vector<T>> dp;
        std::function<T(T &, T &)> combine;

        RMQ(
            std::vector<T> &a, std::function<T(T &, T &)> combine = [](T &a, T &b) { return std::min(a, b); }) : combine(combine)
        {
            int n = a.size(), lg = maxbit(n);
            dp.resize(lg + 1, std::vector<T>(n));
            dp[0] = a;
            for (int j = 0; j < lg; ++j)
                for (int i = 0; i + (2 << j) <= n; ++i)
                    dp[j + 1][i] = combine(dp[j][i], dp[j][i + (1 << j)]);
        }

        inline T query(int a, int b)
        {
            int l = maxbit(b - a);
            return combine(dp[l][a], dp[l][b - (1 << l)]);
        }

    };
} 

#include <experimental/optional>

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

    vec<int> a(n);
    cin >> a;

    vec<pair<int, int>> b(n);
    vec<pair<int, int>> c(n);

    for (int i = 0; i < n; ++i)
    {
        b[i] = {a[i], i};
        c[i] = {-a[i], i};
    }

    RMQ<pair<int, int>> X(b);
    RMQ<pair<int, int>> Y(c);

    for (int i = 0; i < m; ++i)
    {
        int u, v, x;
        cin >> u >> v >> x;

        u--;

        auto q = X.query(u, v);
        auto w = Y.query(u, v);

        if (q.first != x)
        {
            cout << q.second + 1 << endl;
        }
        else if (-w.first != x)
        {
            cout << w.second + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
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