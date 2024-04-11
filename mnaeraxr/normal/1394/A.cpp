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
    int n, d, m;
    cin >> n >> d >> m;

    vec<long long> a(n); cin >> a;

    for (int i= 0; i <= d; ++i) a.push_back(0);
    sort(a.begin(), a.end());

    n = a.size();

    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    int p = 1;

    while (p < n && a[p] - a[p - 1] <= m)
        ++p;

    int tot_big = n - p;
    long long res = 0;

    for (int i = 0; i <= tot_big; ++i) {
        if (1LL * i * (d + 1) < tot_big)
            continue;

        if (1LL * i * (d + 1) > n - 1)
            continue;

        long long need = 1LL * i * (d + 1) - tot_big;

        assert(need <= p - 1);

        long long cur = a[n - 1] - a[n - 1 - i] + a[p - 1] - a[need];

        res = max(res, cur);
    }

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