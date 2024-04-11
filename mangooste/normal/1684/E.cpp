#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    struct segtree {
        int n;
        vector<pair<int, int>> tree;

        segtree(int sz) {
            n = 1;
            while (n < sz) n <<= 1;
            tree.resize(2 * n, {0, 0});
        }

        void add(int pos, pair<int, int> delta) {
            for (pos += n; pos; pos >>= 1) {
                tree[pos].first += delta.first;
                tree[pos].second += delta.second;
            }
        }

        int solve(int steps) {
            return solve(1, 0, n, steps);
        }

        int solve(int v, int vl, int vr, int steps) {
            if (vr - vl == 1) {
                if (vl == 0) return 0;
                return max(0, tree[v].second - steps / vl);
            }
            int vm = (vl + vr) >> 1;
            if (tree[v << 1].first <= steps) {
                steps -= tree[v << 1].first;
                return solve(v << 1 | 1, vm, vr, steps);
            }
            return solve(v << 1, vl, vm, steps) + tree[v << 1 | 1].second;
        }
    } tree(n + 1);

    for (auto [x, cnt] : freq) {
        tree.add(cnt, {cnt, 1});
    }

    int ans = n;
    for (int mex = 0, zeroes = 0; mex <= n; zeroes += freq[mex++] == 0) {
        if (freq[mex] != 0) {
            tree.add(freq[mex], {-freq[mex], -1});
        }
        int left = k - freq[mex];
        if (left < 0 || zeroes - freq[mex] > left) continue;
        ans = min(ans, max(mex == 0 ? 1 : 0, tree.solve(left)));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}