#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long

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

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };

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

struct treap {
    struct vertex {
        vertex *left, *right;
        int heap_key, tree_key, size, cnt, val, sub_max;

        vertex(int x, int y) : left(nullptr), right(nullptr),
                               heap_key(rand() << 16 + rand()), tree_key(x), size(1), cnt(1), val(y), sub_max(x) {}

        friend int get_size(vertex *v) { return v ? v->size : 0; }

        friend int get_max(vertex *v) { return v ? v->sub_max : -1e18; }

        vertex *update() {
            size = get_size(left) + cnt + get_size(right);
            sub_max = max({get_max(left), val, get_max(right)});
            return this;
        }
    };

    vertex *root;

    static vertex *merge(vertex *left, vertex *right) {
        if (!left) return right;
        if (!right) return left;
        if (left->heap_key < right->heap_key) {
            right->left = merge(left, right->left);
            return right->update();
        } else {
            left->right = merge(left->right, right);
            return left->update();
        }
    }

    static pair<vertex *, vertex *> split(vertex *v, int val) {
        if (!v) return {nullptr, nullptr};
        if (v->tree_key < val) {
            auto spl = split(v->right, val);
            v->right = spl.first;
            return {v->update(), spl.second};
        } else {
            auto spl = split(v->left, val);
            v->left = spl.second;
            return {spl.first, v->update()};
        }
    }

    treap() : root(nullptr) {}

    void insert(int x, int y) {
        auto spl1 = split(root, x);
        auto spl2 = split(spl1.second, x + 1);
        if (spl2.first) {
            spl2.first->cnt++;
            spl2.first->val = max(spl2.first->val, y);
        } else {
            spl2.first = new vertex(x, y);
        }
        root = merge(spl1.first, merge(spl2.first->update(), spl2.second));
    }

    pair<int, int> less_count(int x) {
        auto spl = split(root, x);
        pair<int, int> ans = {get_size(spl.first), get_max(spl.first)};
        root = merge(spl.first, spl.second);
        return ans;
    }
};

struct segment_tree {
    struct node {
        int l, r, i;

        explicit node(int l, int r, int i) : i(i), l(l), r(r) {}

        node left() const { return node(l, (l + r) / 2, 2 * i + 1); }

        node right() const { return node((l + r) / 2, r, 2 * i + 2); }
    };

    struct query {
        int l, r;
    };
    vector<treap> set;
    int sz = 1;

    explicit segment_tree(vector<vector<pair<int, int>>> &a) {
        while (sz < a.size()) sz <<= 1;
        set.assign(sz * 2, treap());
        for (int i = 0; i < a.size(); ++i) for (auto x : a[i]) add(i, x.first, x.second);
    }

    void add(int i, int x, int y) { add(i, x, y, node(0, sz, 0)); }

    void add(int i, int x, int y, node cur) {
        if (i < cur.l || cur.r <= i) return;
        set[cur.i].insert(x, y);
        if (cur.l + 1 == cur.r) {
            return;
        }
        add(i, x, y, cur.left());
        add(i, x, y, cur.right());
    }

    int distinct_count(int l, int r) { return distinct_count({l, r}, node(0, sz, 0)); }

    int distinct_count(query q, node cur) {
        if (q.r <= cur.l || cur.r <= q.l) return 0;
        if (q.l <= cur.l && cur.r <= q.r) {
            return set[cur.i].less_count(q.l).first;
        }
        return distinct_count(q, cur.left()) + distinct_count(q, cur.right());
    }

    bool has_out(int l, int r) { return has_out({l, r}, node(0, sz, 0)); }

    bool has_out(query q, node cur) {
        if (q.r <= cur.l || cur.r <= q.l) return false;
        if (q.l <= cur.l && cur.r <= q.r) {
            return set[cur.i].less_count(q.l + 1).second >= q.r;
        }
        return has_out(q, cur.left()) || has_out(q, cur.right());
    }
};

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    vector<int> distinct = a;
    stable_sort(distinct.begin(), distinct.end());
    distinct.resize(unique(distinct.begin(), distinct.end()) - distinct.begin());
    for (int &x : a) x = lower_bound(distinct.begin(), distinct.end(), x) - distinct.begin();

    vector<vector<int>> place(distinct.size(), {-1});
    for (int i = 0; i < n; ++i) place[a[i]].push_back(i);
    for (auto &v : place) v.push_back(n);

    vector<vector<pair<int, int>>> c(n);
    for (auto &v : place) {
        for (int i = 1; i + 1 < v.size(); ++i) {
            int start = i, end = i;
            while (end + 2 < v.size() && v[start + 1] - v[start] == v[end + 1] - v[end]) ++end;
            for (int j = start; j <= end; ++j) c[v[j]].emplace_back(v[i - 1] + 1, v[end + 1]);
            i = max(i, end - 1);
        }
    }
    segment_tree progression(c);

    vector<int> prev(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = *--lower_bound(place[a[i]].begin(), place[a[i]].end(), i);
    }
    vector<vector<pair<int, int>>> b(n);
    for (int i = 0; i < n; ++i) b[i].emplace_back(prev[i], 0);
    segment_tree distincts(b);
    autoint q;
    for (int query = 0; query < q; ++query) {
        autoint l, r;
        --l, --r;
        bool out = progression.has_out(l, r + 1);
        cout << distincts.distinct_count(l, r + 1) + 1 - out << '\n';
    }
}