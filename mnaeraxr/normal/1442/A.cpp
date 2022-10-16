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

namespace asl
{
    typedef long long i64;
    
#include <stdint.h>

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

    vec<i64> a(n), suff(n), pref(n);

    cin >> a;

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            suff[i] = a[i] - a[i - 1];
        }
        else
        {
            pref[i - 1] = a[i - 1] - a[i];
        }
    }

    for (int i = 1; i < n; ++i)
        suff[i] += suff[i - 1];
    for (int i = n - 2; i >= 0; --i)
        pref[i] += pref[i + 1];

    for (int i = 0; i < n; ++i)
    {
        if (suff[i] + pref[i] > a[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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