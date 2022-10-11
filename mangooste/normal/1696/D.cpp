#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    array<vector<int>, 2> right, left;
    for (int rot : {0, 1}) {
        for (int dir = 0; dir < 2; dir++, reverse(all(a))) {
            auto &cur = (dir ? left : right)[rot];
            cur.resize(n);
            vector<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
                cur[i] = st.empty() ? n : st.back();
                st.push_back(i);
            }
        }
        reverse(all(left[rot]));
        for (auto &x : left[rot]) x = n - 1 - x;
        for (auto &x : a) x *= -1;
    }

    struct segtree {
        int n;
        vector<multiset<int>> a;
        vector<int> tree;

        segtree(int size = 0) {
            n = 1;
            while (n < size) n <<= 1;
            a.resize(n);
            for (int i = 0; i < n; i++) {
                a[i].insert(1e9);
            }
            tree.resize(2 * n, 1e9);
        }

        void update(int pos, int val, bool erase) {
            if (erase) {
                auto it = a[pos].find(val);
                assert(it != a[pos].end());
                a[pos].erase(it);
            } else {
                a[pos].insert(val);
            }
            tree[pos + n] = *a[pos].begin();
            for (pos += n; pos > 1; pos >>= 1) {
                tree[pos >> 1] = min(tree[pos], tree[pos ^ 1]);
            }
        }

        int go(int from, int to) {
            return go(1, 0, n, from, to);
        }

        int go(int v, int vl, int vr, int from, int to) {
            if (vr <= from || to <= vl || tree[v] >= from) return to;
            if (vr - vl == 1) return vl;
            int vm = (vl + vr) >> 1;
            int res = go(v << 1, vl, vm, from, to);
            return res == to ? go(v << 1 | 1, vm, vr, from, to) : res;
        }
    };

    array<segtree, 2> tree;
    tree.fill(segtree(n));
    for (int rot : {0, 1}) {
        for (int i = 1; i < n; i++) {
            tree[rot].update(i, left[rot][i], false);
        }
    }

    vector<int> dist(n, n), que{0};
    dist[0] = 0;
    for (int ptr = 0; ptr < len(que); ptr++) {
        int v = que[ptr];
        for (int rot : {0, 1}) {
            while (true) {
                int u = tree[rot ^ 1].go(v, right[rot][v]);
                assert(u != v);
                if (u == right[rot][v]) break;
                assert(dist[u] == n);
                dist[u] = dist[v] + 1;
                que.push_back(u);
                for (int j : {0, 1}) {
                    tree[j].update(u, left[j][u], true);
                }
            }
        }
    }

    assert(dist.back() != n);
    cout << dist.back() << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}