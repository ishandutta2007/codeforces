
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int n, m, k, l[N], r[N], x[N], y[N];
ll a[N], d[N], ti[N];

ll tree[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = a[l];
        lazy[i] = 0;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    tree[i] += lazy[i];
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, ll x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 1, m + 1) {
        cin >> l[i] >> r[i] >> d[i];
    }
    rep(i, 1, k + 1) {
        cin >> x[i] >> y[i];
        upd(0, 1, m, x[i], y[i], 1);
    }
    rep(i, 1, m + 1) {
        ti[i] = query(0, 1, m, i, i);
    }
    build(0, 1, n);
    rep(i, 1, m + 1) {
        upd(0, 1, n, l[i], r[i], ti[i] * d[i]);
    }
    rep(i, 1, n + 1) {
        cout << query(0, 1, n, i, i) << ' ';
    }
    cout << '\n';
}