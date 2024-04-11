#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxN = (int)1e5 + 10;
vector < int > g[maxN];
long long c[maxN];
int p[maxN];
int prv[maxN];
bool used[maxN];
int tree[maxN];
bool ok = false;
vector < int > cycle;
vector < int > order;
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == prv[v]) continue;
        if (used[to] == false) {
            prv[to] = v;
            p[to] = 1 - p[v];
            dfs(to);
            if (ok) return ;
        }
        if (p[to] == p[v]) {
            ok = true;
            while (v != to) {
                cycle.push_back(v);
                v = prv[v];
            }
            cycle.push_back(to);
            return ;
        }
    }
}
void dfs1(int v) {
    if (!used[v]) order.push_back(v);
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to]) continue;
        prv[to] = v;
        dfs1(to);
    }
}
long long ans[maxN];
map < pair < int, int > , long long > edges;
void solve1() {
    memset(used, 0, sizeof used);
    memset(prv, 0, sizeof prv);
    dfs1(1);
    reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); i++) {
        int v = order[i];
        if (v != 1) {
            int to = prv[v];
            ans[edges[minmax(v, to)]] = c[v];
            c[to] -= c[v];
        }
        else {
            if (c[1] != 0) {
                cout << "NO";
                return ;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}
void solve2() {
    memset(used, 0, sizeof used);
    memset(prv, 0, sizeof prv);
    for (int i = 1; i < cycle.size(); i++) {
        order.push_back(cycle[i - 1]);
        prv[cycle[i]] = cycle[i - 1];
        used[cycle[i - 1]] = true;
    }
    dfs1(cycle[cycle.size() - 1]);
    for (int i = 0; i < cycle.size(); i++) {
        dfs1(cycle[i]);
    }
    reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); i++) {
        int v = order[i];
        if (v != cycle[0]) {
            int to = prv[v];
            ans[edges[minmax(v, to)]] = c[v];
            c[to] -= c[v];
            c[v] = 0;
        }
    }
    //for (int i = 0; i < cycle.size(); i++) cout << cycle[i] << " ";
    //for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    //for (int i = 1; i <= n; i++) cout << c[i] << '\n';
    int q = -c[cycle[0]] / 2;
    for (int i = 0; i + 1 < cycle.size(); i++) {
        ans[edges[minmax(cycle[i], cycle[i + 1])]] += (2 * (i % 2) - 1) * q;
    }
    ans[edges[minmax(cycle[0], cycle[cycle.size() - 1])]] = -q;
    cout << "YES" << '\n';
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin)  ;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        edges[make_pair(min(x, y), max(x, y))] = i;
    }
    dfs(1);
    if (!ok) {
        solve1();
    }
    else solve2();
    return 0;
}