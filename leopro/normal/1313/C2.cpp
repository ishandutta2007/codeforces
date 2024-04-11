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

int min(const vector<vector<int>> &sparse_table, const vector<int> &log, int f, int t) {
    int pow = log[t - f];
    return min(sparse_table[pow][f], sparse_table[pow][t - (1 << pow)]);
}

void solve() {
    autoint n;
    autoread<vector<int>> a(n);
    a.insert(a.begin(), 0);
    a.insert(a.end(), 0);
    vector<int> log(n + 3);
    for (int i = 2; i <= n + 2; ++i) log[i] = log[i / 2] + 1;
    vector<vector<int>> sparse_table(20, vector<int>(n + 2));
    for (int i = 0; i < n + 2; ++i) sparse_table[0][i] = a[i];
    for (int j = 1; j <= log[n + 2]; ++j) {
        for (int i = 0; i < n + 2; ++i) {
            sparse_table[j][i] = min(sparse_table[j - 1][i], sparse_table[j - 1][min(i + (1 << (j - 1)), n + 1)]);
        }
    }
    vector<int> dpl(n + 2);
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (min(sparse_table, log, m, i) >= a[i] ? r : l) = m;
        }
        dpl[i] = dpl[l] + (i - l) * a[i];
    }
    vector<int> dpr(n + 2);
    for (int i = n; i >= 1; --i) {
        int l = i + 1, r = n + 2;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (min(sparse_table, log, i, m) >= a[i] ? l : r) = m;
        }
        dpr[i] = dpr[l] + (l - i) * a[i];
    }
    int ans = 0, idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans < dpl[i] + dpr[i] - a[i]) {
            ans = dpl[i] + dpr[i] - a[i];
            idx = i;
        }
    }
    vector<int> h(n + 2);
    int prefix_min = a[idx], suffix_min = a[idx];
    for (int i = idx; i >= 1; --i) {
        prefix_min = min(prefix_min, a[i]);
        h[i] = prefix_min;
    }
    for (int i = idx; i <= n; ++i) {
        suffix_min = min(suffix_min, a[i]);
        h[i] = suffix_min;
    }
    h.erase(h.begin());
    h.erase(h.end() - 1);
    cout << h;
}