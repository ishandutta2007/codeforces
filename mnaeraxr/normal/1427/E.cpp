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

vec<tuple<i64, bool, i64>> answer;

void add(i64 x, bool op, i64 y)
{
    answer.push_back({x, op, y});
}

void add_sum(i64 x, i64 y)
{
    add(x, true, y);
}

void add_xor(i64 x, i64 y)
{
    add(x, false, y);
}

const int MAX_BIT = 60;

i64 sample(vec<i64> &a)
{
    return a[rand() % a.size()];
}

void solve()
{
    i64 top = 1LL << MAX_BIT;
    i64 n;
    cin >> n;

    vec<i64> gauss(MAX_BIT);
    set<i64> seen;
    vec<i64> order;

    auto check = [&](i64 a, function<void()> callback) {
        if (a >= top)
            return false;

        if (seen.count(a))
            return false;

        seen.insert(a);
        order.push_back(a);
        callback();

        for (int i = MAX_BIT - 1; i >= 0; --i)
        {
            if (a >> i & 1)
            {
                if (gauss[i])
                {
                    a ^= gauss[i];
                    if (!seen.count(a))
                        add_xor(gauss[i], a ^ gauss[i]);
                }
                else
                {
                    gauss[i] = a;
                    return true;
                }
            }
        }

        return false;
    };

    check(n, [] {});
    while (check(2 * n, [&] { add_sum(n, n); }))
        n *= 2;

    while (!gauss[0])
    {
        auto a = sample(order);
        auto b = sample(order);

        if (check(a + b, [&] { add_sum(a, b); }))
        {
            
        }
    }

    cout << answer.size() << endl;
    for (auto [u, op, v] : answer)
    {
        cout << u << " "
             << "^+"[op] << " " << v << endl;
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