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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    long long r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vec<long long> a(n);
    cin >> a;

    vec<long long> dp(5, 1e18);
    dp[1] = 0;

    for (int i = 1; i < n; ++i)
    {
        vec<long long> ndp(5, 1e18);

        for (int x = 1; x <= 4; ++x)
        {
            for (int y = 1; y <= 4; ++y)
            {
                if (y == 4 && i + 1 != n)
                    continue;

                if (x == 2 && y % 2)
                    continue;

                auto cost_0 = r1 * a[i - 1] + r3;
                auto cost_1 = min({cost_0, r1 * (a[i - 1] + 2), r2 + min({r1, r3, r2})});
                auto cost = max(x, y) >= 2 ? cost_1 : cost_0;
                ndp[y] = min(ndp[y], dp[x] + d * y + cost);
            }
        }

        dp.swap(ndp);
    }

    long long res = 1e18;

    for (int i = 1; i <= 2; ++i)
        res = min(res, dp[i] + r1 * a[n - 1] + r3);

    for (int i = 3; i <= 4; ++i)
        res = min(res, dp[i] + min({r1 * a[n - 1] + r3, r1 * (a[n - 1] + 2), r2 + min({r1, r2, r3})}));

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