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

int find_min(vector<vector<int>> &g, vector<int> &pred, vector<int> &visited, int cur) {
    if (pred[cur] != -1) return min(pred[cur], cur);
    int m = 1e9;
    for (int x : g[cur]) m = min(m, find_min(g, pred, visited, x));
    return min(pred[cur] = m, cur);
}

void set_ex(vector<bool> &ex, vector<vector<int>> &g, int cur) {
    if (ex[cur]) return;
    ex[cur] = true;
    for (int x : g[cur]) set_ex(ex, g, x);
}

void find_cycle(const vector<vector<int>> &g) {
    vector<int> in_deg(g.size());
    for (const auto &row : g) for (int v : row) in_deg[v]++;
    stack<int> zeros;
    for (int i = 0; i < g.size(); ++i) if (in_deg[i] == 0) zeros.push(i);
    while (!zeros.empty()) {
        int v = zeros.top();
        zeros.pop();
        for (int u : g[v]) {
            in_deg[u]--;
            if (in_deg[u] == 0) zeros.push(u);
        }
    }
    if (find_if(in_deg.begin(), in_deg.end(), [](int x){return x;}) != in_deg.end()) answer(-1);
}

void solve() {
    autoint n, m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        autoint x, y;
        --x, --y;
        g[x].push_back(y);
    }

    find_cycle(g);

    vector<int> visited(n, -1), pred(n, -1);
    for (int i = 0; i < n; ++i) find_min(g, pred, visited, i);

    vector<bool> ex(n, false);

    vector<char> ans(n);
    for (int i = 0; i < n; ++i) {
        if (pred[i] > i && !ex[i]) ans[i] = 'A'; else ans[i] = 'E';
        set_ex(ex, g, i);
    }
    answer(count(ans.begin(), ans.end(), 'A'), ans);
}