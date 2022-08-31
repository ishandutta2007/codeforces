#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
vector < int > g[maxN];
int val[maxN];
int n;
int sb[maxN];
int sz[maxN];
bool used[maxN];
void dfs_cen(int root, int p, vector < int >& all) {
    sb[root] = 0;
    sz[root] = 1;
    all.push_back(root);
    for (int to : g[root]) {
        if (used[to] || to == p) continue;
        dfs_cen(to, root, all);
        sz[root] += sz[to];
        sb[root] = max(sb[root], sz[to]);
    }
}
const int PW = (1 << 20) + 10;
int mask[PW];
int his_mask[PW];
void calc_son(int v, int p, int val_now, vector < int >& hs) {
    val_now ^= (1 << val[v]);
    his_mask[v] = val_now;
    hs.push_back(val_now);
    for (int to : g[v]) {
        if (to == p || used[to]) continue;
        calc_son(to, v, val_now, hs);
    }
}

ll tot[maxN];
int cen_val;
ll last_dfs(int v, int p) {
    ll cur = 0;
    int need = his_mask[v] ^ cen_val;
    cur += mask[need];
    for (int bit = 0; bit < 20; bit++) {
        cur += mask[need ^ (1 << bit)];
    }
    for (int to : g[v]) {
        if (to == p || used[to]) continue;
        cur += last_dfs(to, v);
    }
    tot[v] += cur;
    return cur;
}

void solve(int root) {
    vector < int > all;
    dfs_cen(root, -1, all);
    int n = all.size();
    int cen = -1;
    for (int v : all) {
        if (2 * sb[v] <= n && 2 * (n - sz[v]) <= n) {
            cen = v;
            break;
        }
    }
    assert(cen != -1);
    vector < vector < int > > vals;
    vector < int > sons;
    for (int to : g[cen]) {
        if (used[to]) continue;
        sons.push_back(to);
        vector < int > he;
        int hs = 0;
        calc_son(to, cen, hs, he);
        vals.push_back(he);
    }
    // cen
    cen_val = (1 << val[cen]);
    mask[0]++;
    tot[cen]++;
    for (auto& vec : vals) {
        // count for centroid
        for (int msk : vec) {
            int need = msk ^ cen_val;
            tot[cen] += mask[need];
            for (int bit = 0; bit < 20; bit++) {
                tot[cen] += mask[need ^ (1 << bit)];
            }
        }
        for (int msk : vec) mask[msk]++;
    }
    for (int i = 0; i < sons.size(); i++) {
        for (int msk : vals[i]) mask[msk]--;
        last_dfs(sons[i], cen);
        for (int msk : vals[i]) mask[msk]++;
    }
    for (auto& vec : vals) {
        for (int msk : vec) mask[msk]--;
    }
    mask[0]--;
    used[cen] = true;
    vals.clear();
    for (int to : g[cen]) {
        if (used[to]) continue;
        solve(to);
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        val[i] = c - 'a';
    }
    solve(1);
    for (int i = 1; i <= n; i++) cout << tot[i] << " ";
    cout << '\n';
    return 0;
}