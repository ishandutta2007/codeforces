#include <bits/stdc++.h>

#include <utility>

//@formatter:off
namespace {
    using namespace std;
#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}
//@formatter:on

void solve(int t);

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(t); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct mod_int {
    static const int MOD = 1e9 + 7;
    int value;

    mod_int(int i = 0) : value(i % MOD) {} //NOLINT
    mod_int operator+(mod_int m) const { return (value + m.value) % MOD; }

    mod_int operator+=(mod_int m) {
        value += m.value;
        return value %= MOD;
    }

    mod_int operator-(mod_int m) const { return (value - m.value + MOD) % MOD; }

    mod_int operator-=(mod_int m) {
        value -= (m.value - MOD);
        return value %= MOD;
    }

    mod_int operator*(mod_int m) const { return (value * m.value) % MOD; }

    mod_int operator*=(mod_int m) {
        value *= m.value;
        return value %= MOD;
    }

    mod_int power(int exp) {
        if (exp == 0) return 1;
        mod_int res = (exp & 1 ? value : 1);
        mod_int half = power(exp >> 1);
        return res * half * half;
    }

    mod_int operator/(mod_int m) const { return *this * m.power(MOD - 2); }

    mod_int operator/=(mod_int m) { return *this *= m.power(MOD - 2); }

    friend std::istream &operator>>(std::istream &is, mod_int &m) {
        is >> m.value;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const mod_int &m) {
        os << m.value;
        return os;
    }

    operator int() { return value; }  //NOLINT
};

mod_int power(mod_int b, int e) {
    return b.power(e);
}

void yield(mod_int big, mod_int p, const map<int, int>& rem) {
    for (auto x : rem) big -= x.second * p.power(x.first);
    answer(big);
}

bool big(mod_int p, int pow) {
    return (log(1e7) / log((int)p)) < pow;
}

void mult(mod_int p, int &over_weight, map<int, int>::reverse_iterator it, const map<int, int> &cnt) {
    int cur = 0;
    if (it != cnt.rend()) cur = it->first;
    int dist = (--it)->first - cur;
    over_weight *= p.power(dist);
    if ((over_weight && big(p, dist)) || over_weight > 1e6) yield(mod_int(over_weight) * p.power(cur), p, cnt);
}

void solve(int t) {
    autoint n, p;
    vector<int> k(n);
    cin >> k;
    if (p == 1) answer(n & 1);
    map<int, int> cnt;
    for (int x : k) cnt[x]++;
    int over_weight = 0;
    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it, mult((int) p, over_weight, it, cnt)) {
        if (over_weight != 0) {
            if (it->second > over_weight) {
                it->second -= over_weight;
                over_weight = 0;
            } else {
                over_weight -= it->second;
                it->second = 0;
            }
        }
        if (over_weight == 0) {
            over_weight = it->second & 1;
            it->second = 0;
        }
    }
    answer(over_weight);
}