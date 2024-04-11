#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename S, typename T>inline bool whitespace(const pair<S, T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << endl; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0, int till = 0) { vector<T> res = vector<T>(v.size() + 1); for (int i = from; i + till < v.size(); ++i) { res[i - from + 1] = res[i - from] + v[i]; } return res; }
    template<typename S, typename T>S min(S s, T t){return s < t ? s : (S)t;}
    template<typename S, typename T>S max(S s, T t){return s < t ? (S)t : s;}
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    void answer(){}
    template<typename First, typename... Args>void answer(First&& val, Args&&... ans){out << val << "\n"; answer(ans...); throw exit_exception();}
    struct autoint{ int x; autoint(int i):x(i){} autoint():x(0){in >> x;} operator int(){return x;}                                               //NOLINT
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };   //NOLINT
    template<typename T> struct autoread : T { template<typename... Args>autoread(Args&&... args): T(args...){ in >> *dynamic_cast<T *>(this);} };//NOLINT
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

int solve_up(int n, int k, const vector<int> &a) {
    map<int, int> count;
    for (int x : a) count[x]++;
    for (auto p : count) if (p.second >= k) return 0;
    vector<pair<int, int>> cnt(count.begin(), count.end());
    int ans = 0;
    for (int i = 0; i + 1 < cnt.size(); ++i) {
        if (cnt[i].second + cnt[i + 1].second >= k)
            return ans + (k - cnt[i + 1].second) * (cnt[i + 1].first - cnt[i].first);
        cnt[i + 1].second += cnt[i].second;
        ans += cnt[i].second * (cnt[i + 1].first - cnt[i].first);
    }
    return 1e18;
}

int solve_down(int n, int k, vector<int> a) {
    for (int &x : a) x *= -1;
    return solve_up(n, k, a);
}

int count(const vector<int> &a, int n, int k, int x) {
    int result = 1e18;
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += abs(x - a[i]);
    result = min(result, ans - (n - k));
    return result;
}

int count(pair<vector<int>::iterator, vector<int>::iterator> range) {
    return range.second - range.first;
}

void solve() {
    autoint n, k;
    autoread<vector<int>> a(n);
    stable_sort(a.begin(), a.end());
    for (int x : a) if (count(equal_range(a.begin(), a.end(), x)) >= k) answer(0);
    int x = a[n / 2], y = a[n / 2 + 1];
    cout << min(min(count(a, n, k, x), count(a, n, k, y)), min(solve_up(n, k, a), solve_down(n, k, a)));
}