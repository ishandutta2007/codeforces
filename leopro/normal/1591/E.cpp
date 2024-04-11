#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct treap {
    struct node {
        node *left = nullptr, *right = nullptr;
        int size = 1;
        int mySize = 1;
        int heap = rng();
        int key;
        set<int> vals;

        node(int x, int y = 0) : key(x), vals(set<int>{y}) {}

        friend int getSize(node *v) { return v ? v->size : 0; }

        void add(int x) {
            vals.insert(x);
            mySize++;size++;
        }

        void erase(int x) {
            vals.erase(x);
           mySize--; size--;
        }

        node *update() {
            size = getSize(left) +mySize + getSize(right);
            return this;
        }

        int kth(int k) {
            int sz = getSize(left);
            if (k < sz) return left->kth(k);
            if (k < sz + mySize && mySize) return *vals.begin();
            return right->kth(k - sz - mySize);
        }

        int count(int low) {
            int sz = getSize(left);
            if (low == key) return sz;
            if (low < key) return (left ? left->count(low) : 0);
            return sz + mySize + (right ? right->count(low) : 0);
        }
    };

    pair<node *, node *> split(node *v, int val) {
        if (v == nullptr) return {v, v};
        if (v->key < val) {
            auto[l, r] = split(v->right, val);
            v->right = l;
            return {v->update(), r};
        } else {
            auto[l, r] = split(v->left, val);
            v->left = r;
            return {l, v->update()};
        }
    }

    node *merge(node *l, node *r) {
        if (!l) return r;
        if (!r) return l;
        if (l->heap > r->heap) {
            l->right = merge(l->right, r);
            return l->update();
        } else {
            r->left = merge(l, r->left);
            return r->update();
        }
    }

    node *root;

    treap() : root(nullptr) {}

    void add(int key, int value) {
        if (root == nullptr) {
            root = new node(key, value);
        } else {
            auto[l, m] = split(root, key);
            auto[mm, r] = split(m, key + 1);
            if (mm == nullptr) mm = new node(key, value); else mm->add(value);
            root = merge(l, merge(mm, r));
        }
    }

    void sub(int key, int value) {
        auto[l, m] = split(root, key);
        auto[mm, r] = split(m, key + 1);
        mm->erase(value);
        root = merge(l, merge(mm, r));
    }

    int kth(int k, int low) {
        int cnt = root ? root->count(low) : 0;
        if (k + cnt >= getSize(root)) return -1;
        return root->kth(k + cnt);
    }
};

using query = tuple<int, int, int>; // l, k, index

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x: a)cin >> x;
    vector<int> p(n);
    for (int i = 1; i < n; ++i) cin >> p[i];
    vector<vector<int>> t(n);
    for (int i = 1; i < n; ++i) t[--p[i]].push_back(i);
    vector<vector<query>> qs(n);
    for (int i = 0; i < q; ++i) {
        int v, l, k;
        cin >> v >> l >> k;
        --v, --k;
        qs[v].emplace_back(l, k, i);
    }
    vector<int> ans(q);
    vector<int> cnt(n + 1);
    treap freq;
    auto dfs = [&](auto dfs, int cur) -> void {
        int f = ++cnt[a[cur]];
        if (f > 1) freq.sub(f - 1, a[cur]);
        freq.add(f, a[cur]);
        for (auto[l, k, index]: qs[cur]) {
            int x = freq.kth(k, l);
            ans[index] = x;
        }
        for (int next: t[cur]) dfs(dfs, next);
        f = cnt[a[cur]]--;
        freq.sub(f, a[cur]);
        if (f > 1) freq.add(f - 1, a[cur]);
    };
    dfs(dfs, 0);
    for (int i = 0; i < q; ++i) cout << ans[i] << ' ';
    cout << '\n';
}