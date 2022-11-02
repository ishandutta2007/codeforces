#include <bits/stdc++.h>

using namespace std;

const int LCM = 60;

struct Node {
    int v[LCM];

    Node() {
        memset(v, 0, sizeof(int) * LCM);
    }

    Node(const Node& n) {
        memcpy(v, n.v, sizeof(int) * LCM);
    }

    Node operator = (const Node& n) {
        memcpy(v, n.v, sizeof(int) * LCM);
    }
};

Node forPeriod(int t) {
    Node res;
    for (int i = 0; i < LCM; i++) {
        res.v[i] = 1;
        if (i % t == 0)
            res.v[i]++;
    }
    return res;
}

const int N = (int)1e5 + 10;

Node unite(Node a, Node b) {
    Node res;
    for (int i = 0; i < LCM; i++) {
        int t1 = a.v[i];
        int t2 = t1 + (b.v[(i + t1) % LCM]);
        res.v[i] = t2;
    }
    return res;
}

Node tree[4 * N + 10];
int a[N];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = forPeriod(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

void put(int i, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[i] = forPeriod(val);
        return;
    }
    int m = (tl + tr) / 2;
    if (pos <= m)
        put(2 * i + 1, tl, m, pos, val);
    else
        put(2 * i + 2, m + 1, tr, pos, val);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

Node calc(int i, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
        return tree[i];
    int m = (tl + tr) / 2;
    Node nl;
    Node nr;
    if (l <= m)
        nl = calc(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
        nr = calc(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    return unite(nl, nr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(0, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        int x;
        int y;
        cin >> x >> y;
        if (s == "A")
            cout << calc(0, 0, n - 1, x - 1, y - 2).v[0] << "\n";
        else
            put(0, 0, n - 1, x - 1, y);
    }
    return 0;
}