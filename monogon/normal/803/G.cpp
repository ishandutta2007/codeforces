
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
    int mn, lazy = -1;
    node *left = NULL, *right = NULL;
    node(int x = INT_MAX): mn(x) {}
};

const int N = 1e5 + 5;
int n, k, b[N], glob_min = INT_MAX;

node* build(int l, int r) {
    if(l / n == r / n) return new node(glob_min);
    int m = n * (1 + (l / n + r / n) / 2);
    node *x = new node();
    x->left = build(l, m - 1);
    x->right = build(m, r);
    x->mn = min(x->left->mn, x->right->mn);
    return x;
}

map<pii, int> ma;

int getmin(int l, int r) {
    if(l == r) return b[l];
    if(ma.find(make_pair(l, r)) != ma.end()) return ma[{l, r}];
    int m = (l + r) / 2;
    return ma[{l, r}] = min(getmin(l, m), getmin(m + 1, r));
}
node *makenode(int l, int r) {
    return new node(getmin(l, r));
}

void prop(node *x, int l, int r) {
    x->mn = x->lazy;
    int m = (l + r) / 2;
    if(l < r) {
        if(x->left == NULL) x->left = makenode(l % n, m % n);
        x->left->lazy = x->lazy;
        if(x->right == NULL) x->right = makenode((m + 1) % n, r % n);
        x->right->lazy = x->lazy;
    }
    x->lazy = -1;
}
int query(node *x, int l, int r, int L, int R) {
    if(r < L || R < l) return INT_MAX;
    if(x->lazy != -1) prop(x, l, r);
    if(L <= l && r <= R) return x->mn;
    int m = (l + r) / 2;
    if(l / n != r / n) m = n * (1 + (l / n + r / n) / 2) - 1;
    if(x->left == NULL) x->left = makenode(l % n, m % n);
    if(x->right == NULL) x->right = makenode((m + 1) % n, r % n);
    return min(query(x->left, l, m, L, R), query(x->right, m + 1, r, L, R));
}
void upd(node *x, int l, int r, int L, int R, int val) {
    if(x->lazy != -1) prop(x, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        x->lazy = val;
        prop(x, l, r);
        return;
    }
    int m = (l + r) / 2;
    if(l / n != r / n) m = n * (1 + (l / n + r / n) / 2) - 1;
    if(x->left == NULL) x->left = makenode(l % n, m % n);
    if(x->right == NULL) x->right = makenode((m + 1) % n, r % n);
    upd(x->left, l, m, L, R, val);
    upd(x->right, m + 1, r, L, R, val);
    x->mn = min(x->left->mn, x->right->mn);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> b[i];
    }
    glob_min = *min_element(b, b + n);
    node *root = build(0, k * n - 1);
    int q;
    cin >> q;
    while(q--) {
        int ty, l, r;
        cin >> ty >> l >> r;
        l--; r--;
        if(ty == 1) {
            int x;
            cin >> x;
            upd(root, 0, k * n - 1, l, r, x);
        }else {
            cout << query(root, 0, k * n - 1, l, r) << '\n';
        }
    }
}