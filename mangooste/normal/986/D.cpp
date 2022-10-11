#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

namespace FFT {
    template<typename T>
    struct complex {
        T x, y;

        complex() : x(0), y(0) {}
        complex(T x, T y) : x(x), y(y) {}

        complex operator*(const complex &c) const {
            return complex(x * c.x - y * c.y, x * c.y + y * c.x);
        }

        complex operator+(const complex &c) const {
            return complex(x + c.x, y + c.y);
        }

        complex operator-(const complex &c) const {
            return complex(x - c.x, y - c.y);
        }

        template<typename value_t>
        complex operator/(const value_t &value) const {
            return complex(x / value, y / value);
        }

        complex conj() const {
            return complex(x, -y);
        }
    };

    template<typename float_t = long double>
    void fft(std::vector<complex<float_t>> &a) {
        static std::vector<int> reversed_mask;
        static std::vector<complex<float_t>> roots = std::vector<complex<float_t>>(1);
        static constexpr float_t PI = acos(-1);

        if (a.empty())
            return;

        int n = int(a.size());
        assert((n & (n - 1)) == 0);

        if (int(reversed_mask.size()) != n) {
            int lg = std::__lg(n);
            reversed_mask.resize(n);
            for (int mask = 1; mask < n; mask++)
                reversed_mask[mask] = (reversed_mask[mask >> 1] >> 1) + ((mask & 1) << (lg - 1));
        }

        if (int(roots.size()) < n) {
            int prev_size = roots.size();
            roots.resize(n);
            for (int len = prev_size; len < n; len <<= 1)
                for (int i = 0; i < len; i++)
                    roots[len + i] = complex<float_t>(cos(PI * i / len), sin(PI * i / len));
        }

        for (int i = 0; i < n; i++)
            if (i < reversed_mask[i])
                std::swap(a[i], a[reversed_mask[i]]);

        for (int len = 1; len < n; len <<= 1)
            for (int i = 0; i < n; i += (len << 1))
                for (int j = 0; j < len; j++) {
                    complex<float_t> value = a[i + j + len] * roots[len + j];
                    a[i + j + len] = a[i + j] - value;
                    a[i + j] = a[i + j] + value;
                }
    }

    template<typename result_t, typename float_t = long double, typename T1, typename T2>
    std::vector<result_t> multiply(T1 a_begin, T1 a_end, T2 b_begin, T2 b_end) {
        static constexpr float_t PI = acos(-1);

        if (a_begin == a_end || b_begin == b_end)
            return {};

        int real_size = std::distance(a_begin, a_end) + std::distance(b_begin, b_end) - 1;
        int base = 2;
        while (base < real_size)
            base <<= 1;

        std::vector<complex<float_t>> res(base);
        for (int i = 0; a_begin != a_end; i++, a_begin++)
            res[i].x = *a_begin;

        for (int i = 0; b_begin != b_end; i++, b_begin++)
            res[i].y = *b_begin;

        fft<float_t>(res);
        complex<float_t> coeff(0, float_t(-0.25) / base);
        for (int i = 0; i <= (base >> 1); i++) {
            int j = (base - i) & (base - 1);
            complex<float_t> num = (res[j] * res[j] - (res[i] * res[i]).conj()) * coeff;
            res[j] = (res[i] * res[i] - (res[j] * res[j]).conj()) * coeff;
            res[i] = num;
        }
        // now fft(product) == res

        for (int i = 0; i < (base >> 1); i++) {
            complex<float_t> a0 = (res[i] + res[i + (base >> 1)]);
            complex<float_t> a1 = (res[i] - res[i + (base >> 1)]) * complex<float_t>(cos(PI * i / (base >> 1)), sin(PI * i / (base >> 1)));
            res[i] = a0 + a1 * complex<float_t>(0, 1);
        }

        res.resize(base >> 1);
        fft<float_t>(res);
        std::vector<result_t> product(real_size);

        for (int i = 0; i < real_size; i++)
            product[i] = ((i & 1) ? res[i >> 1].y : res[i >> 1].x) + (std::is_integral<result_t>::value) * float_t(0.5);

        return product;
    }

    template<typename T>
    std::vector<T> normilize(std::vector<T> pol) {
        while (!pol.empty() && pol.back() == 0)
            pol.pop_back();

        return pol;
    }

