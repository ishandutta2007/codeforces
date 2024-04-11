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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> pref(n);
    partial_sum(all(a), pref.begin());
    vector<ll> tree(4 * n), mod(4 * n);

    y_combinator([&](auto build, int v, int vl, int vr) -> void {
        if (vr - vl == 1) {
            tree[v] = pref[vl];
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    })(1, 0, n);

    while (q--) {
        int pos, new_value;
        cin >> pos >> new_value;
        pos--;

        auto push = [&](int v, int vl, int vr) {
            if (vr - vl > 1) {
                mod[v << 1] += mod[v];
                mod[v << 1 | 1] += mod[v];
            }

            tree[v] += mod[v];
            mod[v] = 0;
        };

        y_combinator([&](auto update, int v, int vl, int vr) -> void {
            if (pos <= vl) {
                mod[v] += new_value - a[pos];
                push(v, vl, vr);
                return;
            }

            push(v, vl, vr);
            if (vr <= pos)
                return;

            int vm = (vl + vr) >> 1;
            update(v << 1, vl, vm);
            update(v << 1 | 1, vm, vr);
            tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
        })(1, 0, n);

        a[pos] = new_value;
        int answer = -1;

        if (a[0] == 0) {
            cout << "1\n";
            continue;
        }

        ll cur_value = a[0];
        for (int i = 0;;) {
            auto [j, value] = y_combinator([&](auto get, int v, int vl, int vr) -> pair<int, ll> {
                push(v, vl, vr);
                if (vr <= i + 1 || tree[v] < 2 * cur_value)
                    return {n, -1};

                if (vr - vl == 1)
                    return {vl, tree[v]};

                int vm = (vl + vr) >> 1;
                auto [pos, value] = get(v << 1, vl, vm);
                if (pos == n)
                    tie(pos, value) = get(v << 1 | 1, vm, vr);

                return {pos, value};
            })(1, 0, n);

            if (j == n)
                break;

            ll before = y_combinator([&](auto get, int v, int vl, int vr) -> ll {
                push(v, vl, vr);
                if (vr - vl == 1)
                    return tree[v];

                int vm = (vl + vr) >> 1;
                return j - 1 < vm ? get(v << 1, vl, vm) : get(v << 1 | 1, vm, vr);
            })(1, 0, n);

            if (value == 2 * before) {
                answer = j + 1;
                break;
            }

            cur_value = value;
            i = j;
        }

        cout << answer << '\n';
    }
}