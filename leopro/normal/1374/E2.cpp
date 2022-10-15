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
        int tree_val, heap_val;
        int size, sum, cnt;

        vertex(int x) : tree_val(x), heap_val((rand() << 16) + rand()), left(nullptr), right(nullptr),
                        cnt(1), size(1), sum(x) {}

        vertex *update() {
            size = get_size(left) + cnt + get_size(right);
            sum = get_sum(left) + cnt * tree_val + get_sum(right);
            return this;
        }
    };

    static int get_size(vertex *v) { return (v == nullptr ? 0 : v->size); }

    static int get_sum(vertex *v) { return (v == nullptr ? 0 : v->sum); }

    vertex *root;

    treap() : root(nullptr) {}

    static pair<vertex *, vertex *> split(vertex *v, int val) {
        if (v == nullptr) return {nullptr, nullptr};
        if (v->tree_val < val) {
            auto spl = split(v->right, val);
            v->right = spl.first;
            return {v->update(), spl.second};
        } else {
            auto spl = split(v->left, val);
            v->left = spl.second;
            return {spl.first, v->update()};
        }
    }

    static vertex *merge(vertex *left, vertex *right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        if (left->heap_val < right->heap_val) {
            right->left = merge(left, right->left);
            return right->update();
        } else {
            left->right = merge(left->right, right);
            return left->update();
        }
    }

    static int sum(vertex *v, int cnt) {
        if (v == nullptr) return 0;
        if (get_size(v->left) >= cnt) return sum(v->left, cnt);
        if (cnt <= get_size(v->left) + v->cnt) return get_sum(v->left) + (cnt - get_size(v->left)) * v->tree_val;
        return get_sum(v->left) + v->cnt * v->tree_val + sum(v->right, cnt - v->cnt - get_size(v->left));
    }

    static vertex *erase(vertex *v, int x) {
        if (v->tree_val == x) {
            v->cnt--;
            return (v->cnt == 0 ? merge(v->left, v->right) : v->update());
        } else {
            if (v->tree_val < x) {
                v->right = erase(v->right, x);
                return v->update();
            } else {
                v->left = erase(v->left, x);
                return v->update();
            }
        }
    }
    static vertex *add(vertex *v, vertex *x) {
        auto spl1 = split(v, x->tree_val);
        auto spl2 = split(spl1.second, x->tree_val + 1);
        if (spl2.first == nullptr) spl2.first = x; else spl2.first->cnt += 1;
        return merge(spl1.first, merge(spl2.first->update(), spl2.second));
    }

    int sum(int cnt) { return sum(root, cnt); }

    void add(int x) { root = add(root, new vertex(x)); }

    void erase(int x) { root = erase(root, x); }
};

struct book {
    int t, a, b, idx;

    friend istream &operator>>(istream &is, book &b) {
        is >> b.t >> b.a >> b.b;
        return is;
    }

    bool operator<(const book &book) const {
        return t < book.t;
    }
};

void solve() {
    autoint n, m, k;
    vector<book> books(n);
    cin >> books;
    for (int i = 0; i < n; ++i) books[i].idx = i + 1;
    vector<vector<int>> boo(4);
    vector<vector<book>> bk(4);
    for (auto &book : books) {
        boo[book.a * 2 + book.b].push_back(book.t);
        bk[book.a * 2 + book.b].push_back(book);
    }
    vector<vector<int>> p(4);
    for (int i = 0; i < 4; ++i) {
        stable_sort(boo[i].begin(), boo[i].end());
        stable_sort(bk[i].begin(), bk[i].end());
        p[i] = prefix_sum(boo[i]);
    }

    treap t;
    for (int i = k; i < boo[0b11].size(); ++i) t.add(boo[0b11][i]);
    for (int x : boo[0b01]) t.add(x);
    for (int x : boo[0b10]) t.add(x);
    for (int x : boo[0b00]) t.add(x);

    int ans = 3e9;
    int best = -1;
    for (int all = k; all >= 0; --all) {
        if (treap::get_size(t.root) < m + all - k - k || p[0b11].size() <= all ||
            p[0b10].size() <= k - all || p[0b01].size() <= k - all || m + all - k - k < 0) {
            if (0 <= all - 1 && all - 1 < boo[0b11].size()) t.add(boo[0b11][all - 1]);
            if (boo[0b01].size() > k - all) t.erase(boo[0b01][k - all]);
            if (boo[0b10].size() > k - all) t.erase(boo[0b10][k - all]);
            continue;
        }
        int cur = p[0b11][all] + p[0b10][k - all] + p[0b01][k - all] + t.sum(m + all - k - k);
        if (ans > cur) {
            ans = cur;
            best = all;
        }
        if (0 <= all - 1 && all - 1 < boo[0b11].size()) t.add(boo[0b11][all - 1]);
        if (boo[0b01].size() > k - all) t.erase(boo[0b01][k - all]);
        if (boo[0b10].size() > k - all) t.erase(boo[0b10][k - all]);
    }
    if (ans == (int) 3e9) answer(-1);
    cout << ans << '\n';

    for (int i = 0; i < best; ++i) cout << bk[0b11][i].idx << ' ';
    for (int i = 0; i < k - best; ++i) cout << bk[0b10][i].idx << ' ';
    for (int i = 0; i < k - best; ++i) cout << bk[0b01][i].idx << ' ';

    vector<book> rem = bk[0b00];
    for (int i = k - best; i < bk[0b01].size(); ++i) rem.push_back(bk[0b01][i]);
    for (int i = k - best; i < bk[0b10].size(); ++i) rem.push_back(bk[0b10][i]);
    for (int i = best; i < bk[0b11].size(); ++i) rem.push_back(bk[0b11][i]);
    stable_sort(rem.begin(), rem.end());
    for (int i = 0; i < m + best - k - k; ++i) cout << rem[i].idx << ' ';


}