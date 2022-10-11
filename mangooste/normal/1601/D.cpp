#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    vector<int> coords;
    coords.push_back(d);

    for (auto &[x, y] : a) {
        cin >> y >> x;
        coords.push_back(x);
        coords.push_back(y);
    }
    sort(all(a), [&](const auto &a, const auto &b) {
        return a.first + a.second < b.first + b.second;
    });

    sort(all(coords));
    coords.resize(unique(all(coords)) - coords.begin());

    auto get = [&](int x) {
        return lower_bound(all(coords), x) - coords.begin();
    };

    struct segtree {
        int n;
        vector<int> tree, mod;

        segtree(int n) : n(n), tree(4 * n, -1e9), mod(4 * n) {}

        void apply(int v, int delta) {
            tree[v] += delta;
            mod[v] += delta;
        }

        void push(int v) {
            apply(v << 1, mod[v]);
            apply(v << 1 | 1, mod[v]);
            mod[v] = 0;
        }

        void add(int from, int to) {
            add(1, 0, n, from, to);
        }

        void add(int v, int vl, int vr, int from, int to) {
            if (to <= vl || vr <= from) return;
            if (from <= vl && vr <= to) {
                apply(v, 1);
                return;
            }
            push(v);
            int vm = (vl + vr) >> 1;
            add(v << 1, vl, vm, from, to);
            add(v << 1 | 1, vm, vr, from, to);
            tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
        }

        int get_max(int from, int to) {
            return get_max(1, 0, n, from, to);
        }

        int get_max(int v, int vl, int vr, int from, int to) {
            if (to <= vl || vr <= from) return -1e9;
            if (from <= vl && vr <= to) return tree[v];
            push(v);
            int vm = (vl + vr) >> 1;
            return max(get_max(v << 1, vl, vm, from, to), get_max(v << 1 | 1, vm, vr, from, to));
        }

        void set_max(int pos, int value) {
            set_max(1, 0, n, pos, value);
        }

        void set_max(int v, int vl, int vr, int pos, int value) {
            if (vr - vl == 1) {
                tree[v] = max(tree[v], value);
                return;
            }
            push(v);
            int vm = (vl + vr) >> 1;
            pos < vm ? set_max(v << 1, vl, vm, pos, value) : set_max(v << 1 | 1, vm, vr, pos, value);
            tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
        }
    } tree(len(coords));

    for (int i = get(d); i < len(coords); i++) {
        tree.set_max(i, 0);
    }

    for (auto [x, y] : a) {
        x = get(x);
        y = get(y);
        tree.add(x, y + 1);
        if (x == 0) continue;
        tree.set_max(x, tree.get_max(0, min(x, y + 1)) + 1);
    }
    cout << tree.get_max(0, len(coords)) << '\n';
}