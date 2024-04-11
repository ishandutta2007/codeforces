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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    cin >> a >> b;

    auto u = *min_element(b.begin(), b.end());
    auto v = *max_element(b.begin(), b.end());

    if (u != v)
    {
        cout << "Yes" << endl;
        return;
    }

    auto c = a;
    sort(c.begin(), c.end());

    if (a == c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}