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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

vec<pair<int, int>> get(int n)
{
    assert((n & (n - 1)) == 0);

    if (n == 1)
        return {};

    auto cur = get(n / 2);

    int s = cur.size();

    for (int i = 0; i < s; ++i)
    {
        int u, v;
        tie(u, v) = cur[i];
        cur.push_back({u + n / 2, v + n / 2});
    }

    for (int i = 0; i < n / 2; ++i)
        cur.push_back({i + 1, i + 1 + n / 2});

    return cur;
}

void solve()
{
    int n;
    cin >> n;

    int u = 1;

    while (2 * u <= n)
        u *= 2;

    auto res = get(u);

    cout << res.size() * 2 << endl;
    for (auto [u, v] : res)
        cout << u << " " << v << endl;
    for (auto [u, v] : res)
        cout << n - u + 1 << " " << n - v + 1 << endl;
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