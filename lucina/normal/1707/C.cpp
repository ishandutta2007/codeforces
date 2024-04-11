#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int LG = 18;
int n, m;
int u[nax], v[nax];
int par[nax];
bool good[nax];
int dep[nax];
int up[nax][LG];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

vector <int> g[nax];

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    par[u] = v;
    return true;
}
int tin[nax];
int tout[nax];
int timer;

bool is_ancestor(int u, int v) {
    if (tin[u] > tin[v]) swap(u, v);
    return tout[u] >= tout[v];
}

void dfs(int v, int parent) {
    dep[v] = dep[parent] + 1;
    up[v][0] = parent;
    for (int i = 1 ; i < LG ; ++ i) up[v][i] = up[up[v][i - 1]][i - 1];
    tin[v] = timer ++;
    par[v] = parent;
    for (int to : g[v]) {
        if (to == parent) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

int go(int u, int v) {
    if (tin[u] > tin[v]) swap(u, v);
    int dst = dep[v] - dep[u] - 1;
    for (int j = 0 ; j < LG ; ++ j)
        if (dst >> j & 1) v = up[v][j];
    return v;
}


bool bad[nax];
int sum[nax];
int cnt[nax];

void dfs_ans(int v, int parent, int carry) {
    carry += cnt[v];
    sum[v] += carry;
    for (int to : g[v]) {
        if (to == parent) continue;
        dfs_ans(to, v, carry);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++ i) {
        cin >> u[i] >> v[i];
    }
    iota(par + 1, par + 1 + n, 1);
    for (int i = 1 ; i <= n ; ++ i) g[i].clear();

    for (int i = 1 ; i <= m ; ++ i) {
        good[i] = unite(u[i], v[i]);
        bad[i] = false;
        if (good[i]) {
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
    }

    dfs(1, 0);
    int cnt_bad = 0;

    for (int i = 1 ; i <= m ; ++ i) {
        if (!good[i]) {
            cnt_bad += 1;
            if (!is_ancestor(u[i], v[i])) cnt[u[i]] += 1, cnt[v[i]] += 1;
            else {
                cnt[1] += 1;
                if (tin[u[i]] > tin[v[i]]) swap(u[i], v[i]);
                int to = go(u[i], v[i]);
                cnt[to] -= 1;
                cnt[v[i]] += 1;

            }

        }
    }

    dfs_ans(1, 0, 0);

    for (int i = 1 ; i <= n ; ++ i) {
        if (sum[i] == cnt_bad) cout << '1';
        else cout << '0';
    }
    cout << '\n';
    /**
        1) the tree is unique
        2) Let's say we root the tree at (v)
        then, all non-chosen edges should point to parent

        This is necessary condition for (v) to be a good root
        3) it's also sufficient
    */

}

int main() {
    tout[0] = 1e9;
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (T = 1; T -- ;) {
        solve();
    }
}
/*
    long time no, div.1
*/