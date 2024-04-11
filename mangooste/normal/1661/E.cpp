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

    int n;
    cin >> n;
    array<vector<int>, 3> a;
    a.fill(vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    struct node {
        int par[6], ans;
        bool empty;
        array<int, 3> left, right;

        int root(int v) {
            return par[v] == v ? v : par[v] = root(par[v]);
        }
        
        bool unite(int v, int u) {
            v = root(v);
            u = root(u);
            if (v == u) return false;
            par[v] = u;
            return true;
        }

        node() {
            empty = true;
        }

        node(const array<int, 3> &s) {
            assert(len(s) == 3);
            left = right = s;
            empty = false;

            iota(all(par), 0);
            for (int i : {0, 1, 2}) {
                unite(i, 3 + i);
                if (i && s[i] == 1 && s[i - 1] == 1) {
                    unite(i, i - 1);
                }
            }
            
            ans = count(all(s), 1);
            for (int i : {1, 2}) {
                ans -= s[i] == 1 && s[i - 1] == 1;
            }
        }

        static node merge(node &a, node &b) {
            if (a.empty) return b;
            if (b.empty) return a;

            node res;
            res.empty = false;
            iota(all(res.par), 0);
            res.ans = a.ans + b.ans;
            res.left = a.left;
            res.right = b.right;

            static int tmp_par[12];
            for (int i = 0; i < 6; i++) {
                tmp_par[i] = a.par[i];
                tmp_par[6 + i] = 6 + b.par[i];
            }

            auto root = y_combinator([&](auto root, int v) -> int {
                return tmp_par[v] == v ? v : tmp_par[v] = root(tmp_par[v]);
            });

            for (int i : {0, 1, 2}) {
                if (a.right[i] != 1 || b.left[i] != 1) continue;
                int v = root(3 + i);
                int u = root(6 + i);
                if (v == u) continue;
                res.ans--;
                tmp_par[v] = u;
            }

            for (int left : {0, 1, 2}) {
                for (int right : {0, 1, 2}) {
                    if (root(left) == root(right)) {
                        res.unite(left, right);
                    }
                    if (root(9 + left) == root(9 + right)) {
                        res.unite(3 + left, 3 + right);
                    }
                }
                for (int right : {3, 4, 5}) {
                    if (root(left) == root(6 + right)) {
                        res.unite(left, right);
                    }
                }
            }
            return res;
        }
    };

    int sz = 1;
    while (sz < n) sz <<= 1;
    vector<node> tree(sz << 1);
    for (int i = 0; i < n; i++) {
        tree[sz + i] = node({a[0][i], a[1][i], a[2][i]});
    }
    for (int i = sz - 1; i; i--) {
        tree[i] = node::merge(tree[i << 1], tree[i << 1 | 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        node left, right;
        for (l += sz - 1, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = node::merge(left, tree[l++]);
            if (r & 1) right = node::merge(tree[--r], right); 
        }
        cout << node::merge(left, right).ans << '\n';
    }
}