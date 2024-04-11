#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
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

#include <experimental/optional>
#define optional std::experimental::optional

namespace asl
{
    
    template <typename T, typename U = T>
    optional<U> noop_get_lazy(T &p)
    {
        return optional<U>();
    }

    template <typename T>
    T add_merge(T &l, T &r) { return l + r; }

} 

namespace asl
{
    
    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

} 

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);

    cin >> a;

    long long res = 0;
    if (n <= 3)
    {
        for (auto x : a)
            res |= x;
    }
    else
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                for (int k = 0; k < j; ++k)
                    res = max(res, a[i] | a[j] | a[k]);
    }

    cout << res << endl;

    return 0;
}