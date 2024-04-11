
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct node {
    int mx, lazy, left = -1, right = -1;
    node(int val) {
        mx = val;
        lazy = -1;
    }
};

vector<node> tree;

int build(int l, int r) {
    int k = sz(tree);
    tree.push_back(node(0));
    int m = (l + r) / 2;
    if(l < r) {
        tree[k].left = build(l, m);
        tree[k].right = build(m + 1, r);
    }
    return k;
}

int lz(int i, int x) {
    int k = sz(tree);
    tree.push_back(tree[i]);
    tree[k].lazy = x;
    return k;
}
int prop(int i, int l, int r) {
    if(tree[i].lazy == -1) return i;
    int k = sz(tree);
    tree.push_back(tree[i]);
    tree[k].mx = tree[k].lazy + r - l;
    if(l < r) {
        int m = (l + r) / 2;
        tree[k].left = lz(tree[k].left, tree[k].lazy);
        tree[k].right = lz(tree[k].right, tree[k].lazy + m + 1 - l);
    }
    tree[k].lazy = -1;
    return k;
}
int get(int i, int l, int r) {
    if(tree[i].lazy == -1) return tree[i].mx;
    return tree[i].lazy + r - l;
}
int upd(int i, int l, int r, int L, int R, int x) {
    if(r < L || R < l) return i;
    if(L <= l && r <= R) return lz(i, x + l - L);
    int m = (l + r) / 2;
    int k = prop(i, l, r);
    if(k == i) {
        k = sz(tree);
        tree.push_back(tree[i]);
    }
    tree[k].left = upd(tree[k].left, l, m, L, R, x);
    tree[k].right = upd(tree[k].right, m + 1, r, L, R, x);
    tree[k].mx = max(get(tree[k].left, l, m), get(tree[k].right, m + 1, r));
    return k;
}
int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    if(tree[i].lazy != -1) {
        return tree[i].lazy + min(r, R) - l;
    }
    if(L <= l && r <= R) return tree[i].mx;
    int m = (l + r) / 2;
    return max(query(tree[i].left, l, m, L, R), query(tree[i].right, m + 1, r, L, R));
}

// void printtree(int r, int n) {
//     rep(i, 1, n + 1) {
//         cout << query(r, 1, n, i, i) << ' ';
//     }
//     cout << '\n';
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h(n + 1);
    vector<pair<ll, int>> H;
    rep(i, 1, n + 1) {
        cin >> h[i];
        H.push_back({h[i], i});
    }
    sort(all(H), greater<>());
    set<int> se;
    rep(i, 0, n + 2) se.insert(i);
    vi roots;
    roots.push_back(build(1, n));
    rep(idx, 0, n) {
        int i = H[idx].second;
        se.erase(i);
        auto it = se.lower_bound(i);
        int l = *prev(it) + 1;
        int r = *it - 1;
        // update [i, r] with x - l + 1
        roots.push_back(upd(roots.back(), 1, n, i, r, i - l + 1));
    }
    // rep(i, 1, sz(roots)) {
    //     cout << "root " << i << ' ' << roots[i] << '\n';
    //     printtree(roots[i], n);
    // }
    int m;
    cin >> m;
    while(m--) {
        int l, r, w;
        cin >> l >> r >> w;
        // binary search persistent segtree
        int L = 1, R = n;
        while(L < R) {
            int m = (L + R) / 2;
            if(query(roots[m], 1, n, l + w - 1, r) < w) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        cout << H[L - 1].first << '\n';
    }
}