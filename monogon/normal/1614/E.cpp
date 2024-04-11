
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
    ll val, lz;
    node *le, *ri;
    node() {
        val = lz = 0;
        le = ri = NULL;
    }
    node* left() {
        return le ? le : le = new node();
    }
    node* right() {
        return ri ? ri : ri = new node();
    }
};

ll get(node *i) {
    return i->val + i->lz;
}
void prop(node *i, int l, int r) {
    i->val = get(i);
    if(l < r) {
        i->left()->lz += i->lz;
        i->right()->lz += i->lz;
    }
    i->lz = 0;
}

ll query(node *i, int l, int r, int k) {
    if(l == r) {
        return get(i);
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    if(k <= m) return query(i->left(), l, m, k);
    else return query(i->right(), m + 1, r, k);
}
void upd(node *i, int l, int r, int L, int R, ll x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        i->lz += x;
        return;
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    upd(i->left(), l, m, L, R, x);
    upd(i->right(), m + 1, r, L, R, x);
    i->val = get(i->right());
}
int lower(node *i, int l, int r, ll x) {
    if(l == r) return l + (l + get(i) < x);
    int m = (l + r) / 2;
    prop(i, l, r);
    if(m + get(i->left()) >= x) return lower(i->left(), l, m, x);
    else return lower(i->right(), m + 1, r, x);
}
void printtree(node *i, int l, int r, int L, int R) {
    if(r < L || R < l) return;
    if(l == r) {
        cout << get(i) << ' ';
        return;
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    printtree(i->left(), l, m, L, R);
    printtree(i->right(), m + 1, r, L, R);
}

const int M = 1e9 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll last = 0;
    node* root = new node;
    while(n--) {
        ll T;
        int k;
        cin >> T >> k;
        int L = lower(root, 0, 1e9, T);
        int R = lower(root, 0, 1e9, T + 1);
        if(L - 1 >= 0) upd(root, 0, 1e9, 0, L - 1, 1);
        if(R <= 1e9) upd(root, 0, 1e9, R, 1e9, -1);
        rep(i, 0, k) {
            ll x; cin >> x;
            x = (x + last) % M;
            last = x + query(root, 0, 1e9, x);
            cout << last << '\n';
        }
    }
}