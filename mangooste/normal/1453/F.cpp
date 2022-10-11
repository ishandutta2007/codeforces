#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using ll = long long;

#include <bits/extc++.h>

using namespace __gnu_pbds;
template<class T>
using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
struct MySet {
    struct Node {
        T x;
        int left, right;
        int sz;
        int y;

        Node(T x) : x(x), left(-1), right(-1), sz(1), y(rng()) {}
    };

    int root;
    vector<Node> nds;

    MySet() : root(-1) {}

    inline void relax(int v) {
        nds[v].sz = 1 + size(nds[v].left) + size(nds[v].right);
    }

    inline int size(int v) {
        if (v == -1) return 0;
        return nds[v].sz;
    }

    inline int newNode(T x) {
        int id = int(nds.size());
        nds.push_back(Node(x));
        return id;
    }

    pair<int, int> splitX(int v, T x) {                                   // ([-INF, x], (x, INF])
        if (v == -1) return {v, v};
        if (nds[v].x <= x) {
            pair<int, int> cur = splitX(nds[v].right, x);
            nds[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            pair<int, int> cur = splitX(nds[v].left, x);
            nds[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    pair<int, int> splitN(int v, int n) {                                // (first n elements, last N - n elements)
        if (v == -1) return {v, v};
        if (size(left) + 1 <= n) {
            pair<int, int> cur = split(nds[v].right, n - size(left) - 1);
            nds[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            pair<int, int> cur = split(nds[v].left, n);
            nds[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    int merge(int left, int right) {
        if (left == -1) return right;
        if (right == -1) return left;

        if (nds[left].y > nds[right].y) {
            nds[left].right = merge(nds[left].right, right);
            relax(left);
            return left;
        } else {
            nds[right].left = merge(left, nds[right].left);
            relax(right);
            return right;
        }
    }

    int insert(int v, T x, int nv) {
        if (v == -1) return nv;
        if (nds[nv].y < nds[v].y) {
            if (x < nds[v].x) {
                nds[v].left = insert(nds[v].left, x, nv);
            } else {
                nds[v].right = insert(nds[v].right, x, nv);
            }
            relax(v);
            return v;
        } else {
            auto [left, right] = splitX(v, x);
            nds[nv].left = left;
            nds[nv].right = right;
            relax(nv);
            return nv;
        }
    }

    inline void insert(T x) {
        int v = newNode(x);
        root = insert(root, x, v);
    }

    int erase(int v, T x) {
        if (v == -1) return -1;
        if (nds[v].x == x) return merge(nds[v].left, nds[v].right);
        if (x < nds[v].x) {
            nds[v].left = erase(nds[v].left, x);
        } else {
            nds[v].right = erase(nds[v].right, x);
        }
        relax(v);
        return v;
    }

    inline void erase(T x) {
        root = erase(root, x);
    }

    inline int find(T x) {
        auto [left, right] = splitX(root, x);
        int cnt = size(left);
        root = merge(left, right);
        return cnt;
    }

    inline int size() {
        return size(root);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i;
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = n - 2; i >= 0; i--) {
        MySet<pair<int, int>> st;
        st.nds.reserve(a[i] - i + 3);
        for (int j = i + 1; j <= a[i]; j++) {
            auto kek = [&]() {
                int x = rng();
                int y = rng();
                st.insert({x, y});
                st.erase({x, y});
            };
            kek();
            kek();
            if (j != i + 1) st.insert({a[j - 1], j - 1});
            if (j == n - 1) {
                dp[i][j] = st.size() - st.find({j, -1});;
            } else {
                if (a[i] == n - 1) continue;
                if (dp[j][a[i] + 1] == INT_MAX) continue;

                int cnt = dp[j][a[i] + 1];
                cnt += st.size() - st.find({j, -1});
                dp[i][j] = cnt;
            }
        }

        for (int j = n - 2; j >= i; j--) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }

    assert(dp[0][0] != INT_MAX);
    cout << dp[0][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}