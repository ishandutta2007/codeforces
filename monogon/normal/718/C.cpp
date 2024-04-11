
#pragma GCC optimize ("Ofast")
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

const int N = 1e5 + 5, M = 1e9 + 7;
int n, m, a[N];

struct mat {
    ll a[2][2];
    mat() {
        rep(i, 0, 2) rep(j, 0, 2) a[i][j] = 0;
    }
    mat operator+(const mat &o) const {
        mat m;
        rep(i, 0, 2) rep(j, 0, 2) {
            m.a[i][j] = (a[i][j] + o.a[i][j]) % M;
        }
        return m;
    }
    mat operator*(const mat &o) const {
        mat m;
        rep(i, 0, 2) rep(j, 0, 2) {
            rep(k, 0, 2) {
                m.a[i][j] += a[i][k] * o.a[k][j];
            }
            m.a[i][j] %= M;
        }
        return m;
    }
} fib[61];

struct node {
    ll f0, f1, lazy;
    node() {
        f0 = 1;
        f1 = lazy = 0;
    }
    node(ll f0, ll f1, ll lazy): f0(f0), f1(f1), lazy(lazy) {}
    void apply(const mat &o) {
        ll f0tmp = (o.a[0][0] * f0 + o.a[0][1] * f1) % M;
        ll f1tmp = (o.a[1][0] * f0 + o.a[1][1] * f1) % M;
        f0 = f0tmp;
        f1 = f1tmp;
    }
} tree[4 * N];

void prop(int i, int l, int r) {
    // binary exponentiation of matrix [[1, 1], [1, 0]]
    ll b = tree[i].lazy;
    mat X;
    X.a[0][0] = X.a[1][1] = 1;
    int k = 1;
    while(b > 0) {
        if(b & 1) {
            X = X * fib[k];
        }
        b /= 2;
        k++;
    }
    tree[i].apply(X);
    if(l < r) {
        tree[2 * i + 1].lazy += tree[i].lazy;
        tree[2 * i + 2].lazy += tree[i].lazy;
    }
    tree[i].lazy = 0;
}
void upd(int i, int l, int r, int L, int R, ll x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        tree[i].lazy += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i].f0 = (tree[2 * i + 1].f0 + tree[2 * i + 2].f0) % M;
    tree[i].f1 = (tree[2 * i + 1].f1 + tree[2 * i + 2].f1) % M;
}
ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i].f0;
    int m = (l + r) / 2;
    return (query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R)) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    fib[0].a[0][0] = fib[0].a[1][1] = 1;
    fib[1].a[0][0] = fib[1].a[0][1] = fib[1].a[1][0] = 1;
    rep(i, 2, 61) {
        fib[i] = fib[i - 1] * fib[i - 1];
    }
    rep(i, 1, n + 1) {
        upd(0, 1, n, i, i, a[i] - 1);
    }
    while(m--) {
        int ty, l, r;
        ll x;
        cin >> ty >> l >> r;
        if(ty == 1) {
            cin >> x;
            upd(0, 1, n, l, r, x);
        }else {
            cout << query(0, 1, n, l, r) << '\n';
        }
    }
}