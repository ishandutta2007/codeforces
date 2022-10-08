
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
    int val;
    node *left = NULL, *right = NULL;
    node(int val = 0) : val(val) {}
    void split() {
        if(left == NULL) left = new node();
        if(right == NULL) right = new node();
    }
};

struct segtree {
    const int L = 1, R = 1e9 + 5;
    node *root;
    segtree() {
        root = new node();
    }
    void add(node *i, int l, int r, int k, int x) {
        if(l == r) {
            i->val = x;
            return;
        }
        int m = l + (r - l) / 2;
        i->split();
        if(k <= m) {
            add(i->left, l, m, k, x);
        }else {
            add(i->right, m + 1, r, k, x);
        }
        i->val = i->left->val + i->right->val;
    }
    void add(int k, int x) {
        add(root, L, R, k, x);
    }
    int getsum(node *i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return i->val;
        i->split();
        int m = l + (r - l) / 2;
        return getsum(i->left, l, m, L, R) + getsum(i->right, m + 1, r, L, R);
    }
    int getsum(int l, int r) {
        return getsum(root, L, R, l, r);
    }
};

int n;
map<int, segtree> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        int ty, t, x;
        cin >> ty >> t >> x;
        if(ty == 1) {
            // add
            ma[x].add(t, 1);
        }else if(ty == 2) {
            // remove
            ma[x].add(t, -1);
        }else {
            // query
            cout << ma[x].getsum(0, t) << '\n';
        }
    }
}