
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

struct node {
    int pref, suf, first, last, len;
    ll cnt;
    bool stupid = false;
    node() {
        stupid = true;
    }
    node(int x) {
        stupid = false;
        pref = 1;
        suf = 1;
        first = last = x;
        len = 1;
        cnt = 1;
    }
    node operator+(const node &o) const {
        if(stupid) return o;
        if(o.stupid) return *this;
        node X;
        X.stupid = false;
        X.pref = (pref == len && last <= o.first ? len + o.pref : pref);
        X.suf = (o.suf == o.len && last <= o.first ? suf + o.len : o.suf);
        X.first = first;
        X.last = o.last;
        X.len = len + o.len;
        X.cnt = cnt + o.cnt + (last <= o.first ? 1LL * suf * o.pref : 0LL);
        return X;
    }
};

const int N = 2e5 + 5;
node tree[4 * N];

void build(int i, int l, int r, vi &a) {
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
    return query(2 * i + 1, l,m,L,R)+query(2*i+2,m+1,r,L,R);
}
void upd(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = node(x);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2*i+1,l,m,k,x);
    else upd(2*i+2,m+1,r,k,x);
    tree[i]=tree[2*i+1]+tree[2*i+2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    build(0, 1, n, a);
    while(q--) {
        int ty, l, r, x, y;
        cin >> ty;
        if(ty == 1) {
            cin >> x >> y;
            upd(0, 1, n, x, y);
        }else {
            cin >> l >> r;
            node ans = query(0, 1, n, l, r);
            cout << ans.cnt << '\n';
        }
    }
}