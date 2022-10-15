#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}

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
    struct vertex_ptr {
        unsigned int idx = 0;

        vertex_ptr(int idx = 0) : idx(idx) {}

        operator bool() const { return idx; }

        const auto &operator*() const { return memory[idx]; }

        auto *operator->() const { return &memory[idx]; }
    };

    struct vertex {
        int l, r;
        int sum;
        vertex_ptr left, right;

        vertex(int l, int r) : l(l), r(r), sum(0), left(0), right(0) {}


        vertex(vertex_ptr left, vertex_ptr right) : l(left->l), r(right->r), left(left), right(right),
                                                    sum(left->sum + right->sum) {}

        vertex(vertex_ptr old, int sum) : l(old->l), r(old->r), left(old->left), right(old->right), sum(sum) {}
    };

    static vertex_ptr get_left(vertex_ptr v) {
        auto l = (v->left ? v->left : new_vertex(v->l, (v->l + v->r) / 2));
        return v->left = l;
    }

    static vertex_ptr get_right(vertex_ptr v) {
        auto r = (v->right ? v->right : new_vertex((v->l + v->r) / 2, v->r));
        return v->right = r;
    }

    static vector<vertex> memory;

    template<typename ...Args>
    static vertex_ptr new_vertex(Args &&...args) {
        memory.emplace_back(args...);
        return vertex_ptr(memory.size() - 1);
    }

    vertex_ptr last_root;

    segment_tree(int l, int r) : last_root(new_vertex(l, r)) {}

    vertex_ptr add(int i, int x) { return last_root = add(i, x, last_root); }

    static vertex_ptr add(int i, int x, vertex_ptr v) {
        if (i < v->l || v->r <= i) return v;
        if (i == v->l && v->l + 1 == v->r) return new_vertex(v, v->sum + x);
        return new_vertex(add(i, x, get_left(v)), add(i, x, get_right(v)));
    }

    static int sum(int l, int r, vertex_ptr v) {
        if (r <= v->l || v->r <= l) return 0;
        if (l <= v->l && v->r <= r) return v->sum;
        return sum(l, r, get_left(v)) + sum(l, r, get_right(v));
    }
};

vector<segment_tree::vertex> segment_tree::memory(1, {0, 0});

void solve() {
    autoint n, m;
    vector<vector<int>> segments(1e6);
    for (int i = 0; i < n; ++i) {
        autoint l, r;
        segments[--r].push_back(--l);
    }
    segment_tree cur(0, 1e6);
    vector<segment_tree::vertex_ptr> roots(1e6);
    for (int r = 0; r < 1e6; ++r) {
        for (int l : segments[r]) cur.add(l, 1);
        roots[r] = cur.last_root;
    }
    for (int j = 0; j < m; ++j) {
        autoint cnt;
        int prev = -1, ans = n;
        for (int k = 0; k < cnt; ++k) {
            autoint cur;
            --cur;
            if (cur) ans -= segment_tree::sum(prev + 1, cur, roots[cur - 1]);
            prev = cur;
        }
        ans -= segment_tree::sum(prev + 1, 1e6, roots.back());
        cout << ans << '\n';
    }
}