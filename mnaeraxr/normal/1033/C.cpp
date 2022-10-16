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

void solve()
{
    int n;
    cin >> n;
    vec<int> a(n);
    cin >> a;

    vec<int> r(n);
    for (int i = 0; i < n; ++i)
        r[a[i] - 1] = i;

    vec<bool> v(n);

    for (int u = n - 1; u >= 0; --u)
    {
        int p = r[u];

        for (int i = p + a[p]; i < n && !v[p]; i += a[p])
            if (a[p] < a[i] && !v[i])
                v[p] = true;

        for (int i = p - a[p]; i >= 0 && !v[p]; i -= a[p])
            if (a[p] < a[i] && !v[i])
                v[p] = true;
    }

    for (auto x : v)
        cout << "BA"[x];
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