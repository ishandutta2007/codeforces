#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, m, nq;
vector <pair <int, int>> edges;
int ans[nax];
int sz[nax];
int par[nax];
vector <pair <int, int>> query_l[nax];

set <pair <int, int>> setik[nax];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void upd_min(int &a, int b) {
    a = min(a, b);
}

struct node {
    int min_r_update;
    int pos_min_r;
    node(){}
    node(int i) {
        min_r_update = n + 1;
        pos_min_r = i;
        min_r_update = query_l[i].empty() ? n + 1 : query_l[i].back().first;
    }
};
node operator +(const node &a, const node &b) {
    node res;
    res.min_r_update = min(a.min_r_update, b.min_r_update);
    res.pos_min_r = (a.min_r_update == res.min_r_update) ? a.pos_min_r : b.pos_min_r;
    return res;
}
node sg[nax << 2];

void build(int v, int l, int r) {
    if (l == r) {
        sg[v] = node(l);
    } else {
        int mid = l + r >> 1;
        build(v << 1, l, mid);
        build(v << 1 | 1, mid + 1, r);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

node query(int v, int x, int y, int l, int r) {
    if (l == x && r == y) {
        return sg[v];
    }
    int mid = x + y >> 1;
    if (r <= mid) return query(v << 1, x, mid, l, r);
    if (l > mid) return query(v << 1 | 1, mid + 1, y, l, r);
    return query(v << 1, x, mid, l, mid) +
    query(v << 1 | 1, mid + 1, y, mid + 1, r);
}

void update(int v, int x, int y, int pos) {
    if (x == y) {
        sg[v] = node(pos);
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos);
        else update(v << 1 | 1, mid + 1, y, pos);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

void solve() {
    cin >> n >> m >> nq;

    edges.clear();

    for (int i = 1 ; i <= m ; ++ i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        query_l[i].clear();
    }

    for (int i = 1 ; i <= nq ; ++ i) {
        ans[i] = m;
        int l, r;
        cin >> l >> r;
        if (l == r) {
            ans[i] = 0;
            continue;
        }
        query_l[l].push_back({r, i});
    }

    for (int i = 1 ; i <= n ; ++ i) {
        sort(query_l[i].rbegin(), query_l[i].rend());
    }
    iota(par + 1, par + 1 + n, 1);
    fill(sz + 1, sz + 1 + n, 1);

    for (int i = 1 ; i <= n ; ++ i) {
        setik[i].clear();
        setik[i].emplace(i, i);
    }

    build(1, 1, n);
    for (int i = 1 ; i <= m ; ++ i) {
        auto [u, v] = edges[i - 1];
        u = find(u), v = find(v);
        if (u == v) continue;
        if (sz[u] > sz[v]) swap(u, v);

        vector <pair <int, int>> new_insert;
        for (auto &[l, r] : setik[u]) {
            auto g = make_pair(l, r);
            auto [it, tr] = setik[v].insert(g);
            assert(tr);
            if (it != setik[v].begin() && prev(it)->second + 1 == l) {
                auto nw = make_pair(prev(it)->first, r);
                auto sv = *prev(it);
                setik[v].erase(make_pair(l, r));
                setik[v].erase(sv);
                setik[v].insert(nw);
                g = nw;
            }
            it = setik[v].find(g);
            if (next(it) != setik[v].end() && next(it)->first == r + 1) {
                auto nw = make_pair(g.first, next(it)->second);
                auto sv = *next(it);
                setik[v].erase(g);
                setik[v].erase(sv);
                setik[v].insert(nw);
                g = nw;
            }
            new_insert.push_back(g);
        }



        for (auto &range : new_insert) {
            if (setik[v].find(range) == setik[v].end()) continue;
            auto [l, r] = range;
            while (true) {
                static vector <int> to_update; to_update.clear();
                node a = query(1, 1, n, l, r);
                if (a.min_r_update <= r) {
                    int query_idx = query_l[a.pos_min_r].back().second;
                    upd_min(ans[query_idx], i);
                    query_l[a.pos_min_r].pop_back();
                    to_update.push_back(a.pos_min_r);
                }
                for (int v : to_update) {
                    update(1, 1, n, v);
                }
                if (to_update.empty()) break;

            }
        }
        setik[u].clear();
        sz[v] = setik[v].size();
        par[u] = v;
    }

    for (int i = 1 ; i <= nq ; ++ i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    rated div.2, quite a while though
*/