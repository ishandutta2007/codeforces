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
    
    template <typename A, typename B>
    std::istream &operator>>(std::istream &is, std::pair<A, B> &p)
    {
        return is >> p.first >> p.second;
    }

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

i64 sqr(i64 u)
{
    return u * u;
}

i64 dist(i64 x1, i64 y1, i64 x2, i64 y2)
{
    return sqr(x1 - x2) + sqr(y1 - y2);
}

void solve()
{
    int n;
    i64 x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vec<pair<i64, i64>> a(n);
    cin >> a;

    sort(a.begin(), a.end(), [&](auto flower1, auto flower2) {
        return dist(flower1.first, flower1.second, x1, y1) < dist(flower2.first, flower2.second, x1, y1);
    });

    i64 best = 1e18;

    i64 f1 = 0;

    for (int i = 0; i <= n; ++i)
    {
        i64 cur = 0;
        for (int j = i; j < n; ++j)
        {
            cur = max(cur, dist(x2, y2, a[j].first, a[j].second));
        }

        best = min(best, f1 + cur);

        if (i < n)
            f1 = max(f1, dist(x1, y1, a[i].first, a[i].second));
    }

    cout << best << endl;
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