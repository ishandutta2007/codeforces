#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    constexpr int N = 44445;
    vector<int> nxt(N + 1, -1);
    for (int i = N - 1; i >= 0; i--) {
        bool good = true;
        int value = i;
        while (value) {
            good &= value % 10 == 4 || value % 10 == 7;
            value /= 10;
        }
        if (good) nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    struct node {
        int left_value = 0, mn = 1e9, cnt_mn = 0, mod = 0;

        node() {}
        node(int left_value, int x) : left_value(left_value), mn(x), cnt_mn(1) {}

        static node merge(const node &left, const node &right) {
            node res;
            res.left_value = left.left_value;
            res.mn = min(left.mn, right.mn);
            if (left.mn == res.mn) res.cnt_mn += left.cnt_mn;
            if (right.mn == res.mn) res.cnt_mn += right.cnt_mn;
            return res;
        }
    };

    vector<node> tree(4 * n);

    y_combinator([&](auto build, int v, int vl, int vr) -> void {
        if (vr - vl == 1) {
            tree[v] = node(a[vl], nxt[a[vl]] - a[vl]);
            return;
        }
        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    })(1, 0, n);

    auto apply = [&](int v, int value) {
        tree[v].left_value += value;
        tree[v].mn -= value;
        tree[v].mod += value;
    };

    auto push = [&](int v) {
        apply(v << 1, tree[v].mod);
        apply(v << 1 | 1, tree[v].mod);
        tree[v].mod = 0;
    };

    while (q--) {
        string s;
        cin >> s;
        if (s == "count") {
            int l, r;
            cin >> l >> r;
            l--;

            auto res = y_combinator([&](auto query, int v, int vl, int vr) -> node {
                if (r <= vl || vr <= l) return node();
                if (l <= vl && vr <= r) return tree[v];
                push(v);
                int vm = (vl + vr) >> 1;
                return node::merge(query(v << 1, vl, vm), query(v << 1 | 1, vm, vr));
            })(1, 0, n);

            assert(res.mn >= 0);
            if (res.mn > 0) {
                cout << "0\n";
            } else {
                cout << res.cnt_mn << '\n';
            }
        } else if (s == "add") {
            int l, r, value;
            cin >> l >> r >> value;
            l--;

            y_combinator([&](auto add, int v, int vl, int vr) -> void {
                if (r <= vl || vr <= l) return;
                if (l <= vl && vr <= r) {
                    apply(v, value);
                    return;
                }
                push(v);
                int vm = (vl + vr) >> 1;
                add(v << 1, vl, vm);
                add(v << 1 | 1, vm, vr);
                tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
            })(1, 0, n);

            y_combinator([&](auto update, int v, int vl, int vr) -> void {
                if (vr - vl == 1) {
                    tree[v].mn = nxt[tree[v].left_value] - tree[v].left_value;
                    return;
                }

                push(v);
                int vm = (vl + vr) >> 1;
                if (tree[v << 1].mn < 0) {
                    update(v << 1, vl, vm);
                }
                if (tree[v << 1 | 1].mn < 0) {
                    update(v << 1 | 1, vm, vr);
                }
                tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
            })(1, 0, n);
        }
    }
}