#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 3e5 + 7;
const int MAXV = 3 * MAXN;
int n, m;
int a[MAXN], b[MAXN];
int q;
int t[MAXN], p[MAXN], x[MAXN];
void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }  
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
        if (t[i] <= 2) {
            cin >> p[i] >> x[i];
            --p[i];
        }
    }  
}  
int u = 0;
int v[MAXV];
void compr() {
    for (int i = 0; i < n; ++i) {
        v[u++] = a[i];
    }  
    for (int i = 0; i < m; ++i) {
        v[u++] = b[i];
    }  
    for (int i = 0; i < q; ++i) {
        if (t[i] <= 2) {
            v[u++] = x[i];
        }  
    }  
    sort(v, v + u);
    u = unique(v, v + u) - v;
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(v, v + u, a[i]) - v;
    }  
    for (int i = 0; i < m; ++i) {
        b[i] = lower_bound(v, v + u, b[i]) - v;
    }  
    for (int i = 0; i < q; ++i) {
        if (t[i] <= 2) {
            x[i] = lower_bound(v, v + u, x[i]) - v;
        }  
    }  
}  
int tree[MAXV << 2], add[MAXV << 2];
void push(int v) {
    tree[v * 2 + 1] += add[v];
    add[v * 2 + 1] += add[v];
    tree[v * 2 + 2] += add[v];
    add[v * 2 + 2] += add[v];
    add[v] = 0;
}  
void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) {
        return;
    }  
    if (l <= tl && tr <= r) {
        tree[v] += x;
        add[v] += x;
        return;
    }  
    int tm = (tl + tr) >> 1;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x);
    upd(v * 2 + 2, tm + 1, tr, l, r, x);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}
int get(int v, int tl, int tr) {
    if (tl == tr) {
        return tl;
    }  
    int tm = (tl + tr) >> 1;
    push(v);
    if (tree[v * 2 + 2] >= 1) {
        return get(v * 2 + 2, tm + 1, tr);
    }  
    else {
        return get(v * 2 + 1, tl, tm);
    }  
}  
void add1(int x) {
    //cout << x << ' ' << 1 << '\n';
    upd(0, 0, MAXV, 0, x, 1);
}
void del1(int x) {
    //cout << x << ' ' << -1 << '\n';
    upd(0, 0, MAXV, 0, x, -1);
}
void upd1(int p, int x) {
    del1(a[p]);
    a[p] = x;
    add1(a[p]);
}  
void add2(int x) {
    //cout << x << ' ' << -1 << '\n';
    upd(0, 0, MAXV, 0, x, -1);
}
void del2(int x) {                  
    //cout << x << ' ' << 1 << '\n';
    upd(0, 0, MAXV, 0, x, 1);
}  
void upd2(int p, int x) {
    del2(b[p]);
    b[p] = x;
    add2(b[p]);
}  
int get() {
    if (tree[0] >= 1) {
        return get(0, 0, MAXV);
    }  
    else {
        return -1;
    }  
}  
void solve() {
    compr();
    for (int i = 0; i < n; ++i) {
        add1(a[i]);
    }  
    for (int i = 0; i < m; ++i) {
        add2(b[i]);
    }  
}
void print() {
    for (int i = 0; i < q; ++i) {
        if (t[i] == 1) {
            upd1(p[i], x[i]);
        }  
        else {
            upd2(p[i], x[i]);
        }  
        {
            int ans = get();
            if (ans == -1) {
                cout << "-1\n";
            }  
            else {
                cout << v[ans] << '\n';
            }  
        }  
    }  
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    solve();
    print();
    return 0;
}