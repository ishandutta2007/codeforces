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

mt19937 rnd(123);

const int MAXN = 120000;
const int LOG = 20;
int was[MAXN];
int up[LOG][MAXN];
struct node {
    node *l, *r, *p;
    int sz;
    int x;
    int y;
    node(int X) {
        l = r = p = 0;
        sz = 1;
        x = X;
        y = rnd();
    }
};

int sz(node *v) {
    return v ? v->sz : 0;
}

void upd(node *v) {
    if (!v)
        return;
    v->sz = 1;
    if (v->l)
        v->sz += v->l->sz, v->l->p = v;
    if (v->r)
        v->sz += v->r->sz, v->r->p = v;
}

node *merge(node *l, node *r) {
    if (!l)
        return r;
    if (!r)
        return l;
    if (l->y >= r->y) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void split(node *v, int k, node *&l, node *&r) {
    if (!v) {
        l = r = 0;
        return;
    }
    if (sz(v->l) >= k) {
        split(v->l, k, l, v->l);
        upd(v);
        r = v;
    }
    else {
        split(v->r, k - sz(v->l) - 1, v->r, r);
        upd(v);
        l = v;
    }
}


node *nd[MAXN];

int get(int x) {
    node *v = nd[x];
    node *pr = v->r;
    int ans = 0;
    while (v) {
        if (pr == v->r) {
            ans += sz(v->l) + 1;
        }
        pr = v;
        v = v->p;
    }
    return ans - 1;
}

vector<int> vv;
vector<int> eds[MAXN];

void dfs1(int v) {
    was[v] = 1;
    for (int u: eds[v]) {
        if (!was[u])
            dfs1(u);
    }
    vv.push_back(v);
}

int n;

int h[MAXN];
int glv;

int gett(node *v) {
    if (!v)
        return 0;
    if (get(v->x) >= get(glv))
        return gett(v->l);
    if (h[v->x] > h[glv]) {
        int a = v->x;
        for (int i = LOG - 1; i >= 0; --i) {
            if (h[a] - h[glv] >= (1 << i))
                a = up[i][a];
        }
        if (a == glv)
            return gett(v->l);
    }
    return sz(v->l) + 1 + gett(v->r);
}

set<int> ss[MAXN];
int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        eds[a].push_back(b);
    }
    for (int i = 0; i < n; ++i)
        if (!was[i])
            dfs1(i);
    node *root = new node(n);
    nd[n] = root;
    for (int i = 0; i < LOG; ++i)
        up[i][n] = n;
    for (int i = 0; i < n; ++i)
        eds[i].push_back(n);
    for (int i: vv) {
        int cur = eds[i][0];
        for (int j: eds[i]) {
            if (get(cur) > get(j))
                cur = j;
        }
        if (cur > i && cur != n) {
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][cur] > i && up[j][cur] != n)
                    cur = up[j][cur];
            }
            cur = up[0][cur];
        }
        up[0][i] = cur;
        h[i] = h[cur] + 1;
        for (int j = 1; j < LOG; ++j)
            up[j][i] = up[j - 1][up[j - 1][i]];
        auto it = ss[cur].insert(i).first;
        int sz = get(cur);

        if (next(it) != ss[cur].end()) {
            glv = *next(it);
            sz = gett(root);
        }

        node *l, *r;
        split(root, sz, l, r);
        if (l)
            l->p = 0;
        if (r)
            r->p = 0;
        nd[i] = new node(i);
        root = merge(l, merge(nd[i], r));
        if (root)
            root->p = 0;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", get(i) + 1);
    printf("\n");
    return 0;
}