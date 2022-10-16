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

    vec<int> a(n), b(n);
    cin >> a >> b;

    sort(a.begin(), a.end());
    a.push_back(0);
    reverse(a.begin(), a.end());
    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    sort(b.begin(), b.end());
    b.push_back(0);
    reverse(b.begin(), b.end());
    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];

    auto ok = [&](int t)
    {
        int s = (n + t);
        int sp = s - s / 4;

        int ap = min(sp, t) * 100 + a[sp - min(sp, t)];
        int bp = b[min(n, sp)];

        return ap >= bp;
    };

    int lo = -1, hi = 1;

    while (!ok(hi))
        hi *= 2;

    while (lo + 1 < hi)
    {
        int m = (lo + hi) / 2;
        if (ok(m))
            hi = m;
        else
            lo = m;
    }

    cout << hi << endl;
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