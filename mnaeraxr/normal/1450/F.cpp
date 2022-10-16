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

    vec<int> v(n);
    cin >> v;

    vec<int> f(n + 1);
    vec<int> sf(n + 1);

    bool ok = true;

    for (int i = 0; i + 1 < n; ++i)
    {
        if (v[i] == v[i + 1])
        {
            f[v[i]] += 2;
            ok = false;
        }
        sf[v[i]]++;
    }
    sf[v[n - 1]]++;

    f[v[0]]++;
    f[v[n - 1]]++;

    if (max(sf) > (n + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }

    f[0] = 2;

    sort(f.begin(), f.end());

    if (ok)
    {
        cout << 0 << endl;
    }
    else
    {
        int s = 0;

        for (int i = 0; i < n; ++i)
            s += f[i];

        int d = min(s, f[n]);

        f[n] -= d;
        s += d;

        cout << s / 2 - 2 + f[n] << endl;
    }
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