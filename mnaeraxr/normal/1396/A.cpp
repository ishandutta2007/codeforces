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

long long extended_euclid(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long r = extended_euclid(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

void solve()
{
    int n;
    cin >> n;

    vec<long long> a(n);
    cin >> a;

    if (n == 1)
    {
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        return;
    }

    long long u = n, v = n - 1, x, y;
    assert(extended_euclid(u, v, x, y) == 1);
    assert(u * x + v * y == 1);

    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; ++i)
    {
        auto c = -u * x * a[i];
        cout << c << " ";
        a[i] += c;
    }
    cout << endl;

    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        assert(a[i] % (n - 1) == 0);
        cout << -a[i] << " ";
    }
    cout << endl;

    cout << n << " " << n << endl;
    cout << -a[n - 1] << endl;
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