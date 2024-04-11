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

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, k;
    cin >> n >> k;

    vec<pair<long long, int>> a(n);

    cin >> a;

    int s = 0;

    for (auto &x : a)
    {
        x.first *= 2;

        if (x.second == 1)
            ++s;
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int z) {
        return make_pair(a[x].second, -a[x].first) < make_pair(a[z].second, -a[z].first);
    });

    long long price = 0;

    if (s < k)
    {
        for (auto x : a)
        {
            if (x.second == 1)
            {
                price += x.first / 2;
            }
            else
            {
                price += x.first;
            }
        }
    }
    else
    {
        for (int i = 0; i < k - 1; ++i)
        {
            price += a[order[i]].first / 2;
        }

        long long cur = a[order.back()].first;

        for (int i = k - 1; i < n; ++i)
        {
            price += a[order[i]].first;

            if (a[order[i]].second == 1 && (i + 1 == n || a[order[i + 1]].second == 2))
            {
                cur = min(cur, a[order[i]].first);
            }
        }

        price -= cur / 2;
    }

    cout.precision(1);
    cout << fixed << 1. * price / 2 << endl;

    for (int i = 0; i < k - 1; ++i)
    {
        cout << 1 << " " << order[i] + 1 << endl;
    }

    cout << n - (k - 1);
    for (int i = k - 1; i < n; ++i)
        cout << " " << order[i] + 1;
    cout << endl;
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