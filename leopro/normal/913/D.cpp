#include <bits/stdc++.h>

#include <utility>

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
    class exit_exception : exception {};
    void answer(){}
    template<typename First, typename... Args>void answer(First&& val, Args&&... ans){cout << val << "\n"; answer(ans...); throw exit_exception();}
    struct autoint{ int x; autoint(int i):x(i){} autoint():x(0){cin >> x;} operator int(){return x;}                                               //NOLINT
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };   //NOLINT
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
}
//@formatter:on

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

struct problem {
    int a, time, n;

    friend istream &operator>>(istream &is, problem &p) {
        is >> p.a >> p.time;
        return is;
    }
};

int operator+(int x, const problem &p) { return x + p.time; }

void solve() {
    autoint n, t;
    vector<problem> problems(n);
    cin >> problems;
    for (int i = 0; i < n; ++i) problems[i].n = i + 1;
    int l = 0, r = problems.size() + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        stable_sort(problems.begin(), problems.end(), [m](const problem &a, const problem &b) -> bool {
            if ((m <= a.a) ^ (m <= b.a)) return m <= a.a;
            return a.time < b.time;
        });
        if (problems[m - 1].a < m) {
            r = m;
            continue;
        }
        (accumulate(problems.begin(), problems.begin() + m, 0ll) > t ? r : l) = m;
    }
    cout << l << '\n' << l << '\n';
    stable_sort(problems.begin(), problems.end(), [l](const problem &a, const problem &b) -> bool {
        if ((l <= a.a) ^ (l <= b.a)) return l <= a.a;
        return a.time < b.time;
    });
    for (int i = 0; i < l; ++i) cout << problems[i].n << ' ';
}