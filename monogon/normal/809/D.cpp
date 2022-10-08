
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

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

struct node {
    int val, lazy, y;
    node *left = NULL, *right = NULL;
    node(int val) : val(val), lazy(0), y(rand(1, 1e9)) {}
};

int get(node *x) {
    return !x ? INT_MIN : x->val + x->lazy;
}
void prop(node *x) {
    if(!x) return;
    if(x->left) x->left->lazy += x->lazy;
    if(x->right) x->right->lazy += x->lazy;
    x->val += x->lazy;
    x->lazy = 0;
}

int getmin(node *x) {
    if(!x) return INT_MAX;
    prop(x);
    if(x->left) return getmin(x->left);
    return x->val;
}

node* join(node *l, node *r) {
    if(!l) return r;
    if(!r) return l;
    if(l->y < r->y) {
        prop(l);
        l->right = join(l->right, r);
        return l;
    }else {
        prop(r);
        r->left = join(l, r->left);
        return r;
    }
}

pair<node*, node*> split(node *x, int k) {
    if(!x) return {NULL, NULL};
    prop(x);
    if(x->val <= k) {
        auto pa = split(x->right, k);
        x->right = pa.first;
        return {x, pa.second};
    }else {
        auto pa = split(x->left, k);
        x->left = pa.second;
        return {pa.first, x};
    }
}

int getsize(node *x) {
    if(!x) return 0;
    return 1 + getsize(x->left) + getsize(x->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    node *root = NULL;
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        auto pr = split(root, r - 1);
        auto pl = split(pr.first, l - 1);
        node *L = pl.first, *M = pl.second, *R = pr.second;
        node *x = new node(l);
        if(M) M->lazy++;
        M = join(x, M);
        if(R) {
            R = split(R, getmin(R)).second;
        }
        root = join(L, join(M, R));
    }
    cout << getsize(root) << '\n';
}