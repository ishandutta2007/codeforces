
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

int n, k, a, b, q;

struct node {
    ll val;
    node *left = NULL;
    node *right = NULL;
    node(ll val): val(val) {}
    void split() {
        left = new node(0LL);
        right = new node(0LL);
    }
};

struct segtree {
    ll minwith;
    node *root;
    segtree(ll m) : minwith(m) {
        root = new node(0LL);
    }
    void build(node *i, int l, int r) {
        if(l == r) return;
        i->split();
        int m = (l + r) / 2;
        build(i->left, l, m);
        build(i->right, m + 1, r);
    }
    void upd(node *i, int l, int r, int k, ll x) {
        if(l == r) {
            i->val = min(minwith, i->val + x);
            return;
        }
        int m = (l + r) / 2;
        if(k <= m) upd(i->left, l, m, k, x);
        else upd(i->right, m + 1, r, k, x);
        i->val = i->left->val + i->right->val;
    }
    void upd(int k, ll x) {
        upd(root, 1, n, k, x);
    }
    ll getsum(node *i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0LL;
        if(L <= l && r <= R) return i->val;
        int m = (l + r) / 2;
        return getsum(i->left, l, m, L, R) + getsum(i->right, m + 1, r, L, R);
    }
    ll getsum(int L, int R) {
        return getsum(root, 1, n, L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> a >> b >> q;
    segtree sa(a), sb(b);
    sa.build(sa.root, 1, n);
    sb.build(sb.root, 1, n);
    while(q--) {
        int ty, d, p;
        ll amt;
        cin >> ty;
        if(ty == 1) {
            cin >> d >> amt;
            sa.upd(d, amt);
            sb.upd(d, amt);
        }else {
            cin >> p;
            cout << sa.getsum(p + k, n) + sb.getsum(1, p - 1) << '\n';
        }
    }
}