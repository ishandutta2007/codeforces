
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
    ll mx, sum, sumsum;
    int len = 0;
    node(ll mx = -1e9, ll sum = 0, ll sumsum = 0, int len = 0) : mx(mx), sum(sum), sumsum(sumsum), len(len) {}
    node operator+(const node &o) const {
        return node(max(mx, o.mx), sum + o.sum, sumsum + o.sumsum + sum * o.len, len + o.len);
    }
};

const int N = 1e5 + 5;
node tree[4 * N];
ll lazy[4 * N];

node get(int i) {
    return node(tree[i].mx + lazy[i],
        tree[i].sum + lazy[i] * tree[i].len,
        tree[i].sumsum + lazy[i] * (1LL * tree[i].len * (tree[i].len + 1) / 2),
        tree[i].len);
}
void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i] = get(i);
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
void build(int i, int l, int r, const vector<ll> &db) {
    if(l == r) {
        tree[i] = node(db[l], db[l], db[l], 1);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, db);
    build(2 * i + 2, m + 1, r, db);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void upd(int i, int l, int r, int L, int R, ll d) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += d;
        return;
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    upd(2 * i + 1, l, m, L, R, d);
    upd(2 * i + 2, m + 1, r, L, R, d);
    tree[i] = get(2 * i + 1) + get(2 * i + 2);
}
ll lower(int i, int l, int r, ll d) {
    if(l == r) {
        return l + (get(i).mx <= d);
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    if(get(2 * i + 1).mx <= d) return lower(2 * i + 2, m + 1, r, d);
    else return lower(2 * i + 1, l, m, d);
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    if(L <= l && r <= R) return get(i);
    int m = (l + r) / 2;
    prop(i, l, r);
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m), da(n), db(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    adjacent_difference(all(b), db.begin());
    build(0, 1, m - 1, db);

    vi p(n + 1);
    p[n] = m;
    while(q--) {
        int ty, k, d;
        cin >> ty >> k >> d;
        if(ty == 1) {
            rep(i, 0, k) {
                a[n - k + i] += d * (i + 1);
            }
        }else {
            if(k == m) {
                k--;
                db[0] += d;
            }
            upd(0, 1, m - 1, m - k, m - 1, d);
        }
        ll ans = 0;
        rep(i, 1, n) {
            p[i] = lower(0, 1, m - 1, a[i] - a[i - 1]);
        }
        ans += a[0] * p[1];
        ans += db[0] * (n + m - 1) + query(0, 1, m - 1, 1, m - 1).sumsum;
        rep(i, 2, n + 1) {
            ans += a[i - 1] * (p[i] - p[i - 1] + 1);
            ans += query(0, 1, m - 1, 1, p[i - 1] - 1).sum;
        }
        cout << ans << '\n';
    }
}