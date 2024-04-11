
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// at each vertex, store set of pairs:
// (edge weight upper bound, max num edges ending at node)
// for an edge we find prev(lower_bound)

// insert (key, value) pair
// query: max value with key <= K

const int N = 1e5 + 5;

struct segtree {
    vi tree;
    segtree() {}
    segtree(int n) {
        tree.assign(4 * n, 0);
    }
    int query(int i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return tree[i];
        int m = (l + r) / 2;
        return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
    }
    void upd(int i, int l, int r, int k, int x) {
        if(l == r) {
            tree[i] = max(tree[i], x);
            return;
        }
        int m = (l + r) / 2;
        if(k <= m) upd(2 * i + 1, l, m, k, x);
        else upd(2 * i + 2, m + 1, r, k, x);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
};

int n, m, a[N], b[N], w[N];
vi in[N];
segtree seg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> w[i];
        in[b[i]].push_back(w[i]);
    }
    rep(i, 1, n + 1) {
        sort(all(in[i]));
        in[i].erase(unique(all(in[i])), in[i].end());
        seg[i] = segtree(sz(in[i]));
    }
    int ans = 0;
    rep(i, 0, m) {
        int key = (lower_bound(all(in[a[i]]), w[i]) - in[a[i]].begin());
        key--;
        int q = seg[a[i]].query(0, 0, sz(in[a[i]]) - 1, 0, key);
        ans = max(ans, q + 1);
        seg[b[i]].upd(0, 0, sz(in[b[i]]) - 1, lower_bound(all(in[b[i]]), w[i]) - in[b[i]].begin(), q + 1);
    }
    cout << ans << endl;
}