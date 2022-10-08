
// #pragma GCC target ("avx2")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimization ("unroll-loops")
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

const int N = 2e5 + 5;
int n, q;
ll a[N], tree[4 * N], lazy[4 * N], pow2[31];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = a[l];//pref[l];
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
void upd(int i, int l, int r, int L, int R, ll x) {
    if(r < L || R < l) {
        prop(i, l, r);
        return;
    }
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    prop(i, l, r);
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
int query(int i, int l, int r, int x) {
    if(l == r) return tree[i] >= x ? l : -1;
    prop(i, l, r);
    int m = (l + r) / 2;
    ll s = tree[2 * i + 1] + lazy[2 * i + 1];
    if(s >= x) return query(2 * i + 1, l, m, x);
    else return query(2 * i + 2, m + 1, r, x - s);
}
ll getsum(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return getsum(2 * i + 1, l, m, L, R) + getsum(2 * i + 2, m + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    rep(i, 1, n + 1) cin >> a[i];
    build(0, 1, n);
    pow2[1] = 1;
    rep(i, 2, 31) {
        pow2[i] = pow2[i - 1] * 2;
    }
    while(q--) {
        int p, x;
        cin >> p >> x;
        upd(0, 1, n, p, p, x - a[p]);
        a[p] = x;
        int ans = -1;
        rep(i, 0, 31) {
            int x = query(0, 1, n, pow2[i]);
            if(x == -1) break;
            if(getsum(0, 1, n, 1, x - 1) == a[x]) {
                ans = x;
                break;
            }
        }
        cout << ans << '\n';
    }
}