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

namespace asl
{
    class Permutation : public std::vector<int>
    {
    public:
        Permutation(std::vector<int> v) : std::vector<int>(v) {}

        Permutation inverse()
        {
            int sz = size();

            std::vector<int> res(sz);

            for (int i = 0; i < sz; ++i)
            {
                res[(*this)[i]] = i;
            }

            return Permutation(res);
        }
    };
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

    vector<int> a(n), b(n);

    cin >> a >> b;

    for (auto &x : a)
        x--;
    for (auto &x : b)
        x--;

    a = Permutation(a).inverse();
    b = Permutation(b).inverse();

    map<int, int> freq;

    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        int d = a[i] - b[i];
        if (d < 0)
            d += n;

        res = max(res, ++freq[d]);
    }

    cout << res << endl;

    return 0;
}