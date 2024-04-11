#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

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

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct mod_int{
    static const int MOD = 998244353;
    int value;
    mod_int(int i = 0) : value(i % MOD) {} //NOLINT
    mod_int operator+(mod_int m) const { return (value + m.value) % MOD;}
    mod_int operator+=(mod_int m) { value += m.value; return value %= MOD;}
    mod_int operator-(mod_int m) const {return (value - m.value + MOD) % MOD;}
    mod_int operator-=(mod_int m) {value -= (m.value - MOD); return value %= MOD;}
    mod_int operator*(mod_int m) const {return (value * m.value) % MOD;}
    mod_int operator*=(mod_int m) {value *= m.value; return value %= MOD;}
    mod_int power(int exp) {if (exp == 0) return 1; mod_int res = (exp & 1 ? value : 1); mod_int half = power(exp >> 1); return res * half * half; }
    mod_int operator /(mod_int m) const { return *this * m.power(MOD - 2); }
    mod_int operator /=(mod_int m) { return *this *= m.power(MOD - 2); }
    friend std::istream &operator>> (std::istream &is, mod_int &m) { is >> m.value; return is; }
    friend std::ostream &operator<< (std::ostream &os, const mod_int &m) { os << m.value; return os; }
    operator int(){ return value; }  //NOLINT
};

vector<mod_int> fact, inv;
mod_int C(mod_int n, mod_int k){
    return fact[n] * inv[k] * inv[n - k];
}
struct act{
    int t;
    bool l;
    bool operator<(const act &act) const {
        if (t != act.t) return t < act.t;
        return !l < !act.l;
    }
    act(int t, bool l):t(t),l(l){}
};
void solve() {
    autoint n, k;
    fact.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = fact[i - 1] * mod_int{i};
    inv[n] = mod_int(1) / fact[n];
    for (int i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * mod_int(i + 1);

    vector<pair<int, int>> lights(n);
    cin >> lights;
    vector<act> actions;
    for (int i = 0; i < n; ++i) actions.emplace_back(lights[i].first, true);
    for (int i = 0; i < n; ++i) actions.emplace_back(lights[i].second, false);

    stable_sort(actions.begin(), actions.end());
    int cur = 0;
    mod_int ans = 0;
    for (auto & action : actions){
        cur += (action.l ? 1 : -1);
        if (cur >= k && action.l) ans += C(cur - 1, k - 1);
    }
    answer(ans);
}