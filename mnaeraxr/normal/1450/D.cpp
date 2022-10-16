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

namespace asl
{
    
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

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    cin >> n;
    vec<int> a(n + 1);
    vec<int> cnt(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    RMQ<int> rmq(a);

    int one = true;

    for (int i = 1; i <= n; ++i)
        one &= (cnt[i] == 1);

    if (cnt[1] == 0)
    {
        for (int i = 1; i <= n; ++i)
            cout << 0;
        cout << endl;
    }
    else
    {
        int lo = 1, hi = n;
        vec<int> seen(n + 1, -1);

        while (lo + 1 < hi)
        {
            int m = (lo + hi) / 2;

            bool good = true;

            for (int i = 1; i + m <= n + 1 && good; ++i)
            {
                int v = rmq.query(i, i + m);

                if (seen[v] == m)
                {
                    good = false;
                }
                else
                {
                    seen[v] = m;
                }

                if (v > n - m + 1)
                {
                    good = false;
                }

            }

            if (good)
                hi = m;
            else
                lo = m;
        }

        cout << one;

        for (int i = 2; i <= n; ++i)
            cout << (i >= hi);

        cout << endl;
    }
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