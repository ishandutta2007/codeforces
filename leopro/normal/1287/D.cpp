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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    void answer(ostream &os = cout){os << "\n"; throw ExitException();}
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

char third(char a, char b) {
    if (a == b) return a;
    return 'S' + 'E' + 'T' - a - b;
}

template<typename I>
void dfs(I begin, int x,
         vector<vector<int>> &children, vector<int> &size, vector<int> &c, vector<int> &order) {
    for (int child : children[x]) {
        dfs(begin, child, children, size, c, order);
        begin += size[child] + 1;
    }
    if (c[x] > size[x]) answer("NO");
    begin = begin - size[x];
    auto i = begin + size[x];
    for (; i != begin + c[x]; --i) *i = *(i - 1);
    *i = x;
    return;
}

int set_size(int x, vector<vector<int>> &children, vector<int> &size) {
    if (children[x].empty()) return size[x] = 0;
    for (int child : children[x]) size[x] += set_size(child, children, size) + 1;
    return size[x];
}

void solve() {
    autoint n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
    }
    vector<vector<int>> children(n);
    int root;
    for (int i = 0; i < n; ++i) if (p[i]) children[p[i] - 1].push_back(i); else root = i;
    vector<int> size(n, 0);
    set_size(root, children, size);
    vector<int> order(n, -1);
    for (int j = 0; j < n; ++j) order[j] = j + 100;
    dfs(order.begin(), root, children, size, c, order);
    cout << "YES\n";
    vector<int> ans(n, 0);
    for (int i = 0; i < order.size(); ++i) ans[order[i]] = i + 5;
    answer(ans);
}