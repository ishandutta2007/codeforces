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
} // namespace asl

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

} // namespace asl

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;

    vec<pair<int, int>> w(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i].first;
        w[i].second = i;
    }

    RMQ<pair<int, int>> rmq(w);

    vec<pair<int, int>> ans;

    auto go = y_combinator([&](auto self, int x, int y, int v) -> int {
        if (x < y)
        {
            auto u = rmq.query(x, y);
            for (int i = v; i < u.first; ++i)
                ans.push_back({x + 1, y});
            self(x, u.second, u.first);
            self(u.second + 1, y, u.first);
        }
    });

    go(0, n, 0);

    cout << ans.size() << endl;

    for (auto [u, v] : ans)
    {
        cout << u << " " << v << endl;
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