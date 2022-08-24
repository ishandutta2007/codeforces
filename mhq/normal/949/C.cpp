#include <bits/stdc++.h>
using namespace std;
int n, m, h;
const int maxN = (int)1e5 + 10;
vector < int > g[maxN];
vector < int > gr[maxN];
int u[maxN];
map < pair < int, int >, int > s;
bool used[maxN];
int deg[maxN];
vector < int > comp;
int cnt = 0;
vector < int > order;
vector < int > comps[maxN];
map < int, int > q;
void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) dfs1(g[v][i]);
    }
    order.push_back(v);
}
int sz[maxN];
void dfs2(int v) {
    used[v] = true;
    q[v] = cnt;
    comps[cnt].push_back(v);
    sz[cnt]++;
    for (int i = 0; i < gr[v].size(); i++) {
        int to = gr[v][i];
        if (!used[to]) dfs2(to);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) cin >> u[i];
    for (int i = 1; i <= m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        if (u[uu] - u[vv] == 1 || u[uu] - u[vv] == -h + 1) {
            if (s[make_pair(uu, vv)] == 0) {
                s[make_pair(uu, vv)] = 1;
                g[vv].push_back(uu);
                gr[uu].push_back(vv);
            }
        }
        swap(uu, vv);
        if (u[uu] - u[vv] == 1 || u[uu] - u[vv] == -h + 1) {
            if (s[make_pair(uu, vv)] == 0) {
                s[make_pair(uu, vv)] = 1;
                g[vv].push_back(uu);
                gr[uu].push_back(vv);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (!used[i]) dfs1(i);
    for (int i = 1; i <= n; i++) used[i] = false;
    int ans = (int)1e5 + 10;
    for (int i = 0; i < n; i++) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs2(v);
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int to = g[i][j];
            int comp1 = q[i];
            int comp2 = q[to];
            if (comp1 != comp2) deg[comp1]++;
        }
    }
    int ind = -1;
    for (int i = 0; i < cnt; i++) {
        if (deg[i] == 0) {
            if (ans > sz[i]) {
                ans = sz[i];
                ind = i;
            }
        }
    }
    cout << comps[ind].size() << endl;
    for (int i = 0; i < comps[ind].size(); i++) cout << comps[ind][i] << " ";
    return 0;
}