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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    istream &is = cin;
    struct autoint {int x; autoint() {is >> x;} operator int(){return x;}};
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
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

struct Seq {
    int len;
    vector<int> s;
    bool good;
    int min, max;

    friend istream &operator>>(istream &is, Seq &s) {
        is >> s.len;
        s.s.resize(s.len);
        is >> s.s;
        s.min = *min_element(s.s.begin(), s.s.end());
        s.max = *max_element(s.s.begin(), s.s.end());
        s.good = false;
        for (int j = 1; j < s.len; ++j) {
            if (s.s[j - 1] < s.s[j]) s.good = true;
        }
        return is;
    }
};

struct Pair {
    int min, max;

    Pair(int a, int b) : min(a), max(b) {}

    const bool operator<(const Pair &p) const {
        return max < p.max;
    }
};

void solve() {
    autoint n;
    autoread<vector<Seq>> s(n);
    int good = 0;
    vector<Pair> other;
    for (int i = 0; i < n; ++i) {
        if (!s[i].good) other.push_back({s[i].min, s[i].max}); else ++good;
    }
    int ans = good * good + 2ll * good * other.size();
    incr_sort(other);
    for (int i = 0; i < other.size(); ++i) {
        ans += (other.size() - (upper_bound(other.begin(), other.end(), Pair({0, other[i].min})) - other.begin()));
    }
    answer(ans);
}