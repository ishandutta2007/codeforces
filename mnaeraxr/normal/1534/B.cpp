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

    vec<i64> a(n);
    cin >> a;

    i64 sol = 0;

    for (int i = 0; i < n; ++i)
    {
        i64 l = i == 0 ? 0 : a[i - 1];
        i64 r = i == n - 1 ? 0 : a[i + 1];

        sol += max(0LL, a[i] - max(l, r));
        a[i] = min(a[i], max(l, r));
        sol += abs(a[i] - l);
        
    }

    sol += a.back();

    cout << sol << endl;
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