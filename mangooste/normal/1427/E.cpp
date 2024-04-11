#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

namespace math {
    template<typename T>
    inline vector<pair<T, int>> get_factors(T n) {
        vector<pair<T, int>> factors;
        for (T i = 2; i * i <= n; i++) {
            if (n % i != 0)
                continue;

            factors.emplace_back(i, 0);
            while (n % i == 0) {
                factors.back().second++;
                n /= i;
            }
        }
        if (n != 1)
            factors.emplace_back(n, 1);

        return factors;
    }

    template<typename A, typename B>
    inline bool miller_rabin(A n, A b) {
        A t = n - 1;
        int s = 0;
        while (t % 2 == 0)
            s++, t >>= 1;

        auto power = [&](A a, A b) {
            A prod = 1;
            while (b > 0) {
                if (b & 1)
                    prod = B(prod) * a % n;

                a = B(a) * a % n;
                b >>= 1;
            }
            return prod;
        };

        A x = power(b, t);
        if (x == 1 || x == n - 1)
            return true;

        for (int i = 0; i < s - 1; i++) {
            x = B(x) * x % n;
            if (x == 1)
                return false;

            if (x == n - 1)
                return true;
        }

        return false;
    }

    template<typename A, typename B = __int128>
    inline bool is_prime(A x, const int tests = 20) {
        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

        if (x == 1)
            return false;

        if (x == 2 || x == 3)
            return true;

        if (x % 2 == 0 || x % 3 == 0)
            return false;

        for (int i = 0; i < tests; i++)
            if (!miller_rabin<A, B>(x, rng() % (x - 3) + 2))
                return false;

        return true;
    }

    template<typename A, typename B = __int128>
    inline vector<A> get_prime_divisors(A n) {
        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

        if (n <= 1)
            return {};

        if (is_prime(n))
            return {n};

        while (true) {
            A delta = rng() % n;

            auto f = [&](A x) {
                return (B(x) * x + delta) % n;
            };

            A a = rng() % n;
            A b = f(a);
            while (true) {
                A div = gcd(n, a > b ? a - b : b - a);
                if (div == n)
                    break;

                if (div != 1) {
                    auto left = get_prime_divisors(div);
                    auto right = get_prime_divisors(n / div);
                    left.reserve(left.size() + right.size());

                    for (const A &x : right)
                        left.push_back(x);

                    return left;
                }

                a = f(a);
                b = f(f(b));
            }
        }
    }

    template<typename T>
    inline T phi(T n) {
        T res = n;
        for (T i = 2; i * i <= n; i++) {
            if (n % i != 0)
                continue;

            res /= i;
            res *= i - 1;
            while (n % i == 0)
                n /= i;
        }
        if (n != 1)
            res /= n, res *= n - 1;

        return res;
    }

    template<typename A, typename B = long long>
    pair<B, B> extgcd(A a, A b) {
        if (b == 0)
            return {1, 0};

        auto [x, y] = extgcd(b, a % b);
        return {y, x - y * B(a / b)};
    }
} // namespace math

using math::get_factors;
using math::is_prime;
using math::get_prime_divisors;
using math::phi;
using math::extgcd;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    ll x;
    cin >> x;

    struct op {
        ll x, y;
        char type;
    };
    vector<op> answer;

    int bx = __lg(x);
    for (int i = 0; i < bx; i++)
        answer.push_back({x << i, x << i, '+'});

    answer.push_back({x << bx, x, '^'});
    ll y = (x << bx) ^ x;
    assert(gcd(x, y) == 1);

    auto [a, b] = extgcd(x, y);
    ll coeff = max(-min(a, 0ll) / y + 1, min(b, 0ll) / x + 1);
    a += coeff * y;
    b -= coeff * x;
    assert(a > 0 && b < 0);

    if (b % 2) {
        a += y;
        b -= x;
    }
    assert(((a * x) ^ (-b * y)) == 1);

    auto insert = [&](ll init, ll coeff) {
        int b = __lg(coeff);
        for (int i = 0; i < b; i++)
            answer.push_back({init << i, init << i, '+'});

        ll current = 0;
        for (int i = 0; i <= b; i++)
            if ((coeff >> i) & 1) {
                if (current != 0)
                    answer.push_back({current, init << i, '+'});

                current += init << i;
            }
    };

    insert(x, a);
    insert(y, -b);
    answer.push_back({a * x, -b * y, '^'});

    cout << len(answer) << '\n';
    for (const auto &[x, y, type] : answer)
        cout << x << ' ' << type << ' ' << y << '\n';
}