
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

const int N = 1e5 + 5, M = 1e9 + 7;
int n, m;
ll lazy[4 * N], a[N], precomp[N][6];
array<ll, 6> tree[4 * N];
ll choose[6][6];

ll eval(const array<ll, 6> &a, int k, ll x) {
    ll res = 0;
    ll p = 1;
    rep(i, 0, k + 1) {
        res = (res + ((choose[k][i] * p) % M) * a[k - i]) % M;
        p = (p * x) % M;
    }
    return res;
}

array<ll, 6> add(const array<ll, 6> left, const array<ll, 6> right, int len) {
    array<ll, 6> res;
    rep(l, 0, 6) {
        res[l] = (left[l] + eval(right, l, len)) % M;
    }
    return res;
}

void build(int i, int l, int r) {
    lazy[i] = -1;
    if(l == r) {
        rep(k, 0, 6) tree[i][k] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = add(tree[2 * i + 1], tree[2 * i + 2], m - l + 1);
}

void prop(int i, int l, int r) {
    if(lazy[i] == -1) return;
    rep(j, 0, 6) {
        tree[i][j] = (lazy[i] * precomp[r - l + 1][j]) % M;
    }
    if(l < r) {
        lazy[2 * i + 1] = lazy[2 * i + 2] = lazy[i];
    }
    lazy[i] = -1;
}
array<ll, 6> query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) {
        array<ll, 6> res;
        fill(res.begin(), res.end(), 0LL);
        return res;
    }
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    if(R <= m) return query(2 * i + 1, l, m, L, R);
    else if(m + 1 <= L) return query(2 * i + 2, m + 1, r, L, R);
    return add(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R), m - max(l, L) + 1);
}
void upd(int i, int l, int r, int L, int R, ll x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = add(tree[2 * i + 1], tree[2 * i + 2], m - l + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 0, 6) rep(j, 0, 6) {
        if(j == 0) choose[i][j] = 1;
        else if(i == 0) choose[i][j] = 0;
        else choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
    rep(i, 1, N) {
        ll p = 1;
        rep(k, 0, 6) {
            precomp[i][k] = (p + precomp[i - 1][k]) % M;
            p = (p * i) % M;
        }
    }
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    build(0, 1, n);
    while(m--) {
        char ty;
        int l, r;
        cin >> ty >> l >> r;
        if(ty == '=') {
            ll x;
            cin >> x;
            upd(0, 1, n, l, r, x);
        }else {
            int k;
            cin >> k;
            cout << query(0, 1, n, l, r)[k] << '\n';
        }
    }
}