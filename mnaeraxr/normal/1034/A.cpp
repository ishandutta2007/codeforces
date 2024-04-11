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

namespace asl
{
    
    template <typename int_type>
    int_type gcd(int_type a, int_type b)
    {
        while (b)
        {
            auto t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
} 

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
    sort(a.begin(), a.end());

    if (a[0] == a.back())
    {
        cout << -1 << endl;
        return;
    }

    int g = 0;

    for (auto x : a)
        g = gcd(g, x);

    for (auto &x : a)
        x /= g;

    int m = max(a);

    vec<int> X(m + 1);
    vec<bool> P(m + 1, true);

    for (auto x : a)
        X[x]++;

    int best = 0;

    for (int i = 2; i <= m; ++i)
    {
        if (!P[i])
            continue;

        int tot = X[i];

        for (int j = 2 * i; j <= m; j += i)
        {
            P[j] = false;
            tot += X[j];
        }

        best = max(best, tot);
    }

    cout << n - best << endl;
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