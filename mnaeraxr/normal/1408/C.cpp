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

#include <tuple>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

double distance(vector<double> &f, double tm)
{
    double last = 0;
    double speed = 1;
    double dist = 0;
    for (auto u : f)
    {
        auto cur_tm = (u - last) / speed;

        if (cur_tm <= tm)
        {
            tm -= cur_tm;
            dist += u - last;
        }
        else
        {
            dist += tm * speed;
            tm = 0;
        }

        last = u;
        speed += 1;
    }

    dist += tm * speed;
    return dist;
}

void solve()
{
    int n;
    double l;
    cin >> n >> l;
    vec<double> f(n);
    cin >> f;

    auto r = f;
    reverse(r.begin(), r.end());
    for (auto &x : r)
        x = l - x;

    double lo = 0, hi = 1;
    int steps = 0;

    while (distance(f, hi) + distance(r, hi) < l)
    {
        ++steps;
        hi *= 2;
    }

    steps += 50;

    while (steps--)
    {
        auto mid = (lo + hi) / 2;

        if (distance(f, mid) + distance(r, mid) < l)
            lo = mid;
        else
            hi = mid;
    }

    cout.precision(15);
    cout << fixed << hi << endl;
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