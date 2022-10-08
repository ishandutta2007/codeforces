
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

const int N = (1 << 18) + 5;
int n, q;
ll a[N];
bool revall[N], swaall[N];

struct node {
    ll sum;
    bool rev;
    bool swa;
    node *left, *right;
    node(ll sum) : sum(sum) {
        rev = swa = false;
        left = right = NULL;
    }
};

struct segtree {
    node *root = NULL;
    segtree() {
        root = new node(0);
    }
    void build(node *i, int l, int r) {
        if(l == r) {
            i->sum = a[l];
            return;
        }
        int m = (l + r) / 2;
        i->left = new node(0);
        i->right = new node(0);
        build(i->left, l, m);
        build(i->right, m + 1, r);
        i->sum = i->left->sum + i->right->sum;
    }
    void prop(node *i, int l, int r) {
        int len = r - l + 1;
        if(i->swa ^ swaall[len]) {
            i->swa ^= true;
            swap(i->left, i->right);
        }
        if(i->rev ^ revall[len]) {
            i->rev ^= true;
            swap(i->left, i->right);
            if(l < r) {
                i->left->rev ^= true;
                i->right->rev ^= true;
            }
        }
    }
    ll query(node *i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return i->sum;
        prop(i, l, r);
        int m = (l + r) / 2;
        return query(i->left, l, m, L, R) + query(i->right, m + 1, r, L, R);
    }
    void upd(node *i, int l, int r, int k, ll x) {
        if(l == r) {
            i->sum = x;
            return;
        }
        prop(i, l, r);
        int m = (l + r) / 2;
        if(k <= m) {
            upd(i->left, l, m, k, x);
        }else {
            upd(i->right, m + 1, r, k, x);
        }
        i->sum = i->left->sum + i->right->sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    n = (1 << n);
    segtree tree;
    rep(i, 0, n) {
        cin >> a[i];
    }
    tree.build(tree.root, 0, n - 1);
    while(q--) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            // replace(x, k)
            int x; 
            ll k;
            cin >> x >> k;
            x--;
            // cerr << "replace " << x << ' ' << k << '\n';
            tree.upd(tree.root, 0, n - 1, x, k);
        }else if(ty == 2) {
            // reverse(k)
            int k;
            cin >> k;
            // cerr << "reverse " << k << '\n';
            int len = (1 << k);
            revall[len] ^= true;
        }else if(ty == 3) {
            // swap(k)
            int k;
            cin >> k;
            // cerr << "swap " << k << '\n';
            int len = (1 << (k + 1));
            swaall[len] ^= true;
        }else {
            // sum(l, r)
            int l, r;
            cin >> l >> r;
            l--; r--;
            // cerr << "query " << l << ' ' << r << '\n';
            cout << tree.query(tree.root, 0, n - 1, l, r) << '\n';
        }
    }
}