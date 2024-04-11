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
    
    void asl_assert(bool condition)
    {

    }
 
    template <typename numeric_type>
    class point
    {
    public:
        numeric_type x, y;

        point(numeric_type x = 0, numeric_type y = 0) : x(x), y(y) {}

        numeric_type real() const
        {
            return x;
        }

        point<numeric_type> conj() const
        {
            return point(x, -y);
        }

        point<numeric_type> &operator+=(const point<numeric_type> &ri)
        {
            x += ri.x;
            y += ri.y;
            return *this;
        }

        point<numeric_type> &operator-=(const point<numeric_type> &ri)
        {
            x -= ri.x;
            y -= ri.y;
            return *this;
        }

        point<numeric_type> &operator*=(const point<numeric_type> &ri)
        {
            numeric_type _x = x * ri.x - y * ri.y;
            numeric_type _y = x * ri.y + y * ri.x;
            x = _x;
            y = _y;
            return *this;
        }

        point<numeric_type> &operator/=(const numeric_type &ri)
        {
            x /= ri;
            y /= ri;
            return *this;
        }

        friend point<numeric_type> operator+(const point<numeric_type> &a, const point<numeric_type> &b)
        {
            return point<numeric_type>(a) += b;
        }

        friend point<numeric_type> operator-(const point<numeric_type> &a, const point<numeric_type> &b)
        {
            return point<numeric_type>(a) -= b;
        }

        friend point<numeric_type> operator*(const point<numeric_type> &a, const point<numeric_type> &b)
        {
            return point<numeric_type>(a) *= b;
        }

    };

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

    int maxbit(unsigned long long num)
    {
        if (num == 0)
            return -1;

        int res = 0;

        for (int i = 32; i; i >>= 1)
        {
            auto big = num >> i;
            if (big)
            {
                res += i;
                num = big;
            }
        }

        return res;
    }

    bool is_power_of_2(unsigned long long num)
    {
        return (num != 0) && (num & (num - 1)) == 0;
    }
} 

#include <experimental/optional>

namespace asl
{
    typedef double double_type;
    const double PI = acos(-1);

    std::vector<int> rev;
    std::vector<point<double_type>> roots = {{0, 0}, {1, 0}};

    void ensure_size(int bits)
    {
        const int n = 1 << bits;
        if (rev.size() >= n)
            return;

        rev.resize(n);
        for (int i = 1, j = 0; i < n - 1; ++i)
        {
            for (int k = n >> 1; (j ^= k) < k; k >>= 1)
                ;
            rev[i] = j;
        }
        rev[n - 1] = n - 1;
        int cur_bits = maxbit(roots.size());
        roots.resize(n);
        roots[0] = 1;
        for (; cur_bits < bits; ++cur_bits)
        {
            const double theta = 2 * PI / (1 << (cur_bits + 1));
            for (int i = 1 << (cur_bits - 1); i < (1 << cur_bits); i++)
            {
                roots[i << 1] = roots[i];
                double angle_i = theta * (2 * i + 1 - (1 << cur_bits));
                double y = sin(angle_i), x = cos(angle_i);
                roots[(i << 1) + 1] = point<double_type>(x, y);
            }
        }
    }

    void fft_core(point<double_type> a[], int n, int sign = +1)
    {
        asl_assert(std::abs(sign) == 1);
        asl_assert(is_power_of_2(n));

        ensure_size(maxbit(n));
        int shift = maxbit(rev.size() / n);
        if (sign == -1)
            std::reverse(a + 1, a + n);
        for (int i = 1; i < n - 1; ++i)
        {
            int j = rev[i] >> shift;
            if (j < i)
                std::swap(a[i], a[j]);
        }
        for (int m, mh = 1; (m = mh << 1) <= n; mh = m)
            for (int i = 0; i < n; i += m)
                for (int j = 0; j < mh; ++j)
                {
                    point<double_type> u = a[i + j + mh] * roots[mh + j];
                    a[i + j + mh] = a[i + j] - u;
                    a[i + j] = a[i + j] + u;
                }
    }

    template <typename T>
    std::pair<std::vector<point<double_type>>, std::vector<point<double_type>>> ffts(const std::vector<T> &a, const std::vector<T> &b, int n)
    {
        asl_assert(is_power_of_2(n));

        std::vector<point<double_type>> p(n), pa(n), pb(n);
        for (int i = 0; i < n; ++i)
            p[i] = point<double_type>(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);

        fft_core(p.data(), n, +1);

        for (int i = 0; i < n; ++i)
        {
            int j = (n - i) & (n - 1);
            point<double_type> u = p[i], v = p[j].conj();
            pa[i] = (u + v) * point<double_type>(0.5, +0.0);
            pb[i] = (u - v) * point<double_type>(0.0, -0.5);
        }
        return std::make_pair(move(pa), move(pb));
    }

    std::vector<long long> multiply_naive(const std::vector<int> &a, const std::vector<int> &b)
    {
        int n = a.size(), m = b.size();
        std::vector<long long> res(n + m - 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                res[i + j] += 1LL * a[i] * b[j];
        return res;
    }

    std::vector<long long> multiply(const std::vector<int> &a, const std::vector<int> &b)
    {
        if (std::max(a.size(), b.size()) <= 300)
            return multiply_naive(a, b);

        int n = a.size() + b.size() - 1, m = 1;
        while (m < n)
            m *= 2;
        std::vector<point<double_type>> pa, pb;
        tie(pa, pb) = ffts(a, b, m);
        for (int i = 0; i < m; ++i)
        {
            pa[i] /= m;
            pa[i] = pa[i] * pb[i];
        }
        fft_core(pa.data(), m, -1);
        std::vector<long long> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = llround(pa[i].real());
        return ans;
    }

    template <typename F>
    std::vector<F> &operator*=(std::vector<F> &cur, const std::vector<F> &other)
    {
        std::vector<int> cur_int(cur.begin(), cur.end());
        std::vector<int> other_int(other.begin(), other.end());
        auto res = multiply(cur_int, other_int);
        cur = std::vector<F>(res.begin(), res.end());
        return cur;
    }

    template <typename F>
    std::vector<F> &operator*(std::vector<F> cur, const std::vector<F> &other)
    {
        return cur *= other;
    }

} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vec<int> a(x + 1);

    for (int i = 0; i <= n; ++i)
    {
        int u;
        cin >> u;
        a[u] = 1;
    }

    auto b = a;
    reverse(b.begin(), b.end());

    auto c = a * b;

    int q;
    cin >> q;
    vec<int> l(q);
    cin >> l;
    for (auto &x : l)
        x /= 2;
    int top = *max_element(l.begin(), l.end());

    vec<int> sol(top + 1);

    for (int i = x + 1; i < c.size(); ++i)
    {
        if (i - x + y <= top)
        {
            if (c[i])
            {
                sol[i - x + y] = i - x + y;
            }
        }
        else
        {
            break;
        }
    }

    for (int i = 1; i <= top; ++i)
    {
        for (int j = 2 * i; j <= top; j += i)
            sol[j] = max(sol[j], sol[i]);
    }

    for (auto u : l)
    {
        cout << (sol[u] == 0 ? -1 : sol[u] * 2) << " ";
    }
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