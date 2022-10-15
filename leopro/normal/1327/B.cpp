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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
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
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        autoint sz;
        g[i].resize(sz);
        cin >> g[i];
    }
    set<int> unused;
    vector<bool> married(n);
    for (int i = 1; i <= n; ++i) unused.insert(i);
    for (int i = 0; i < n; ++i) {
        for (int p : g[i]) {
            if (unused.find(p) != unused.end()) {
                unused.erase(p);
                married[i] = true;
                break;
            }
        }
    }
    if (find(married.begin(), married.end(), false) == married.end()) answer("OPTIMAL");
    auto it = find(married.rbegin(), married.rend(), false);
    int i = married.size() - (it - married.rbegin()) - 1;
    answer("IMPROVE", i+1, *unused.begin());
}