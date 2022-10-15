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

void solve() {
    autoint n, m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i){
        autoint u, v;
        --u, --v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> desired_topic(n);
    cin >> desired_topic;
    for (int &x : desired_topic) --x;
    vector<vector<int>> desired_blog(n);
    for (int i = 0; i < n; ++i) desired_blog[desired_topic[i]].push_back(i);
    vector<int> order(n);
    int f = 0;
    for (int i = 0; i < n; ++i){
        for (int blog : desired_blog[i]) order[blog] = f++;
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[order[i]] = i;
    vector<int> topic(n, -1);
    for (int i = 0; i < n; ++i){
        vector<int> near;
        for (int edge : graph[v[i]]){
            near.push_back(topic[edge]);
        }
        stable_sort(near.begin(), near.end());
        near.resize(unique(near.begin(), near.end()) -near.begin());
        for (int x = 0; x < n; ++x) if (!binary_search(near.begin(), near.end(), x)) {topic[v[i]] = x; break;}
    }
    for (int &x : v) ++x;
    if (topic == desired_topic) answer( v);else answer(-1);
}