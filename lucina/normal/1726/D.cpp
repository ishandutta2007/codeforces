#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n, m;
pair <int, int> e[nax];
vector <int> g[nax];
bool vis[nax];
int ans[nax];
int h[nax];
int get_other(int e_id, int u) {
    return u ^ e[e_id].first ^ e[e_id].second;
}
vector <int> bar;
int par[nax];
int dsu_par[nax];
int find(int x) {
    return x == dsu_par[x] ? x : dsu_par[x] = find(dsu_par[x]);
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    dsu_par[x] = y;
    return true;
}

void dfs(int v, int parent) {
    vis[v] = true;
    h[v] = h[parent] + 1;
    for (int id : g[v]) {
        int to = get_other(id, v);
        if (to == parent) continue;
        if (!vis[to]) {
            par[to] = id;
            dfs(to, v);
            ans[id] = 0;
        } else {
            ans[id] = 1;
            bar.push_back(id);
        }
    }
}

void solve() {
    /**
        m = n - 1
        n + 1

        m = n,
        color backedge

        m = n + 1?
        There are two backedges.
        So just color, two of them,

        m = n + 2?
        troublesome cases? When 3 backedges from cycle?
    */
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        g[i].clear(), vis[i] = false;
    for (int i = 1 ; i <= m ; ++ i) {
        auto &[u, v] = e[i];
        cin >> u >> v;
        if (u > v) swap(u, v);
        g[u].push_back(i);
        g[v].push_back(i);
    }
    bar.clear();

    dfs(1, 0);

    if (m != n + 2) {
        for (int i = 1 ; i <= m ; ++ i)
            cout << ans[i];
        cout << '\n';
        return;
    }
    int res = 0;
    sort(bar.begin(), bar.end());
    bar.erase(unique(bar.begin(), bar.end()), bar.end());
    assert(bar.size() == 3);
    bool ok = true;

    iota(dsu_par, dsu_par + 1 + n, 0);

    for (int j : bar) {
        ok &= unite(e[j].first, e[j].second);
    }


    if (!ok) {
        set <int> s;
        for (int id : bar) {
            s.insert(e[id].first);
            s.insert(e[id].second);
        }
        assert(s.size() == 3);
        vector <int> g;
        for (int id : s) {
            g.push_back(id);
        }
        int where_min = g[0], where_max = g[0], r = 0;
        for (int i : g) {
            r ^= i;
            if (h[i] < h[where_min]) where_min = i;
            if (h[i] > h[where_max]) where_max = i;
        }
        int mid = r ^ where_max ^ where_min;

        int cur = where_max;
        int lst;
        while (cur != where_min) {
            int t = par[cur];
            lst = t;
            cur = e[par[cur]].first ^ e[par[cur]].second ^ cur;
        }
        ans[lst] = 1;
        if (mid > where_min) swap(mid, where_min);
        for (int j : bar) {
            if (e[j] == make_pair(mid, where_min)) {
                ans[j] = 0;
                break;
            }
        }
    }
    for (int i = 1 ; i <= m ; ++ i)
        cout << ans[i];
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    combined round~
    which faces?
    :D ? :E ? :O ? X<
*/