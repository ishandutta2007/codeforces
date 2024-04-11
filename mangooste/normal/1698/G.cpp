#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using i128 = __int128;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

ll solve(string s) {
    assert(s[0] == '1' && s.back() == '1');
    int n = len(s);
    if (n == 1) return 1;

    ll num = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') num ^= 1ll << i;
    }

    auto lg = [&](const i128 &x) {
        int lg = 0;
        i128 val = 1;
        while (val <= x) {
            val <<= 1;
            lg++;
        }
        return lg - 1;
    };

    auto divide = [&](i128 a, i128 b) {
        int lg_a = lg(a), lg_b = lg(b);
        i128 div = 0;
        for (int i = lg_a; i >= lg_b; i--) {
            if (a >> i & 1) {
                int shift = i - lg_b;
                div ^= i128(1) << shift;
                a ^= b << shift;
            }
        }
        return pair{div, a};
    };

    auto multiply = [&](i128 a, i128 b) {
        int lg_a = lg(a);
        i128 c = 0;
        for (int i = 0; i <= lg_a; i++) {
            if (a >> i & 1) c ^= b << i;
        }
        return c;
    };

    const int STEP = 1 << (len(s) + 1) / 2;
    unordered_map<ll, int> mp;
    mp.reserve(STEP);
    ll cur = 1;
    for (int step = 0; step < STEP; step++) {
        cur = divide(multiply(cur, 2), num).second;
        if (!mp.count(cur)) mp[cur] = step + 1;
    }

    ll val = 1;
    for (int step = 0; step < STEP; step++) {
        // val(x) * need(x) = 1 mod num(x)
        // val(x) * x + num(x) * y = 1
        // x = need(x)
        bool gcd_one;

        auto [x, y] = y_combinator([&](auto ext_gcd, i128 a, i128 b) -> pair<i128, i128> {
            if (b == 0) {
                gcd_one = a == 1;
                return {1, 0};
            }
            auto [x, y] = ext_gcd(b, divide(a, b).second);
            return {y, x ^ multiply(y, divide(a, b).first)};
        })(val, num);

        if (gcd_one && mp.count(x)) {
            return 1ll * step * STEP + mp[x];
        }
        val = divide(multiply(val, cur), num).second;
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    if (count(all(s), '0') == len(s)) {
        cout << "-1\n";
        return 0;
    }

    int from = 0;
    while (s[from] == '0') from++;
    int to = len(s) - 1;
    while (s[to] == '0') to--;

    ll ans = solve(s.substr(from, to - from + 1));
    if (ans == -1) {
        cout << "-1\n";
    } else {
        cout << from + 1 << ' ' << from + 1 + ans << '\n';
    }
}