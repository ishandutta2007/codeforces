#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

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

struct segment_tree {
    struct segment {
        int l, r;
        int sum = 0;
        bool inv = false;
        segment *left = nullptr, *right = nullptr;

        explicit segment(int l, int r, int sum = 0, bool inv = false) : l(l), r(r), sum(sum), inv(inv) {}

        segment(segment *left, segment *right) : left(left), right(right), l(left->l), r(right->r),
                                                 sum(left->sum + right->sum) {}

        segment *inversed() {
            auto *s = new segment(l, r, r - l - sum, !inv);
            s->left = left;
            s->right = right;
            return s;
        }

        segment *pushed() {
            if (!inv || !left || !right) return this;
            return new segment(left->inversed(), right->inversed());
        }
    };

    segment *root;

    segment_tree(int n) : root(build(0, 1 << (__lg(n) + 1))) {}

    segment *build(int l, int r) {
        if (l + 1 == r) return new segment(l, r);
        int m = (l + r) / 2;
        return new segment(build(l, m), build(m, r));
    }

    segment *update(int i, int x) { return root = update(i, x, root); }

    static segment *update(int i, int x, segment *root) {
        if (root == nullptr || root->l > i || root->r <= i) return root;
        if (root->l + 1 == root->r) return new segment(i, i + 1, x);
        root = root->pushed();
        return new segment(update(i, x, root->left), update(i, x, root->right));
    }

    segment *inverse(int l, int r) { return root = inverse(l, r, root); }

    static segment *inverse(int l, int r, segment *root) {
        if (root == nullptr || r <= root->l || root->r <= l) return root;
        if (l <= root->l && root->r <= r) return root->inversed();
        root = root->pushed();
        return new segment(inverse(l, r, root->left), inverse(l, r, root->right));
    }
};

void solve() {
    autoint n, m, q;
    segment_tree shelves(n * m);
    vector<segment_tree::segment *> versions(q + 1);
    versions[0] = shelves.root;
    for (int k = 1; k <= q; ++k) {
        autoint t;
        if (t == 1) {
            autoint i, j;
            --i, --j;
            shelves.update(i * m + j, 1);
        } else if (t == 2) {
            autoint i, j;
            --i, --j;
            shelves.update(i * m + j, 0);
        } else if (t == 3) {
            autoint i;
            --i;
            shelves.inverse(i * m, (i + 1) * m);
        } else if (t == 4) {
            shelves.root = versions[autoint()];
        }
        versions[k] = shelves.root;
        cout << shelves.root->sum << '\n';
    }
}