#include<bits/stdc++.h>
using namespace std;
/**
    so done with centroid shit
*/
/**
    Shame cube algorithm
    d(x) - 2 * d(y) + d(z)
    a-> max(dep[x])
    b->max(dep[x] - 2 * dep[y])
    c-> max(-2 * dep[y] + dep[z])
    d -> max(- 2 * dep[x]
    answer means it.
*/
using ll = long long;

struct node_t {
    ll a, b, c, d;
    ll answer;

    node_t (ll a = 0, ll b = 0, ll c = 0, ll d = 0, ll answer = 0) : a(a), b(b), c(c), d(d), answer(answer) {}

    friend node_t operator + (const node_t &l, const node_t &r) {
        node_t res;
        res.a = max(l.a, r.a);
        res.b = max({l.b, r.b, l.a + r.d});
        res.c = max({l.c, r.c, l.d + r.a});
        res.d = max({l.d, r.d});
        res.answer = max({l.answer, r.answer});
        res.answer = max(res.answer,
                        max(l.a + r.c, l.b + r.a));
        return res;
    }

    void debug () {
        fprintf(stderr, "wat %lld %lld %lld %lld %lld\n", a, b, c, d, answer);
    }
};
const int nax = 4e5 + 10;
node_t sg[nax * 4];
ll tag[nax * 4];
int tin[nax];
int tout[nax];
int timer;
int n, q;
ll mod;
vector <pair <int, ll>> a[nax];

struct edge_t {
    int u, v;
    ll w;
}e[nax];

void dfs (int node, int parent) {
    tin[node] = ++ timer;
    for (auto &[i, w] : a[node]) {
        if (i == parent) continue;
        dfs(i, node);
        ++ timer;
    }
    tout[node] = timer;
}

void add (node_t &node, ll to_add) {
    node.a += to_add;
    node.b -= to_add;
    node.c -= to_add;
    node.d -= 2 * to_add;
}

inline void push (int v) {
    if (!tag[v]) return ;
    tag[v << 1] += tag[v];
    tag[v << 1 | 1] += tag[v];
    add(sg[v << 1], tag[v]);
    add(sg[v << 1 | 1], tag[v]);
    tag[v] = 0;

}

void update (int v, int x, int y, int l, int r, ll val) {
    if (x != y) push(v);
    if (l == x && r == y) {
        add(sg[v], val);
        tag[v] += val;
        if (x != y) push(v);
    } else {
        int mid = x + y >> 1;
        if (r <= mid) update(v << 1, x, mid, l, r, val);
        else if (l > mid) update(v << 1 | 1, mid + 1, y, l, r, val);
        else {
            update(v << 1, x, mid, l, mid, val);
            update(v << 1 | 1, mid + 1, y, mid + 1, r, val);
        }
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}


int main () {

    scanf("%d %d %lld", &n, &q, &mod);

    for (int i = 1 ; i < n ; ++ i) {
        auto &[u, v, w] = e[i];
        scanf("%d %d %lld", &u, &v, &w);
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
    }

    dfs(1, 0);

    for (int i = 1 ; i < n ; ++ i) {
        auto &[u, v, w] = e[i];
        int child = (tin[u] > tin[v]) ? u : v;
        update(1, 1, 2 * n, tin[child], tout[child], w);
    }

    ll LAST = 0;

    for (; q -- ;) {
        int id;
        ll new_w;
        scanf("%d %lld", &id, &new_w);
        id = (id + LAST) % (n - 1) + 1;
        new_w = (new_w + LAST) % mod;
        auto &[u, v, w] = e[id];
        ll dif = new_w - w;
        w = new_w;
        int child = tin[u] > tin[v] ? u : v;
        update(1, 1, 2 * n, tin[child], tout[child], dif);
        printf("%lld\n", LAST = sg[1].answer);
    }




}