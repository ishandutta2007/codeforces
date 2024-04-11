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

struct segment_tree {
    struct segment {
        int l, r, i;

        segment(int l, int r, int i) : l(l), r(r), i(i) {}

        segment left() const { return {l, (l + r) >> 1, 2 * i + 1}; }

        segment right() const { return {(l + r) >> 1, r, 2 * i + 2}; }

        bool leaf() const { return l + 1 == r; }
    };

    struct query {
        int l, r;

        query(int l, int r) : l(l), r(r) {}
    };

    struct data {
        int val, max;

        data(int val, int max) : val(val), max(max) {}

        void operator+=(int x) {
            val += x;
            max += x;
        }
    };

    vector<data> dp;
    int sz;

    explicit segment_tree(int n) : sz(1) {
        while (sz < n) sz <<= 1;
        dp.assign(sz * 2, {0, 0});
    }

    void push(const segment &s) {
        if (s.leaf()) return;
        if (dp[s.i].val == 0) return;
        dp[s.left().i] += dp[s.i].val;
        dp[s.right().i] += dp[s.i].val;
        dp[s.i].val = 0;
    }

    void add(int x, const query &q) { add(x, q, {0, sz, 0}); }

    void add(int x, const query &q, const segment &s) {
        if (q.r <= s.l || s.r <= q.l) return;
        if (q.l <= s.l && s.r <= q.r) {
            dp[s.i] += x;
            return;
        }
        push(s);
        add(x, q, s.left());
        add(x, q, s.right());
        dp[s.i].max = ::max(dp[s.left().i].max, dp[s.right().i].max);
    }

    void set(int x, int idx) { set(x, idx, {0, sz, 0}); }

    void set(int x, int idx, const segment &s) {
        if (s.leaf() && s.l == idx) {
            dp[s.i].val = dp[s.i].max = x;
            return;
        }
        push(s);
        if (idx < s.left().r) set(x, idx, s.left());
        else set(x, idx, s.right());
        dp[s.i].max = ::max(dp[s.left().i].max, dp[s.right().i].max);
    }

    int max(const query &q) { return max(q, {0, sz, 0}); }

    int max(const query &q, const segment &s) {
        if (q.r <= s.l || s.r <= q.l) return -1e18;
        if (q.l <= s.l && s.r <= q.r) return dp[s.i].max;
        push(s);
        return ::max(max(q, s.left()), max(q, s.right()));
    }
};

struct segment{
    int l, r;
    friend istream &operator >> (istream &is, segment &s){
        int x, w;
        is >> x >> w;
        x -= 1;
        s.l = x - w;
        s.r = x + w;
        return is;
    }
    bool operator < (const segment &segment) const {
        return l < segment.l;
    }
};

void solve() {
    autoint n;
    vector<segment> nodes(n);
    cin >> nodes;

    vector<int> x;
    for (segment s : nodes) {
        x.push_back(s.l);
        x.push_back(s.r);
    }
    stable_sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    for (auto &s : nodes){
        s.l = lower_bound(x.begin(), x.end(), s.l) - x.begin();
        s.r = lower_bound(x.begin(), x.end(), s.r) - x.begin();
    }

    stable_sort(nodes.begin(), nodes.end());

    segment_tree max_size(x.size());

    for (segment &s : nodes){
        max_size.set(max_size.max({0, s.l + 1}) + 1, s.r);
    }
    cout << max_size.max({0, x.size()}) << '\n';
}