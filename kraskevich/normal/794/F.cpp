#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Node {
    ll sum[10];

    Node() {
        fill(sum, sum + 10, 0);
    }

    Node unite(const Node& rhs) const {
        Node res;
        for (int i = 0; i < 10; i++)
            res.sum[i] = sum[i] + rhs.sum[i];
        return res;
    }

    ll eval() const {
        ll res = 0;
        for (int i = 0; i < 10; i++)
            res += sum[i] * i;
        return res;
    }
};

struct Add {
    int p[10];

    Add() {
        iota(p, p + 10, 0);
    }

    Add unite(const Add& add) const {
        Add res;
        for (int i = 0; i < 10; i++)
            res.p[i] = add.p[p[i]];
        return res;
    }
};

const int N = 100 * 1000 + 10;

Node t[4 * N + 10];
Add a[4 * N + 10];

void push(int i) {
    if (2 * i + 2 < 4 * N + 10) {
        a[2 * i + 1] = a[2 * i + 1].unite(a[i]);
        a[2 * i + 2] = a[2 * i + 2].unite(a[i]);
    }
    ll new_s[10];
    fill(new_s, new_s + 10, 0);
    for (int d = 0; d < 10; d++)
        new_s[a[i].p[d]] += t[i].sum[d];
    copy(new_s, new_s + 10, t[i].sum);
    a[i] = Add();
}

ll arr[N];

void build(int i, int l, int r) {
    if (l == r) {
        ll p = 1;
        while (arr[l]) {
            t[i].sum[arr[l] % 10] += p;
            p *= 10;
            arr[l] /= 10; 
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    t[i] = t[2 * i + 1].unite(t[2 * i + 2]);
}

Node get(int i, int tl, int tr, int l, int r) {
    push(i);
    if (l == tl && r == tr)
        return t[i];
    int m = (tl + tr) / 2;
    Node nl;
    Node nr;
    if (l <= m)
        nl = get(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
        nr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    return nl.unite(nr);
}

void upd(int i, int tl, int tr, int l, int r, const Add& add) {
    push(i);
    if (l == tl && r == tr) {
        a[i] = add;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        upd(2 * i + 1, tl, m, l, min(r, m), add);
    if (r > m)
        upd(2 * i + 2, m + 1, tr, max(m + 1, l), r, add);
    t[i] = get(2 * i + 1, 0, 0, 0, 0).unite(get(2 * i + 2, 0, 0, 0, 0));
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            Add add;
            add.p[x] = y;
            upd(0, 0, n - 1, l, r, add);
        } else {
            cout << get(0, 0, n - 1, l, r).eval() << "\n";
        }
    }
}