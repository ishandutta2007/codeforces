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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n;
    long long t;
    cin >> n >> t;

    vec<pair<long long, int>> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        a[i].first += a[i - 1].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    long long answer = 0;

    BIT<int> bit(n + 1);

    for (int i = 0, p = 0; i <= n; ++i)
    {
        while (p <= n && a[i].first - a[p].first < t)
        {
            
            bit.update(a[p].second, +1);
            ++p;
        }

        answer += bit.query(a[i].second) - (t > 0);
    }

    cout << answer << endl;
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