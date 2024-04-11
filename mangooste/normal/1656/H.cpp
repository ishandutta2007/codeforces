#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

using int128 = __int128_t;

istream& operator>>(istream &in, int128 &x) {
    string s;
    in >> s;
    x = 0;
    for (auto c : s) x = x * 10 + c - '0';
    return in;
}

ostream& operator<<(ostream &out, int128 x) {
    string s;
    while (x != 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(all(s));
    return out << s;
}

int128 gcd(int128 a, int128 b) {
    while (a != 0) {
        b %= a;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return b;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int128> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    struct segtree {
        int n;
        vector<int128> tree;

        segtree(int n = 0) : n(n), tree(2 * n) {}

        void build() {
            for (int i = n - 1; i; i--) {
                tree[i] = gcd(tree[i << 1], tree[i << 1 | 1]);
            }
        }

        void remove(int pos) {
            pos += n;
            tree[pos] = 0;
            for (pos >>= 1; pos; pos >>= 1) {
                tree[pos] = gcd(tree[pos << 1], tree[pos << 1 | 1]);
            }
        }

        int128 query() const {
            return tree[1];
        }
    };

    vector<segtree> tree_a(n, segtree(m)), tree_b(m, segtree(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto g = gcd(a[i], b[j]);
            tree_a[i].tree[m + j] = a[i] / g;
            tree_b[j].tree[n + i] = b[j] / g;
        }
    }
    for (int i = 0; i < n; i++) {
        tree_a[i].build();
    }
    for (int i = 0; i < m; i++) {
        tree_b[i].build();
    }

    vector<int> first(n), second(m);
    iota(all(first), 0);
    iota(all(second), 0);

    while (!first.empty() && !second.empty()) {
        vector<int> nfirst, nsecond;
        for (auto pos : first) {
            if (tree_a[pos].query() == 1) {
                nfirst.push_back(pos);
            } else {
                for (auto j : second) {
                    tree_b[j].remove(pos);
                }
            }
        }
        for (auto pos : second) {
            if (tree_b[pos].query() == 1) {
                nsecond.push_back(pos);
            } else {
                for (auto i : first) {
                    tree_a[i].remove(pos);
                }
            }
        }

        if (len(first) == len(nfirst) && len(second) == len(nsecond)) {
            break;
        }
        first = nfirst;
        second = nsecond;
    }

    if (first.empty() || second.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << len(first) << ' ' << len(second) << '\n';
        for (int i = 0; i < len(first); i++) {
            cout << a[first[i]] << " \n"[i == len(first) - 1];
        }
        for (int i = 0; i < len(second); i++) {
            cout << b[second[i]] << " \n"[i == len(second) - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}