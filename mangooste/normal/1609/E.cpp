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
    string s;
    cin >> n >> q >> s;

    struct node {
        int a, b, c, ab, bc, abc;

        node(char ch) : a(0), b(0), c(0), ab(0), bc(0), abc(0) {
            a += ch == 'a';
            b += ch == 'b';
            c += ch == 'c';
        }

        node() {}

        node(int a, int b, int c, int ab, int bc, int abc) :
            a(a), b(b), c(c), ab(ab), bc(bc), abc(abc)
        {}
    };

    auto merge = [&](const node &left, const node &right) {
        return node(left.a + right.a, left.b + right.b, left.c + right.c,
                min(left.ab + right.b, left.a + right.ab),
                min(left.bc + right.c, left.b + right.bc),
                min({left.a + right.abc, left.ab + right.bc, left.abc + right.c}));
    };

    vector<node> tree(4 * n);

    y_combinator([&](auto build, int v, int vl, int vr) -> void {
        if (vr - vl == 1) {
            tree[v] = node(s[vl]);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    })(1, 0, n);

    while (q--) {
        int i;
        char c;
        cin >> i >> c;

        y_combinator([&](auto update, int v, int vl, int vr, int pos) -> void {
            if (vr - vl == 1) {
                tree[v] = node(c);
                return;
            }

            int vm = (vl + vr) >> 1;
            pos < vm ? update(v << 1, vl, vm, pos) : update(v << 1 | 1, vm, vr, pos);
            tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
        })(1, 0, n, i - 1);

        cout << tree[1].abc << '\n';
    }
}