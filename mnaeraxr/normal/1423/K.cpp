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
    T max(std::vector<T> &vec)
    {
        return *std::max_element(vec.begin(), vec.end());
    }

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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

int sqr(int u)
{
    int lo = 0, hi = 1;
    while (hi * hi <= u)
        hi *= 2;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (mid * mid <= u)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

void solve()
{
    int n;
    cin >> n;

    vec<int> q(n);
    cin >> q;

    int t = max(q);

    vec<int> s(t + 1, 1);

    s[0] = s[1] = 0;

    for (int i = 2; i <= t; ++i)
    {
        if (s[i] == 0)
            continue;

        for (int j = 2 * i; j <= t; j += i)
            s[j] = 0;
    }

    s[1] = 1;

    for (int i = 1; i <= t; ++i)
        s[i] += s[i - 1];

    for (auto u : q)
    {
        cout << s[u] - s[sqr(u)] + 1 << endl;
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