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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (auto &x : a) cin >> x;

    struct node {
        ll res = 0, pref = 0, suf = 0, sum = 0;

        node() {}
        node(ll value) {
            res = pref = suf = max(0ll, value);
            sum = value;
        }

        static node merge(const node &left, const node &right) {
            node res;
            res.res = max({left.res, right.res, left.suf + right.pref});
            res.pref = max({left.pref, left.sum + right.pref});
            res.suf = max({right.suf, right.sum + left.suf});
            res.sum = left.sum + right.sum;
            return res;
        }
    };

    auto reverse_mask = [&](int mask) {
        int imask = 0;
        for (int i = 0; i < n; i++) {
            imask ^= (mask >> i & 1) << n - 1 - i;
        }
        return imask;
    };
    vector<int> ord(1 << n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int mask1, const int mask2) {
        return reverse_mask(mask1) < reverse_mask(mask2);
    });

    vector<int> left(1 << n), right(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        left[i] = 2 * i + 1;
        right[i] = left[i] + 1;
    }

    vector<node> tree(2 << n);
    for (int i = 0; i < (1 << n); i++) {
        tree[(1 << n) - 1 + i] = node(a[i]);
    }

    auto relax_node = [&](int i) {
        tree[i] = node::merge(tree[left[i]], tree[right[i]]);
    };
    for (int i = (1 << n) - 2; i >= 0; i--) {
        relax_node(i);
    }

    int cur_mask = 0;
    vector<ll> ans(1 << n);
    ans[cur_mask] = tree[0].res;
    assert(ord[0] == cur_mask);
    ord.erase(ord.begin());
    for (int mask : ord) {
        int diff = mask ^ cur_mask;
        for (int layer = 0; layer < n; layer++) {
            if (!(diff >> layer & 1)) continue;
            int dep = n - 1 - layer;
            for (int v = (1 << dep) - 1; v < (1 << dep + 1) - 1; v++) {
                swap(left[v], right[v]);
            }
        }
        int layer = n - 1 - __builtin_ctz(diff);
        cur_mask = mask;
        for (int i = (1 << layer + 1) - 2; i >= 0; i--) {
            relax_node(i);
        }
        ans[cur_mask] = tree[0].res;
    }

    int q;
    cin >> q;
    int mask = 0;
    while (q--) {
        int k;
        cin >> k;
        mask ^= 1 << k;
        cout << ans[mask] << '\n';
    }
}