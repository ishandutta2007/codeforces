#include <bits/stdc++.h>

using namespace std;

template<typename value_t, value_t mod, typename big_t>
struct Modular {
    using mval = Modular<value_t, mod, big_t>;

    value_t val;

    template<typename T>
    static T normalize(T x, value_t m = mod) {
        if (x < -m || x >= 2 * m)
            x %= m;
        if (x >= m)
            x -= m;
        if (x < 0)
            x += m;
        return x;
    }

    template<typename T>
    static inline mval power(mval base, T degree) {
        degree = normalize(degree, mod - 1);
        mval res = 1;
        for (; degree > 0; degree >>= 1) {
            if (degree & 1)
                res *= base;
            base *= base;
        }
        return res;
    }

    inline mval rev() const {
        return power(*this, -1);
    }

    Modular() : val(0) {}
    template<typename T>
    Modular(T x) : val(normalize(x)) {}

    mval operator * (mval x) const {
        return mval(big_t(val) * big_t(x.val));
    }
    mval operator + (mval x) const {
        return mval(val + x.val);
    }
    mval operator - (mval x) const {
        return mval(val - x.val);
    }
    mval operator / (mval x) const {
        return *this * x.rev();
    }

    mval& operator *= (mval x) {
        return *this = *this * x;
    }
    mval& operator += (mval x) {
        return *this = *this + x;
    }
    mval& operator -= (mval x) {
        return *this = *this - x;
    }
    mval& operator /= (mval x) {
        return *this = *this / x;
    }

    mval& operator ++ () {
        val++;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    mval& operator -- () {
        val--;
        if (val < 0)
            val += mod;
        return *this;
    }
    mval operator ++ (int) {
        val++;
        if (val >= mod)
            val -= mod;
        return *this;
    }
    mval operator -- (int) {
        val--;
        if (val < 0)
            val += mod;
        return *this;
    }

    friend istream& operator >> (istream &in, mval &val) {
        value_t x;
        in >> x;
        val = mval(x);
        return in;
    }
    friend ostream& operator << (ostream &out, mval val) {
        return out << val.val;
    }
};

constexpr int MOD = int(1e9) + 7;
// constexpr int MOD = 998244353;
using mint = Modular<int, MOD, long long>;

const int N = 2e5 + 4;
vector<int> p(N);

map<int, int> factor(int x) {
    map<int, int> divs;
    while (x != 1) {
        int prime = p[x];
        while (x % prime == 0) {
            divs[prime]++;
            x /= prime;
        }
    }
    return divs;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    iota(p.begin(), p.end(), 0);
    for (int i = 2; i < N; i++)
        if (p[i] == i)
            for (int j = 2 * i; j < N; j += i)
                if (p[j] == j)
                    p[j] = i;

    int n, q;
    cin >> n >> q;
    vector<map<int, int>> divs(n);
    vector<multiset<int>> powers(N);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        divs[i] = factor(x);
        for (auto [p, d] : divs[i])
            powers[p].insert(d);
    }

    auto get = [&](int p) -> mint {
        if (int(powers[p].size()) != n)
            return 1;
        return mint::power(p, *powers[p].begin());
    };

    mint ans = 1;
    for (int i = 1; i < N; i++)
        ans *= get(i);
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        auto now = factor(x);
        for (auto [p, d] : now) {
            ans /= get(p);
            if (divs[i].find(p) != divs[i].end())
                powers[p].erase(powers[p].find(divs[i][p]));
            divs[i][p] += d;
            powers[p].insert(divs[i][p]);
            ans *= get(p);
        }
        cout << ans << '\n';
    }
}