#include <bits/stdc++.h>
#define pb push_back
#define ll long long
 
using namespace std;
 
const int N = 5e3 + 5;
 
int n, m, dep[N], par[N];
vector<int> g[N];
int col[N][N];
 
void dfs(int v, int p) {
    dep[v] = dep[p] + 1;
    par[v] = p;
    for (auto u: g[v])
        if (u != p)
            dfs(u, v);
}
 
struct cell {
    int a, b, c;
};
cell p[N];
pair<int, int> q[N];
bool cmp(cell a, cell b) {
    return a.c < b.c;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        q[i] = {a, b};
    }
    //cout << 1;
    dfs(1, 0);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int u = p[i].a, v = p[i].b;
        while (u != v)
            if (dep[u] > dep[v]) {
                int u1 = par[u];
                //col[{u, u1}] = col[{u1, u}] = p[i].c;
                col[u][u1] = col[u1][u] = p[i].c;
                u = u1;
            } else {
                int v1 = par[v];
                //col[{v, v1}] = col[{v1, v}] = p[i].c;
                col[v][v1] = col[v1][v] = p[i].c;
                v = v1;
            }
    }
    for (int i = 1; i <= m; i++) {
        int mn = 1e9 + 9;
        int u = p[i].a, v = p[i].b;
       // cout << u << ' ' << v << endl;
        while (u != v)
            if (dep[u] > dep[v]) {
                int u1 = par[u];
                mn = min(mn, col[u][u1]);
                u = u1;
            } else {
                int v1 = par[v];
                mn = min(mn, col[v][v1]);
                v = v1;
            }
        if (mn != p[i].c) {
            //cout << mn << endl;
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (col[q[i].first][q[i].second] == 0)
            col[q[i].first][q[i].second] = 1;
        cout << col[q[i].first][q[i].second] << " ";
    }
    return 0;
}