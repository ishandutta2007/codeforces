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

void dfs(vector<vector<int>> &graph, int cur, int from) {
    for (int next : graph[cur]) {
        if (next == from) continue;
        graph[next].erase(find(graph[next].begin(), graph[next].end(), cur));
        dfs(graph, next, cur);
    }
}

void dfs(const vector<vector<int>> &graph, int cur, int &time, vector<int> &time_in, vector<int> &time_out) {
    time_in[cur] = time++;
    for (int next : graph[cur]) dfs(graph, next, time, time_in, time_out);
    time_out[cur] = time++;
}

void dfs(const vector<vector<int>> &graph, int cur, int d, vector<int> &depth) {
    depth[cur] = d;
    for (int next : graph[cur]) dfs(graph, next, d + 1, depth);
}

void solve() {
    autoint n, m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        autoint u, v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(graph, 0, 0);
    vector<int> parent(n, 0);
    for (int i = 0; i < n; ++i) for (int v : graph[i]) parent[v] = i;
    vector<int> time_in(n), time_out(n), depth(n);
    int time = 0;
    dfs(graph, 0, time, time_in, time_out);
    dfs(graph, 0, 0, depth);
    for (int j = 0; j < m; ++j) {
        autoint k;
        autoread<vector<int>> v(k);
        for (int &u : v) u = parent[u - 1];
        stable_sort(v.begin(), v.end(), [&](int x, int y){return make_pair(depth[x], x) < make_pair(depth[y], y);});
        bool correct = true;
        for (int i = 1; i < k; ++i) {
            if ((!(time_in[v[i]] >= time_in[v[i - 1]] && time_out[v[i - 1]] >= time_out[v[i]])) &&
                (!(time_in[v[i - 1]] >= time_in[v[i]] && time_out[v[i]] >= time_out[v[i - 1]]))) {
                correct = false;
            }
        }
        cout << (correct ? "YES" : "NO") << "\n";
    }
}