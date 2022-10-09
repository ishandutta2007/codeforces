
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

const int N = 1e5 + 5;
int n;
ll a[N], tree[4 * N], lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i] += lazy[i];
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
ll query(int i, int l, int r, int idx) {
    prop(i, l, r);
    if(l == r) return tree[i];
    int m = (l + r) / 2;
    if(idx <= m) return query(2 * i + 1, l, m, idx);
    else return query(2 * i + 2, m + 1, r, idx);
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

ll val = 0;
ll dostuff(int l, int r) {
    ll ans = 0;
    if(l > 1) {
        ans += max(0LL, query(0, 1, n, l - 1) - query(0, 1, n, l));
    }
    if(r < n) {
        ans += max(0LL, query(0, 1, n, r) - query(0, 1, n, r + 1));
    }
    return ans;
}

ll bruh(ll x) {
    if(x >= 0) return (x + 1) / 2;
    else return x / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 2, n + 1) {
        val += max(0LL, a[i - 1] - a[i]);
    }
    build(0, 1, n);
    cout << bruh(val + a[n]) << '\n';
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        if(l == 1) a[1] += x;
        if(n > 1 && r == n) a[n] += x;
        val -= dostuff(l, r);
        upd(0, 1, n, l, r, x);
        val += dostuff(l, r);
        cout << bruh(val + a[n]) << '\n';
    }
}