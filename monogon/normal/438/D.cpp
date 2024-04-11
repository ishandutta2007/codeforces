
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
    ll sum;
    int mx;
    node() {
        sum = 0;
        mx = -1;
    }
    node(int a) {
        sum = mx = a;
    }
    node(ll sum, int mx) : sum(sum), mx(mx) {}
    node operator+(const node &o) const {
        return node(sum + o.sum, max(mx, o.mx));
    }
};

const int N = 1e5 + 5;
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
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, int x) {
    if(r < L || R < l || tree[i].mx < x) return;
    if(l == r) {
        tree[i] = node(tree[i].sum % x);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void upd2(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = node(x);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd2(2 * i + 1, l, m, k, x);
    else upd2(2 * i + 2, m + 1, r, k, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    build(0, 1, n, a);
    while(m--) {
        int ty, l, r, k, x;
        cin >> ty;
        if(ty == 1) {
            cin >> l >> r;
            cout << query(0, 1, n, l, r).sum << '\n';
        }else if(ty == 2) {
            cin >> l >> r >> x;
            upd(0, 1, n, l, r, x);
        }else if(ty == 3) {
            cin >> k >> x;
            upd2(0, 1, n, k, x);
        }
    }
}