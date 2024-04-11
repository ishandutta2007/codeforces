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
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
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
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
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

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct treap {
    struct vertex {
        vertex *left = nullptr, *right = nullptr;
        int value, heap_value;
        int cost, mod = 0, sub_min;

        vertex(int value, int cost) : value(value), cost(cost), sub_min(cost), heap_value((rand() << 16) + rand()) {}

        static int get_min(vertex *v) { return v ? v->sub_min : (int) 1e18; }

        void apply(int bias) {
            mod += bias;
            cost += bias;
            sub_min += bias;
        }

        void push() {
            if (left) left->apply(mod);
            if (right) right->apply(mod);
            mod = 0;
        }

        vertex *update() {
            sub_min = min({get_min(left), cost, get_min(right)});
            return this;
        }
    };

    static pair<vertex *, vertex *> split(vertex *v, int val) {
        if (v == nullptr) return {v, v};
        v->push();
        if (v->value < val) {
            auto[left, right] = split(v->right, val);
            v->right = left;
            return {v->update(), right};
        } else {
            auto[left, right] = split(v->left, val);
            v->left = right;
            return {left, v->update()};
        }
    }

    static vertex *merge(vertex *left, vertex *right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        left->push(), right->push();
        if (left->heap_value > right->heap_value) {
            left->right = merge(left->right, right);
            return left->update();
        } else {
            right->left = merge(left, right->left);
            return right->update();
        }
    }

    static vertex *unite(vertex *u, vertex *v) {
        if (u == nullptr) return v;
        if (v == nullptr) return u;
        auto[left, cr] = split(u, v->value);
        auto[c, right] = split(cr, v->value + 1);
        if (c == nullptr || c->cost > v->cost) c = v;
        v->push();
        left = unite(left, v->left);
        right = unite(right, v->right);
        c->left = c->right = nullptr;
        return merge(left, merge(c->update(), right));
    }

    vertex *root;

    treap(int i, int x) : root(new vertex(i, x)) {}

    int get(int i) {
        auto[left, vr] = split(root, i);
        auto[v, right] = split(vr, i + 1);
        int res = vertex::get_min(v);
        root = merge(left, merge(v, right));
        return res;
    }

    int get_min() {
        return vertex::get_min(root);
    }

    void update(treap t) {
        root = unite(root, t.root);
    }

    void update(int i, int x) {
        auto[left, vr] = split(root, i);
        auto[v, right] = split(vr, i + 1);
        if (v == nullptr) v = new vertex(i, x); else v->push(), v->cost = min(v->cost, x);
        root = merge(left, merge(v->update(), right));
    }

    void erase(int i) {
        auto[left, vr] = split(root, i);
        auto[v, right] = split(vr, i + 1);
        root = merge(left, right);
    }

    void add(int x) {
        if (root) root->apply(x);
    }
};

treap solve_recursive(treap cur, int s) {
    string query;
    while (cin >> query) {
        if (query == "end") return cur;
        if (query == "set") {
            autoint y, v;
            if (y == s) {
                cur.add(v);
            } else {
                int min = cur.get_min();
                cur.add(v);
                cur.update(y, min);
            }
        }
        if (query == "if") {
            autoint v;
            auto cost = cur.get(v);
            cur.erase(v);
            cur.update(solve_recursive(treap(v, cost), s));
        }
    }
    return cur;
}

void solve() {
    autoint n, s;
    auto ans = solve_recursive(treap(0, 0), s);
    cout << ans.get_min() << '\n';
}