    template<typename float_t = long double>
    void fft_2d(std::vector<std::vector<complex<float_t>>> &a, bool invert) {
        for (int rot : {0, 1}) {
            for (auto &v : a) {
                fft<float_t>(v);
                if (invert) {
                    std::reverse(v.begin() + 1, v.end());
                    for (auto &x : v)
                        x = x / v.size();
                }
            }

            for (int i = 0; i < int(a.size()); i++)
                for (int j = 0; j < i; j++)
                    std::swap(a[i][j], a[j][i]);
        }
    }

    template<typename result_t, typename float_t = long double, typename T1, typename T2>
    std::vector<std::vector<result_t>> multiply_2d(T1 a_begin, T1 a_end, T2 b_begin, T2 b_end) {
        if (a_begin == a_end || b_begin == b_end || (*a_begin).empty() || (*b_begin).empty())
            return {};

        int real_size_x = std::distance(a_begin, a_end) + std::distance(b_begin, b_end) - 1;
        int real_size_y = int((*a_begin).size() + (*b_begin).size()) - 1;
        int base = 2;
        while (base < std::max(real_size_x, real_size_y))
            base <<= 1;

        auto get = [&](auto a_begin, auto a_end) {
            std::vector<std::vector<complex<float_t>>> a(base, std::vector<complex<float_t>>(base));
            for (int i = 0; a_begin != a_end; i++, a_begin++)
                for (int j = 0; j < int((*a_begin).size()); j++)
                    a[i][j].x = (*a_begin)[j];

            return a;
        };

        auto a = get(a_begin, a_end), b = get(b_begin, b_end);
        fft_2d<float_t>(a, false);
        fft_2d<float_t>(b, false);

        for (int i = 0; i < base; i++)
            for (int j = 0; j < base; j++)
                a[i][j] = a[i][j] * b[i][j];

        fft_2d<float_t>(a, true);

        std::vector<std::vector<result_t>> product(real_size_x, std::vector<result_t>(real_size_y));
        for (int i = 0; i < real_size_x; i++)
            for (int j = 0; j < real_size_y; j++)
                product[i][j] = a[i][j].x + (std::is_integral<result_t>::value) * float_t(0.5);

        return product;
    }

} // namespace FFT

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string x;
    cin >> x;
    if (len(x) == 1 && x[0] - '0' <= 3) {
        cout << x[0] - '0' << '\n';
        return 0;
    }

/*
rem:
  0: 3 -> 3**(x/3)
  1: 3 -> 3**((x - 1)/3 - 1) * 4
  2: 2 -> 3**((x - 2)/3) * 2

(log3(x)-1) * 3 <= real_x

log3(x) = log10(x) * log3(10)
log10(x) ~ len(x)

0: *3
1: *4
2: *6
3: *9
4: *12
5: *27
*/

    constexpr ld log3_10 = 2.095903274289385;
    int p3 = max<int>(1, (len(x) - 1) * log3_10 - 1);
    constexpr int BASE = 1000, LOG_BASE = 3;

    auto normilize = [&](vector<ll> &a) {
        ll to_add = 0;
        for (int i = 0; i < len(a); i++) {
            to_add += a[i];
            a[i] = to_add % BASE;
            to_add /= BASE;
        }
        for (; to_add; to_add /= BASE) a.push_back(to_add % BASE);
    };

    auto multiply = [&](const vector<ll> &a, const vector<ll> &b) {
        auto c = FFT::multiply<ll>(all(a), all(b));
        normilize(c);
        return c;
    };

    auto multiply_const = [&](vector<ll> a, ll x) {
        for (auto &value : a) value *= x;
        normilize(a);
        return a;
    };

    auto base = y_combinator([&](auto solve, int power) -> vector<ll> {
        if (power == 0) return {1};
        if (power & 1) return multiply_const(solve(power - 1), 3);
        auto res = solve(power >> 1);
        res = multiply(res, res);
        return res;
    })(p3 - 1);

    for (int d = 0;; d++) {
        ll coeff = 1;
        for (int i = 0; i < d / 3; i++) coeff *= 3;
        if (d % 3 == 0) {
            coeff *= 3;
        } else if (d % 3 == 1) {
            coeff *= 4;
        } else {
            coeff *= 6;
        }
        auto cur = multiply_const(base, coeff);

        string str;
        for (int i = 0; i < len(cur); i++) {
            string s = to_string(cur[i]);
            reverse(all(s));
            s.resize(LOG_BASE, '0');
            str += s;
        }
        while (str.back() == '0') str.pop_back();
        reverse(all(str));

        if (pair{len(str), str} >= pair{len(x), x}) {
            cout << 3 * p3 + d << '\n';
            return 0;
        }
    }
}