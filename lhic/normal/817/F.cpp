#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const ll MX = 1e18 + 1e9;

struct node {
    node *l, *r;
    ll x;
    int d;
    node () {
        l = r = 0;
        x = d = 0;
    }
};

void push(node *v, ll tl, ll tr) {
    if (!v)
        return;
    ll m = (tl + tr) >> 1;
    if (!v->l) {
        v->l = new node();
        v->l->x = m - tl;
    }
    if (!v->r) {
        v->r = new node();
        v->r->x = tr - m;
    }
    if (v->d == 0)
        return;
    if (v->d == 1) {
        v->l->d = 1;
        v->l->x = 0;
        v->r->d = 1;
        v->r->x = 0;
    }
    else if (v->d == 2) {
        v->l->d = 2;
        v->l->x = m - tl;
        v->r->d = 2;
        v->r->x = tr - m;
    }
    else {
        v->l->d = 3 - v->l->d;
        v->l->x = (m - tl) - v->l->x;
        v->r->d = 3 - v->r->d;
        v->r->x = (tr - m) - v->r->x;
    }
    v->d = 0;
}

void add(node *v, ll tl, ll tr, ll l, ll r, int t) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        if (t == 1)
            v->d = 1, v->x = 0;
        else if (t == 2)
            v->d = 2, v->x = tr - tl;
        else {
            v->d = 3 - v->d;
            v->x = (tr - tl) - v->x;
        }
        return;
    }
    push(v, tl, tr);
    ll m = (tl + tr) >> 1;
    add(v->l, tl, m, l, r, t);
    add(v->r, m, tr, l, r, t);
    v->x = v->l->x + v->r->x;
    if (v->l->x == m - tl)
        delete v->l, v->l = 0;
    if (v->r->x == tr - m)
        delete v->r, v->r = 0;
}

ll get(node *v, ll tl, ll tr) {
    if (tl + 1 == tr) {
        return tl;
    }
    ll m = (tl + tr) >> 1;
    push(v, tl, tr);
    if (v->l->x)
        return get(v->l, tl, m);
    else
        return get(v->r, m, tr);
}
vector<ll> vv;
ll ql[120000];
ll qr[120000];
int qt[120000];

int main() {
    int n;
    scanf("%d", &n);
    vv.push_back(1);
    for (int i = 0; i < n; ++i) {
        scanf("%d%lld%lld", qt + i, ql + i, qr + i);
        ++qr[i];
        vv.push_back(ql[i]);
        vv.push_back(qr[i]);
    }
    sort(vv.begin(), vv.end());
    vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
    node *root = new node();
    root->x = MX - 1;
    for (int i = 0; i < n; ++i) {
        int t;
        ll l, r;
        t = qt[i];
        l = ql[i];
        r = qr[i];
        l = lower_bound(vv.begin(), vv.end(), l) - vv.begin();
        r = lower_bound(vv.begin(), vv.end(), r) - vv.begin();
        add(root, 0, vv.size(), l, r, t);
        printf("%lld\n", vv[get(root, 0, vv.size())]);
    }
    return 0;
}