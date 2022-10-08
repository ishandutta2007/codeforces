
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
struct node {
    ll mn, mx;
    node() {
        mn = LLONG_MAX;
        mx = LLONG_MIN;
    }
    node(ll a) {
        mn = mx = a;
    }
    node(ll a, ll b) {
        mn = a;
        mx = b;
    }
    node operator+(const node &o) const {
        return node(min(o.mn, mn), max(o.mx, mx));
    }
};
node tree[4 * N];

void build(int i, int l, int r, const vector<ll> &a) {
    if(l == r) {
        tree[i] = node(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, a);
    build(2 * i + 2, m + 1, r, a);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 1, n + 1) {
        ll b;
        cin >> b;
        a[i] = b - a[i];
    }
    rep(i, 1, n + 1) {
        a[i] += a[i - 1];
    }
    build(0, 0, n, a);
    while(q--) {
        int l, r;
        cin >> l >> r;
        node x = query(0, 0, n, l, r);
        if(a[l - 1] == a[r] && x.mn >= a[l - 1]) {
            cout << x.mx - a[l - 1] << '\n';
        }else {
            cout << -1 << '\n';
        }
    }
}