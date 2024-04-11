
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// priority queue of nodes
// keep nodes in linked list so we can update upon removal

struct node {
    int val, occ, pos;
    node *p, *n;
    node(int val, int occ, int pos): val(val), occ(occ), pos(pos), p(NULL), n(NULL) {}
};

struct nodecmp {
    bool operator()(const node *a, const node *b) {
        if(a->occ != b->occ) return a->occ > b->occ;
        else return a->pos < b->pos;
    }
};

set<node*, nodecmp> Q;
const int N = 2e5 + 5;
int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int idx = 0;
    vector<node*> ve;
    while(idx < n) {
        int j = idx;
        while(j < n && a[j] == a[idx]) j++;
        ve.push_back(new node(a[idx], j - idx, idx));
        idx = j;
    }
    int k = sz(ve);
    rep(i, 0, k - 1) {
        ve[i]->n = ve[i + 1];
        ve[i + 1]->p = ve[i];
    }
    rep(i, 0, k) {
        Q.insert(ve[i]);
    }
    int step = 0;
    while(!Q.empty()) {
        step++;
        node *x = *Q.begin();
        Q.erase(Q.begin());
        if(x->p != NULL) x->p->n = x->n;
        if(x->n != NULL) x->n->p = x->p;
        if(x->p != NULL && x->n != NULL && x->p->val == x->n->val) {
            // combine into one block
            Q.erase(x->p);
            Q.erase(x->n);
            x->p->occ += x->n->occ;
            x->p->n = x->n->n;
            if(x->n->n != NULL) x->n->n->p = x->p;
            Q.insert(x->p);
        }
    }
    cout << step << '\n';
}