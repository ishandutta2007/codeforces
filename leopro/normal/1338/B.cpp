#include <bits/stdc++.h>

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
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
    template<typename F, typename S>F min(F a, S b){return a < (F)b ? a : b; }
    template<typename F, typename S>F max(F a, S b){return a < (F)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;} int operator=(int i){ return x = i; }
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
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

struct vertex {
    vertex *parent;
    vector<vertex *> children;
    int n;
    bool leaf, has_leaves;
    bool has_even, has_odd;
    int mx, mn;

    vertex(int n, vertex *p, const vector<vector<int>> &g)
            : n(n), has_leaves(false), mx(0), mn(0), has_even(false), has_odd(false) {
        parent = p;
        leaf = g[n].size() == 1;
        has_even = leaf;
        for (int c : g[n]) {
            if (p && c == p->n) continue;
            children.push_back(new vertex(c, this, g));
            has_leaves |= children.back()->leaf;
            has_even |= children.back()->has_odd;
            has_odd |= children.back()->has_even;
        }
    }
};

int dfs(vertex *cur, int &mn) {
    if (cur->has_even && cur->has_odd) mn = 3;
    if (cur->leaf) return 0;
    int ans = cur->has_leaves + count_if(cur->children.begin(), cur->children.end(), [](vertex *u){return !u->leaf;});
    for (vertex *v : cur->children) ans += dfs(v, mn);
    return ans;
}

void solve() {
    autoint n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        autoint a, b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vertex *root = new vertex(find_if(g.begin(), g.end(), [](const vector<int> &h) { return h.size() > 1; }) - g.begin(),
                              nullptr, g);
    int mn = 1;
    int mx = dfs(root, mn);
    cout << mn << ' ' << mx << '\n';
}