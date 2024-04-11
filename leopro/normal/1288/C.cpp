#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    void answer(ostream &os = cout){os << "\n"; throw ExitException();}
    istream &is = cin;
    struct autoint {int x; autoint() { is >> x; } operator int(){return x;}};
    template<typename T> struct autoread : T{template<typename... Args>autoread(Args&&... args): T(args...){ is >> *dynamic_cast<T *>(this);} };
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (ExitException &) {}} while (--t);
    return 0;
}

const int MOD = 1e9 + 7;
vector<int> fact(2000);
vector<int> fractions(2000);

int power(int a, int b) {
    if (b == 0) return 1;
    int ans = 1;
    if (b % 2 != 0) ans *= a;
    int x = power(a, b / 2);
    return (((x * x) % MOD) * ans) % MOD;
}

int C(int n, int k) {
    int a = fact[n], b = fractions[k], c = fractions[n - k];
    return ((a * b) % MOD * c) % MOD;
}

void solve() {
    autoint n, m;
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 2000; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int j = 0; j < 2000; ++j) {
        fractions[j] = power(fact[j], MOD - 2);
    }
//    cout << C(2, 2);
    int ans = 0;
    for (int border1 = 1; border1 <= n; ++border1) {
        for (int border2 = 1; border1 + border2 <= n + 1; ++border2) {
            ans += (C(m + border1 - 2, m - 1) * C(m + border2 - 2, m - 1)) % MOD;
        }
    }
    answer(ans % MOD);
}