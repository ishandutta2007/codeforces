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

i64 check(i64 a, i64 b)
{
    i64 c = 0;

    while (a >= b)
    {
        a /= b;
        c += a;
    }

    return c;
}

void solve()
{
    i64 n, b;
    cin >> n >> b;

    vec<pair<i64, int>> fak;

    for (i64 i = 2; i * i <= b; ++i)
    {
        int t = 0;
        while (b % i == 0)
        {
            b /= i;
            ++t;
        }

        if (t)
            fak.push_back({i, t});
    }

    if (b > 1)
        fak.push_back({b, 1});

    i64 sol = 1e18;

    for (auto [a, b] : fak)
    {
        sol = min(sol, check(n, a) / b);
    }

    cout << sol << endl;
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