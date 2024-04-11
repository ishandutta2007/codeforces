#include <bits/stdc++.h>

//@formatter:off
namespace {
#define int long long
    using namespace std;
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t + 1 << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer_ref(T &ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    const char *to_string(const vector<int> &v){ostringstream ss; for (const auto &item : v) ss << item << (whitespace(item) ? " " : ""); return ss.str().c_str();}
    const char *to_string(const vector<vector<int>> &v){string *s = new string; for (const auto & item : v) *s += string(to_string(item)) + "   "; return s->c_str();}
    const char *to_string(const pair<int, int> &p){ostringstream ss; ss << p.first << ", " << p.second; return ss.str().c_str();}
    const char *to_string(const map<int, int> &m){ostringstream ss; for (const auto & item : m) ss << "(" << item << ") "; return ss.str().c_str();}
    const char *to_string(const set<int> &s){ostringstream ss; for (const auto & item : s) ss << "(" << item << ") "; return ss.str().c_str();}
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

void read_tree(int m, vector<vector<int>> &edges, vector<int> &degree) {
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ++degree[a];
        ++degree[b];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}
int same_cmp[500000];
bool in_super(int x, int from, vector<vector<int>> &edges, vector<int> &cmp, int c) {
    int n = 1;
    same_cmp[0] = x;
    bool result = false;
    while (n > 0) {
        int y = same_cmp[--n];
        cmp[y] = c;
        for (int i = 1; i < edges[y].size(); ++i) {
            int L = edges[y][i - 1], R = edges[y][i];
            for (int j = L + 1; j < R; ++j) {
                if (cmp[j] == 0) result = true;
                if (cmp[j] == -1) same_cmp[n++] = j;
            }
        }
    }
    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>({n, -1}));
    vector<int> degree(n);
    read_tree(m, edges, degree);
    for (int i = 0; i < n; ++i) incr_sort(edges[i]);
    int super_root = min_element(degree.begin(), degree.end()) - degree.begin();
    vector<int> cmp(n, -1);
    vector<int> rem = edges[super_root];
    cmp[super_root] = 0;
    for (int i = 1; i < rem.size(); ++i) {
        for (int j = rem[i - 1] + 1; j < rem[i]; ++j) cmp[j] = 0;
    }
    int c = 1;
    for (int i = 1; i < rem.size() - 1; ++i) {
        if (cmp[rem[i]] == -1) {
            if (in_super(rem[i], rem[i], edges, cmp, c)) {
                for (int j = 1; j < rem.size() - 1; ++j) { if (cmp[rem[j]] == c) cmp[rem[j]] = 0; }
            } else ++c;
        }
    }
    cout << c - 1 << "\n";
}