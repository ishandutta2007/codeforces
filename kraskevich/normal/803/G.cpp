#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 10;

struct SegmentTree {
    vector<int> t;
    vector<int> add;
    int n;

    SegmentTree(int n_ = 0): t(4 * n_ + 10, INF), add(4 * n_ + 10, 0), n(n_) {}

    void push(int i) {
        if (!add[i])
            return;
        t[i] = add[i];
        if (2 * i + 2 < (int)t.size()) {
            add[2 * i + 1] = add[i];
            add[2 * i + 2] = add[i];
        }
        add[i] = 0;
    }

    void upd(int i, int tl, int tr, int l, int r, int x) {
        push(i);
        if (l == tl && r == tr) {
            add[i] = x;
            return;
        }
        int m = (tl + tr) / 2;
        if (l <= m)
            upd(2 * i + 1, tl, m, l, min(r, m), x);
        if (r > m)
            upd(2 * i + 2, m + 1, tr, max(m + 1, l), r, x);
        push(2 * i + 1);
        push(2 * i + 2);
        t[i] = min(t[2 * i + 1], t[2 * i + 2]);
    }
    
    void upd(int l, int r, int x) {
        upd(0, 0, n - 1, l, r, x);
    }

    int get(int i, int tl, int tr, int l, int r) {
        push(i);
        if (l == tl && r == tr)
            return t[i];
        int ml = INF;
        int mr = INF;
        int m = (tl + tr) / 2;
        if (l <= m)
            ml = get(2 * i + 1, tl, m, l, min(r, m));
        if (r > m)
            mr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
        return min(ml, mr);
    }

    int get(int l, int r) {
        return get(0, 0, n - 1, l, r);
    }
};

SegmentTree tree_a;
int n;

int get_init(int l, int r) {
    if (r - l + 1 >= n)
        return tree_a.get(0, n - 1);
    l %= n;
    r %= n;
    if (r < l)
        r += n;
    return tree_a.get(l, r);
}

struct Node {
    int val;
    int add{0};
    Node* L{nullptr};
    Node* R{nullptr};

    Node(int v): val(v) {}
};

Node* root;

void push(Node*& t, int l, int r) {
    if (!t)
        t = new Node(get_init(l, r));
    if (t->add)
        t->val = t->add;
    int m = (l + r) / 2;
    if (l != r && !t->L) 
        t->L = new Node(get_init(l, m));
    if (l != r && !t->R) 
        t->R = new Node(get_init(m + 1, r));
    if (l != r && t->add)
        t->L->add = t->R->add = t->add;
    t->add = 0;
}

void upd(Node*& t, int tl, int tr, int l, int r, int x) {
    push(t, tl, tr);
    if (l == tl && r == tr) {
        t->add = x;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        upd(t->L, tl, m, l, min(r, m), x);
    if (r > m)
        upd(t->R, m + 1, tr, max(m + 1, l), r, x);
    push(t->L, tl, m);
    push(t->R, m + 1, tr);
    t->val = min(t->L->val, t->R->val);
}

int get(Node*& t, int tl, int tr, int l, int r) {
    push(t, tl, tr);
    if (l == tl && r == tr)
        return t->val;
    int m = (tl + tr) / 2;
    int ml = INF;
    int mr = INF;
    if (l <= m)
        ml = get(t->L, tl, m, l, min(r, m));
    if (r > m)
        mr = get(t->R, m + 1, tr, max(m + 1, l), r);
    return min(ml, mr);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    tree_a = SegmentTree(2 * n);
    for (int i = 0; i < 2 * n; i++)
        tree_a.upd(i, i, a[i % n]);
    int q;
    cin >> q;
    int R = n * k - 1;
    for (int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        --r;
        if (t == 2)
            cout << get(root, 0, R, l, r) << "\n";
        else {
            int x;
            cin >> x;
            upd(root, 0, R, l, r, x);
        }
    }
}