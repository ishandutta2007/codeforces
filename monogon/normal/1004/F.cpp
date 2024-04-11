
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

int x;

struct node {
    int n;
    ll ans;
    node *left = NULL, *right = NULL;
    // (pos, bitwise or)
    vector<pii> pre, suf;
    int pre0, suf0;
    node() {
        n = 0;
        ans = 0;
        pre0 = suf0 = 0;
    }
    node(int y) {
        n = 1;
        ans = (y >= x ? 1 : 0);
        if(y > 0) pre.push_back({0, y});
        if(y > 0) suf.push_back({0, y});
        pre0 = (y == 0);
        suf0 = (y == 0);
    }
    node operator+(const node &o) const {
        node N;
        N.n = n + o.n;
        N.ans = ans + o.ans;
        int j = 0;
        int prv = n;
        for(int i = sz(suf) - 1; i >= 0; i--) {
            while(j < sz(o.pre) && (suf[i].second | o.pre[j].second) < x) j++;
            if(j < sz(o.pre)) N.ans += 1LL * (prv - suf[i].first) * (o.n - o.pre[j].first);
            prv = suf[i].first;
        }
        if(x == 0) {
            N.ans += 1LL * suf0 * (o.n - o.pre0) + 1LL * n * o.pre0;
        }else {
            int j = 0;
            while(j < sz(o.pre) && o.pre[j].second < x) j++;
            if(j < sz(o.pre)) N.ans += 1LL * suf0 * (o.n - o.pre[j].first);
            j = 0;
            while(j < sz(suf) && suf[j].second < x) j++;
            if(j < sz(suf)) N.ans += 1LL * o.pre0 * (n - suf[j].first);
        }

        N.pre = pre;
        int mask = (N.pre.empty() ? 0 : N.pre.back().second);
        for(auto &pa : o.pre) {
            if((pa.second | mask) != mask) {
                mask |= pa.second;
                N.pre.push_back({pa.first + n, mask});
            }
        }
        N.suf = o.suf;
        mask = (N.suf.empty() ? 0 : N.suf.back().second);
        for(auto &pa : suf) {
            if((pa.second | mask) != mask) {
                mask |= pa.second;
                N.suf.push_back({pa.first + o.n, mask});
            }
        }
        N.pre0 = (pre0 == n ? n + o.pre0 : pre0);
        N.suf0 = (o.suf0 == o.n ? o.n + suf0 : o.suf0);
        return N;
    }
};

const int N = 1e5 + 5;
node tree[4 * N];

void build(int i, int l, int r, const vi &v) {
    if(l == r) {
        tree[i] = node(v[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, v);
    build(2 * i + 2, m + 1, r, v);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

void upd(int i, int l, int r, int k, int y) {
    if(l == r) {
        tree[i] = node(y);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, y);
    else upd(2 * i + 2, m + 1, r, k, y);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> x;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    build(0, 1, n, a);
    while(m--) {
        int ty, i, y, l, r;
        cin >> ty;
        if(ty == 1) {
            cin >> i >> y;
            upd(0, 1, n, i, y);
        }else {
            cin >> l >> r;
            cout << query(0, 1, n, l, r).ans << '\n';
        }
    }
}