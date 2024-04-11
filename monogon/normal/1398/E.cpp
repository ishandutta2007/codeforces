
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

// we can double whichever spells we want, except one lightning spell must come first
// excluding minimum lightning spell, choose maximum k of the other spells, if k = number of lightnings
// maintain number of lightning spells, set of all other cells
// in set, we need to query sum of max k
// segment tree

struct node {
    int cnt = 0;
    ll sum = 0;
    node *l = NULL, *r = NULL;
    node(int cnt = 0, ll sum = 0) : cnt(cnt), sum(sum) {}
    void split() {
        l = new node();
        r = new node();
    }
};

struct segtree {
    node *root = NULL;
    int L = 0, R = 1e9 + 5;
    segtree() {
        root = new node();
    }
    void upd(node *i, int l, int r, int k, ll val, int c) {
        if(l == r) {
            i->sum += val * c;
            i->cnt += c;
            return;
        }
        int m = (l + r) / 2;
        if(i->l == NULL) i->split();
        if(k <= m) upd(i->l, l, m, k, val, c);
        else upd(i->r, m + 1, r, k, val, c);
        i->cnt = i->l->cnt + i->r->cnt;
        i->sum = i->l->sum + i->r->sum;
    }
    void upd(int k, ll val, int c) {
        upd(root, L, R, k, val, c);
    }
    ll query(node *i, int l, int r, int k) {
        if(k <= 0) return 0;
        if(l == r) return i->sum;
        int m = (l + r) / 2;
        if(i->l == NULL) i->split();
        if(k <= i->r->cnt) return query(i->r, m + 1, r, k);
        else return i->r->sum + query(i->l, l, m, k - i->r->cnt);
    }
    ll query(int k) {
        return query(root, L, R, k);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<ll> lightning;
    segtree tree;
    ll sum = 0;
    while(n--) {
        int ty;
        ll d;
        cin >> ty >> d;
        sum += d;
        if(ty == 0) {
            if(d > 0) {
                // learn fire
                tree.upd(d, d, 1);
            }else {
                // forget fire
                d = -d;
                tree.upd(d, d, -1);
            }
        }else {
            if(d > 0) {
                // learn lightning
                if(lightning.empty() || d < *lightning.begin()) {
                    if(!lightning.empty()) tree.upd(*lightning.begin(), *lightning.begin(), 1);
                }else {
                    tree.upd(d, d, 1);
                }
                lightning.insert(d);
            }else {
                // forget lightning
                d = -d;
                lightning.erase(lightning.find(d));
                // if it was min
                if(lightning.empty() || d < *lightning.begin()) {
                    if(!lightning.empty()) tree.upd(*lightning.begin(), *lightning.begin(), -1);
                }else {
                    tree.upd(d, d, -1);
                }
            }
        }
        cout << sum + tree.query(sz(lightning)) << '\n';
    }
}