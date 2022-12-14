/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
#include <ostream>

bool is_prime(long long n) {
    for (long long d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

/// Modular exponentiation for integers
long long mod_pow(long long val, long long n, long long mod) {
    long long tar = 1;

    while (n) {
        if (n & 1) {
            tar = tar * val % mod;
        }
        n >>= 1;
        val = val * val % mod;
    }

    return tar;
}

/// Given a, b find x, y, g such that:
///
///     a * x + b * y = g
///
long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0)
        return x = 1, y = 0, a;
    long long r = gcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}


/// Find b such that:
///
///     a * b = 1 mod m
///
long long inverse(long long a, long long m) {
    long long x, y;
    long long g = gcd(a, m, x, y);

    if (g != 1) {
        // There is no solution
    }

    x = x % m;
    if (x < 0) x += m;
    return x;
}

template<typename mul_type>
mul_type fast_pow(mul_type val, long long n) {
    mul_type tar = mul_type::one();

    while (n) {
        if (n & 1) {
            tar = tar * val;
        }
        n >>= 1;
        val = val * val;
    }

    return tar;
}

template<long long mod = 1000000007>
class Num {
public:
    long long value;

    Num(long long value = 0) : value(value) {}

    Num zero() {
        return Num(0);
    }

    static Num one() {
        return Num(1);
    }

    Num inv() {
        return inverse(value, mod);
    }

    Num operator+(const long long &right) const {
        long long answer = value;
        answer += right;
        if (answer >= mod)
            answer -= mod;
        return Num(answer);
    }

    Num operator-(const long long &right) const {
        auto neg = right == 0 ? 0 : mod - right;
        return *this + neg;
    }

    Num operator*(const long long &right) const {
        return Num(value * right % mod);
    }

    Num operator/(const long long &right) const {
        return *this * Num(right).inv();
    }

    Num operator+(const Num &right) const {
        return *this + right.value;
    }

    Num operator-(const Num &right) const {
        return *this - right.value;
    }

    Num operator*(const Num &right) const {
        return *this * right.value;
    }

    Num operator/(const Num &right) const {
        return *this / right.value;
    }
};

template<long long mod>
std::ostream &operator<<(std::ostream &os, Num<mod> num) {
    os << num.value;
    return os;
}

using namespace std;

const long long mod = 998244353;

typedef Num<998244353> N;

class FCards {
public:
    void solve(std::istream &in, std::ostream &out) {
        long long n, m, k;
        in >> n >> m >> k;

        auto answer = N(0);

        auto im = N(m).inv();
        auto den = N(1);

        vector<N> x(2);
        x[1] = N(1);

        for (int i = 2; i <= k; ++i) {
            x.push_back(N(1));
            for (int j = i - 1; j; --j) {
                x[j] = x[j] * j + x[j - 1];
            }
        }

        for (int p = 1; p <= min(n, k); ++p) {
            den = den * im;

            auto np = N(1);
            for (int i = 1; i <= p; ++i)
                np = np * (n - i + 1);

            auto xnp = x[p];

            auto cur = den * np * xnp;
            answer = answer + cur;
        }

        out << answer << endl;
    }
};


int main() {
    FCards solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}