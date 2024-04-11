#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;
int par[nax];
int n, m, q;
vector < pair <int, int>> queries;
vector < pair <int, int>> edges;
int a[nax];
int lc[nax];
int rc[nax];
bool del[nax];
int where[nax + nax / 4];
int in[nax];
int out[nax];
int cur;
int T = 1;
bool vis[nax];

pair <int, int> sg[nax * 4];

void pull(int v) {
    sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

void update(int v, int x, int y, int pos, pair <int, int> val) {
    if (x == y) {
        sg[v] = val;
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos, val);
        else update(v << 1 | 1, mid + 1, y, pos, val);
        pull(v);
    }
}

pair <int, int> get_max(int v, int x, int y, int l, int r) {
    if (l == x && r == y) {
        return sg[v];
    } else {
        int mid = x + y >> 1;
        if (r <= mid) return get_max(v << 1, x, mid, l, r);
        else if (l > mid) return get_max(v << 1 | 1, mid + 1, y, l, r);
        else return max(get_max(v << 1, x, mid, l, mid)
                        , get_max(v << 1 | 1, mid + 1, y, mid + 1, r));
    }
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    int fake = cur ++;
    lc[fake] = u;
    rc[fake] = v;
    par[u] = fake;
    par[v] = fake;
}

void dfs(int v) {
    vis[v] = true;
    in[v] = ++ T;
    if (lc[v]) dfs(lc[v]);
    if (rc[v]) dfs(rc[v]);
    out[v] = T;
}


int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    edges.resize(m);

    for (auto &[u, v] : edges) {
        scanf("%d %d", &u, &v);
    }

    queries.resize(q);

    for (auto &[u, v] : queries) {
        scanf("%d %d", &u, &v);
        if (u == 2) {
            -- v;
            del[v] = true;
        }
    }

    cur = n + 1;

    iota(par, par + nax, 0);

    for (int i = 0 ; i < m ; ++ i) {
        if (del[i]) continue;
        auto &[u, v] = edges[i];
        join(u, v);
    }

    reverse(queries.begin(), queries.end());

    int now = 0;

    for (auto &[u, v] : queries) {
        if (u == 1) {
            where[now] = find(v);
        } else if (u == 2) {
            auto &[x, y] = edges[v];
            join(x, y);
        } else throw;
        now ++;
    }

    T = -1;

    for (int i = 1 ; i <= n ; ++ i) {
        int root = find(i);
        if (vis[root]) continue;
        T++;
        dfs(root);
    }


    for (int i = 1 ; i < cur ; ++ i)
        assert(vis[i]);


    int s = T + 1;

    for (int i = 1 ; i <= n ; ++ i) {
        update(1, 1, s, in[i], make_pair(a[i], i));
    }


    for (int i = q - 1 ; i >= 0 ; -- i) {
        if (queries[i].first == 2) continue;
        int x = where[i];
        auto y = get_max(1, 1, s, in[x], out[x]);
        printf("%d\n", y.first);
        if (y.first > 0) {
            update(1, 1, s, in[y.second], make_pair(0, 0));
        }
    }




}
/*
    Good Luck
        -Lucina
*/