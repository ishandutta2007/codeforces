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

    template <typename T>
    struct fenwick
    {
        int n;
        std::vector<T> f;
        fenwick(int n) : n(n), f(n + 1) {}

        T query(int p)
        {
            T ret = 0;
            for (++p; p > 0; p -= p & -p)
                ret += f[p];
            return ret;
        }

        void update(int p, T x)
        {
            for (++p; p <= n; p += p & -p)
                f[p] += x;
        }
    };

    template <typename T>
    using BIT = fenwick<T>;
} 

#include <experimental/optional>

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, k;
    cin >> n >> k;
    vec<int> a(n);
    cin >> a;

    vec<BIT<long long>> bits(k + 2, BIT<long long>(n + 1));
    bits[0].update(0, +1);

    for (auto x : a)
        for (int i = 1; i <= k + 1; ++i)
            bits[i].update(x, bits[i - 1].query(x - 1));

    cout << bits[k + 1].query(n) << endl;
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