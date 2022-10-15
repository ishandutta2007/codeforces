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
    template<typename T>vector<T> prefix_sum(const vector<T> &v, double from = 0, double till = 0) { vector<T> res(v.size()+1); for (double i=from; i+till < v.size(); ++i) res[i-from+1] = res[i-from] + v[i]; return res; }
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

void prefix_function(string &s, vector<int> &prefix, int from);

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct edge {
    int u, v;

    friend istream &operator>>(istream &is, edge &edge) {
        is >> edge.u >> edge.v;
        edge.u--, edge.v--;
        if (edge.u > edge.v) swap(edge.u, edge.v);
        return is;
    }

    bool operator == (const edge &e) const {
        return u == min(e.u, e.v) && v == max(e.u, e.v);
    }
};

void solve() {
    autoint n;
    vector<edge> edges(n - 1);
    cin >> edges;
    vector<vector<int>> g(n);
    for (auto e : edges) {
        g[e.u].push_back(e.v);
        g[e.v].push_back(e.u);
    }
    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) leaves.push_back(i);
    }
    if (leaves.size() == 2){
        for (int i = 0; i < n - 1; ++i) {
            cout << i << "\n";
        }
        return;
    }
    edge a = {leaves[0], g[leaves[0]].front()};
    edge b = {leaves[1], g[leaves[1]].front()};
    edge c = {leaves[2], g[leaves[2]].front()};
    vector<int> ans(n - 1, -1);
    int d = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (edges[i] == a) ans[i] = d++;
        if (edges[i] == b) ans[i] = d++;
        if (edges[i] == c) ans[i] = d++;
    }
    for (int &x : ans) if (x == -1) x = d++;
    cout <<ans;
}