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

    typedef __int128 int128;

    std::ostream &operator<<(std::ostream &out, const int128 &num_i)
    {
        if (num_i == 0)
        {
            return out << "0";
        }

        auto num = num_i;

        if (num < 0)
        {
            out << "-";
            num = -num;
        }

        std::vector<char> digits;
        digits.reserve(36);

        while (num)
        {
            digits.push_back('0' + num % 10);
            num /= 10;
        }

        std::reverse(digits.begin(), digits.end());

        for (auto d : digits)
            out << d;

        return out;
    }

    std::istream &operator>>(std::istream &is, int128 &num)
    {
        std::string s;
        is >> s;

        num = 0;

        int p = 0;

        if (s[p] == '-' || s[p] == '+')
            ++p;

        while (p < s.length())
            num = 10 * num + s[p++] - '0';

        if (s[0] == '-')
            num *= -1;

        return is;
    }

    template <typename A, typename B, typename C>
    std::istream &operator>>(std::istream &is, std::tuple<A, B, C> &p)
    {
        return is >> std::get<0>(p) >> std::get<1>(p) >> std::get<2>(p);
    }

    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

    template <typename numeric_type>
    class point
    {
    public:
        numeric_type x, y;

        point(numeric_type x = 0, numeric_type y = 0) : x(x), y(y) {}

        point<numeric_type> &operator-=(const point<numeric_type> &ri)
        {
            x -= ri.x;
            y -= ri.y;
            return *this;
        }

        friend point<numeric_type> operator-(const point<numeric_type> &a, const point<numeric_type> &b)
        {
            return point<numeric_type>(a) -= b;
        }
    };

    template <typename numeric_type>
    numeric_type cross(point<numeric_type> a, point<numeric_type> b)
    {
        return a.x * b.y - a.y * b.x;
    }

    template <typename numeric_type>
    numeric_type dot(point<numeric_type> a, point<numeric_type> b)
    {
        return a.x * b.x + a.y * b.y;
    }

    void asl_assert(bool condition)
    {
    }

    template <typename numeric_type>
    class MonotoneConvexHull
    {
        typedef point<numeric_type> point;

    public:
        int start;
        vec<point> hull;

        MonotoneConvexHull(int n = 0) : start(0)
        {
            hull.reserve(n);
        }
        void push(point p)
        {

            while (size() >= 2 && cross(p - hull[hull.size() - 1], hull[hull.size() - 2] - hull[hull.size() - 1]) >= 0)
                hull.pop_back();

            hull.push_back(p);
        }

        int size() { return hull.size() - start; }

        bool empty() { return start == hull.size(); }

        numeric_type eval(point &p, int ix)
        {
            asl_assert(start <= ix && ix < hull.size());
            return dot(p, hull[ix]);
        }

        numeric_type monotonic_query(point p, bool unchecked = false)
        {
            asl_assert(!empty());

            while (start + 1 < hull.size() && eval(p, start + 1) >= eval(p, start))
                ++start;

            return eval(p, start);
        }
    };

} // namespace asl

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

    vec<tuple<int128, int128, int128>> rec(n);
    cin >> rec;

    sort(rec.begin(), rec.end());

    MonotoneConvexHull<int128> cht(n);

    cht.push({0, 0});

    int128 dp = 0;

    for (auto [x, y, a] : rec)
    {
        auto cur_v = cht.monotonic_query({1, y}, true);
        dp = max(dp, x * y - a + cur_v);
        cht.push({dp, -x});
    }

    cout << dp << endl;

    return 0;
}