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
    int n;
    cin >> n;

    vec<i64> a(n);
    cin >> a;

    i64 tot = 0;

    for (auto &x : a)
    {
        tot -= x;
        x *= 2;
    }

    vec<pair<i64, int>> dp(n + 1);

    i64 best = 0;
    int where = n;
    dp[n] = {best, where};

    for (int i = n - 1; i >= 0; --i)
    {
        best += a[i];

        if (best < 0)
        {
            best = 0;
            where = i;
        }

        dp[i] = {best, where};
    }

    i64 foo = 0, x = 0, y = 0, z = 0, pre = 0;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            if (pre + dp[j].first > foo)
            {
                foo = pre + dp[j].first;
                x = i, y = j, z = dp[j].second;
            }
        }

        pre += a[i];
    }

    cout << x << " " << y << " " << z << endl;
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