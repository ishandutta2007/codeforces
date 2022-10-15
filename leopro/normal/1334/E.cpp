#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename F, typename S>inline bool whitespace(const pair<F, S> &) { return false; }
    template<typename F, typename S>ostream &operator<<(ostream &os, const pair<F, S> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename F, typename S>istream &operator>>(istream &is, pair<F, S> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
    template<typename F, typename S>F min(F a, S b){return a < (F)b ? a : b; }
    template<typename F, typename S>F max(F a, S b){return a < (F)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;} int operator=(int i){ return x = i; }
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
}
//@formatter:on

void solve();

struct mod_int {
    static const int MOD = 998244353;
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

map<int, mod_int> ans;

vector<int> inv;

void dfs(const vector<pair<int, int>> &primes, int cur, mod_int mul, int s, int c) {
    if (cur == primes.size()) {
        ans[s] = mul;
        return;
    }
    for (int i = 0; i <= primes[cur].second; ++i) {
        dfs(primes, cur + 1, mul, s, c);
        s *= primes[cur].first;
        mul *= ++c;
        if (i < primes[cur].second) mul *= inv[(i + 1)];
    }
}

void pre_calc(int d) {
    vector<pair<int, int>> primes;
    int mx = 2;
    for (int i = 2; i * i <= d; ++i) {
        if (d % i != 0) continue;
        primes.emplace_back(i, 0);
        while (d % i == 0) {
            primes.back().second++;
            d /= i;
        }
        mx = max(mx, primes.back().second);
    }
    for (int i = 0; i <= mx + 1; ++i) inv.push_back(mod_int(1) / mod_int(i));
    if (d > 1) primes.emplace_back(d, 1);
    dfs(primes, 0, 1, 1, 0);
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int d, t = 1;
    cin >> d >> t;
    pre_calc(d);
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}


void solve() {
    int u, v;
    cin >> u >> v;
    int g = gcd(u, v);
    cout << ans[(u / g)] * ans[(v / g)] << '\n';
}