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
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

struct Problem {
    int time;
    int len;

    Problem() {}

    Problem(int t, int l) : len(l), time(t) {}

    const bool operator<(const Problem &time1) const {
        return time < time1.time;
    }
};

int add(int primes, int others, int bonus, int a, int b) {
    if (bonus < 0) return 0;
    if (bonus / a < primes) return bonus / a;
    bonus -= a * primes;
    if (bonus / b < others) return primes + bonus / b;
    return primes + others;
}

void solve() {
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<Problem> p(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        p[i].len = (c == 1 ? b : a);
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i].time;
    }
    incr_sort(p);
    p.push_back({T + 1, 0});
    int ans = 0;
    int sum = 0;
    int primes = count_if(p.begin(), p.end(), [a](Problem &x) { return x.len == a; });
    int others = n - primes;
    ans = add(primes, others, p[0].time - 1, a, b);
    for (int i = 0; i < n; ++i) {
        sum += p[i].len;
        (p[i].len == a? primes : others) -= 1;
        if (sum < p[i + 1].time)
            ans = max(ans,
                      i + 1 + add(primes, others, p[i + 1].time - sum - 1, a, b));
    }
    answer(ans);
}