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

    template <typename T>
    using vec = std::vector<T>;

} 

#include <experimental/optional>

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n = 0, int m = 0)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m));
    }

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

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, k;
    cin >> n >> k;

    vec<vec<i64>> a(n);

    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        a[i].resize(t + 1);
        for (int j = 1; j <= t; ++j)
        {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }

    i64 answer = 0;
    auto dp = board<i64>(20, k + 1);

    auto apply = [&](vec<i64> &knapsack, int sz, i64 wei) {
        for (int i = k; i >= sz; --i)
            knapsack[i] = max(knapsack[i], knapsack[i - sz] + wei);
    };

    auto dc = y_combinator([&](auto self, int b, int e, int d) -> void {
        if (b + 1 == e)
        {
            for (int i = 0; i <= min(int(a[b].size() - 1), k); ++i)
                answer = max(answer, dp[d][k - i] + a[b][i]);
        }
        else
        {
            int m = (b + e) / 2;
            dp[d + 1] = dp[d];

            for (int i = b; i < m; ++i)
            {
                int sz = min(int(a[i].size() - 1), k);
                apply(dp[d + 1], sz, a[i][sz]);
            }

            self(m, e, d + 1);

            dp[d + 1] = dp[d];
            for (int i = m; i < e; ++i)
            {
                int sz = min(int(a[i].size() - 1), k);
                apply(dp[d + 1], sz, a[i][sz]);
            }

            self(b, m, d + 1);
        }
    });

    dc(0, n, 0);
    cout << answer << endl;
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