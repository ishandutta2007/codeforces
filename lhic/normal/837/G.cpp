#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

struct node {
    node *l, *r;
    ll a, b;
    node() {
        l = r = 0;
        a = b = 0;
    }
};

node *build(int tl, int tr) {
    node *v = new node();
    if (tl + 1 == tr)
        return v;
    int m = (tl + tr) >> 1;
    v->l = build(tl, m);
    v->r = build(m, tr);
    return v;
}

node *add(node *v, int tl, int tr, int l, int r, ll a, ll b) {
    if (r <= tl || tr <= l)
        return v;
    node *u = new node();
    *u = *v;
    if (l <= tl && tr <= r) {
        u->a += a;
        u->b += b;
        return u;
    }
    int m = (tl + tr) >> 1;
    u->l = add(u->l, tl, m, l, r, a, b);
    u->r = add(u->r, m, tr, l, r, a, b);
    return u;
}

ll get(node *v, int tl, int tr, ll x) {
    ll ans = v->a + v->b * x;
    if (tl + 1 == tr)
        return ans;
    int m = (tl + tr) >> 1;
    if (x < m)
        return get(v->l, tl, m, x) + ans;
    else
        return get(v->r, m, tr, x) + ans;
}

int n;
const int MX = 210000;
const ll MOD = 1e9;
node *cur[MX];

int main() {
    scanf("%d", &n);
    node *root = build(0, MX);
    cur[0] = root;
    for (int i = 0; i < n; ++i) {
        int x1, x2;
        ll a, b, y1, y2;
        scanf("%d%d%lld%lld%lld%lld", &x1, &x2, &y1, &a, &b, &y2);
        root = add(root, 0, MX, 0, x1 + 1, y1, 0);
        root = add(root, 0, MX, x1 + 1, x2 + 1, b, a);
        root = add(root, 0, MX, x2 + 1, MX, y2, 0);
        cur[i + 1] = root;
    }
    int q;
    scanf("%d", &q);
    ll lst = 0;
    while (q--) {
        int l, r;
        ll x;
        scanf("%d%d%lld", &l, &r, &x);
        x = (x + lst) % MOD;
        --l;
        if (x >= MX)
            x = MX - 1;
        lst = get(cur[r], 0, MX, x) - get(cur[l], 0, MX, x);
        printf("%lld\n", lst);
    }
    return 0;
}