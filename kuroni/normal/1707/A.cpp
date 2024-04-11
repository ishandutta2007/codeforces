#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    int n;
    vector<int> bit;

    fenwick_tree(int _n) : n(_n) {
        bit.resize(_n + 1);
    }

    void update(int u, int v) {
        for (; u <= n; u += u & -u) {
            bit[u] += v;
        }
    }

    int query(int u) {
        int ans = 0;
        for (; u > 0; u -= u & -u) {
            ans += bit[u];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n - 1, cur = 0; i >= 0; i--) {
            if (a[i] > cur) {
                cur++;
            }
            a[i] = min(a[i], cur);
        }
        for (int i = 0; i < n; i++) {
            cout << (a[i] <= q);
        }
        cout << '\n';
    }
}