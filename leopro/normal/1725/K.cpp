#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using ll = long long;
#define int ll
using namespace std;

struct DSU {
    int n;
    vector<int> parent, size, value;

    int get(int i) { return parent[i] == i ? i : parent[i] = get(parent[i]); }

    DSU(int n) : value(n), parent(n, 1), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int q;
    cin >> q;
    DSU dsu(n + 2 * q);
    vector<int> link(n);
    map<int, int> vals;
    for (int i = 0; i < n; ++i) {
        if (vals.contains(a[i])) {
            link[i] = vals[a[i]];
        } else {
            vals[a[i]] = i;
            dsu.value[i] = a[i];
            link[i] = i;
        }
    }
    for (int j = 0; j < q; ++j) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, w;
            cin >> k >> w;
            --k;
            if (vals.contains(w)) {
                int root = vals[w];
                link[k] = root;
            } else {
                link[k] = n + 2 * j;
                dsu.value[n + 2 * j] = w;
                vals[w] = n + 2 * j;
            }
        } else if (t == 2) {
            int k;
            cin >> k;
            --k;
            cout << dsu.value[dsu.get(link[k])] << '\n';
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            int m = (l + r) / 2;
            if (!vals.contains(l - 1)) {
                vals[l - 1] = n + 2 * j;
                dsu.value[n + 2 * j] = l - 1;
            }
            if (!vals.contains(r + 1)) {
                vals[r + 1] = n + 2 * j + 1;
                dsu.value[n + 2 * j + 1] = r + 1;
            }
            while (true) {
                auto it = vals.lower_bound(l);
                if (it == vals.end() || it->first > m) break;
                dsu.unite(vals[l - 1], it->second);
                vals.erase(it);
            }
            while (true) {
                auto it = vals.lower_bound(m + 1);
                if (it == vals.end() || it->first > r) break;
                dsu.unite(vals[r + 1], it->second);
                vals.erase(it);
            }
        }
    }
}