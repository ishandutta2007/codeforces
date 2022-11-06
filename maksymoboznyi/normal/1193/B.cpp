#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5 + 5;

int n, m, k, d[N], w[N], sz[N];
vector<int> g[N];
mt19937 gen;

struct node {
    int key, add, prior, val, mx;
    node *l, *r;
    node (int _key, int _val) {
        key = _key;
        add = 0;
        val = mx = _val;
        l = r = 0;
        prior = gen();
    }
};

typedef node *tnode;

void push(tnode t) {
    if (t -> l)
        t -> l -> mx += t -> add, t -> l -> add += t -> add, t -> l -> val += t -> add;
    if (t -> r)
        t -> r -> mx += t -> add, t -> r -> add += t -> add, t -> r -> val += t -> add;
    t -> add = 0;
}

int mx(tnode t) {
    return t ? t -> mx : 0;
}

void recalc(tnode t) {
    if (t) {
        push(t);
        t -> mx = max({t -> val, mx(t -> l), mx(t -> r)});
    }
}

void merge(tnode &t, tnode l, tnode r) {
    if (!l)
        return void(t = r);
    if (!r)
        return void(t = l);
    push(l);
    push(r);
    if (l -> prior > r -> prior)
        merge(l -> r, l -> r, r), t = l;
    else
        merge(r -> l, l, r -> l), t = r;
    recalc(t);
}

void split(tnode t, tnode &l, tnode &r, int key) {
    if (!t)
        return void(l = r = 0);
    push(t);
    if (t -> key <= key)
        split(t -> r, t -> r, r, key), l = t;
    else
        split(t -> l, l, t -> l, key), r = t;
    recalc(t);
}

vector<pair<int, int> > c;

void go(tnode t) {
    push(t);
    if (t -> l)
        go(t -> l);
    c.pb({t -> key, t -> val});
    if (t -> r)
        go(t -> r);
}

tnode t[N];

bool cmp(int a, int b) {
    return sz[a] > sz[b];
}

void dfs_sz(int v) {
    sz[v] = 1;
    for (auto u: g[v])
        dfs_sz(u), sz[v] += sz[u];
}

int get_l(tnode t) {
    push(t);
    if (t -> l)
        return  get_l(t -> l);
    return t -> val;
}

void del(tnode &t) {
    if (t -> l) {
        push(t);
        del(t -> l);
        recalc(t);
        return;
    }
    push(t);
    t = t -> r;
    recalc(t);
}

void dfs(int v) {
    if (g[v].size() == 0) {
        t[v] = new node(d[v], w[v]);
        return;
    }
    for (auto u: g[v])
        dfs(u);
    t[v] = t[g[v][0]];

    for (int j = 1; j < g[v].size(); j++) {
        c.clear();
        go(t[g[v][j]]);
        c.pb({1e9, -1});

        for (int i = 0; i + 1 < c.size(); i++) {
            tnode t1, t2, t3;
            split(t[v], t1, t2, c[i].first - 1);
            split(t2, t2, t3, c[i].first);
            if (!t2)
                t2 = new node(c[i].first, mx(t1));
            merge(t2, t2, t3);
            merge(t[v], t1, t2);
        }
    }

    for (int j = 1; j < g[v].size(); j++) {
        c.clear();
        go(t[g[v][j]]);
        c.pb({1e9, -1});
        int x = 0;
        for (int i = 0; i + 1 < c.size(); i++) {
            x = max(x, c[i].second);
            tnode t1, t2, t3;
            split(t[v], t1, t2, c[i].first - 1);
            split(t2, t2, t3, c[i + 1].first - 1);
            t2 -> add += x;
            t2 -> mx += x;
            t2 -> val += x;
            merge(t2, t2, t3);
            merge(t[v], t1, t2);
        }
    }

    if (d[v]) {
        tnode t1, t2, t3;
        split(t[v], t1, t2, d[v] - 1);
        split(t2, t2, t3, d[v]);
        if (!t2)
            t2 = new node(d[v], w[v] + mx(t1));
        else
            t2 -> mx += w[v], t2 -> val += w[v];

        while (t3 != 0 && get_l(t3) < t2 -> val)
            del(t3);

        merge(t2, t2, t3);
        merge(t[v], t1, t2);
    }


}

signed main()
{
    gen.seed(time(0));
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].pb(i);
    }
    for (int i = 1; i <= m; i++) {
        int v;
        cin >> v;
        cin >> d[v] >> w[v];
    }
    dfs_sz(1);
    for (int i = 1; i <= n; i++)
        sort(all(g[i]), cmp);
    dfs(1);
    c.clear();
    go(t[1]);
    int ans = 0;
    for (int i = 0; i < c.size(); i++)
        ans = max(ans, c[i].second);
    cout << ans;
    return 0;
}