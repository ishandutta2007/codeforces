#include "bits/stdc++.h"
using namespace std;
const int nax = 8e5 + 10;
int n, q;
int id[nax];
int par[nax];
int sz[nax];
int a[nax];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

map <int, int> rt;

void add(int i, int h) {
    auto it = rt.find(h);
    if (it != rt.end()) {
        unite(it->second, i);
        it->second = find(it->second);
        a[it->second] = h;
    } else {
        rt[h] = i;
        a[i] = h;
    }
}


void scale(int l, int r) {
    int mid = l + r >> 1;
    auto it = rt.lower_bound(mid + 1);


    while (it != rt.end() && it->first <= r) {
        add(it->second, r + 1);
        auto nxt = next(it);
        rt.erase(it);
        it = nxt;
    }

    it = rt.lower_bound(l);

    while (it != rt.end() && it->first <= mid) {
        add(it->second, l - 1);
        auto nxt = next(it);
        rt.erase(it);
        it = nxt;
    }
}

int h[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    fill(sz + 1, sz + nax, 1);
    iota(par, par + nax, 0);
    iota(id, id + n + 1, 0);

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> h[i];
        add(i, h[i]);
    }

    int top = n;

    cin >> q;

    while (q --) {
        int op;
        cin >> op;
        if (op == 1) {

            int k, h;
            cin >> k >> h;
            id[k] = ++ top;
            add(id[k], h);

        } else if (op == 2) {

            int x; cin >> x;
            x = id[x];
            x = find(x);
            cout << a[x] << '\n';

        } else if (op == 3) {

            int l, r;
            cin >> l >> r;
            scale(l, r);

        } else assert(false);
    }
}