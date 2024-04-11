#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int n, m;
int p[N];
vector<int> adj[N];
vector<int> chl[N];
map<array<int,2>, int> id;

int d[N], par[N][20], vis[N];
void dfs1(int u, int p) {
    vis[u] = 1;
    d[u] = d[p] + 1;
    par[u][0] = p;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        chl[u].push_back(v);
        dfs1(v,u);
    }
}
int getPar(int u, int layer) {
    int delta = d[u] - layer;
    for (int i=0; i<20; i++)
        if (delta & (1<<i))
            u = par[u][i];
    return u;
}

vector<int> ans;
set<int> st;
void dfs2(int u) {
    auto tryUp = [&]() {
        if (par[u][0] != u && p[u] != u && (st.count(p[u]) || d[p[u]] <= d[u] || getPar(p[u], d[u]) != u)) {
            ans.push_back(id[{u, par[u][0]}]);
            swap(p[u], p[par[u][0]]);
        }
    };
    tryUp();
    st.insert(u);
    for (int i=0; i<chl[u].size(); i++) {
        int v = getPar(p[u], d[u]+1);
        dfs2(v);
        tryUp();
    }
    st.erase(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> p[i];
    for (int i=1; i<=m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        id[{x, y}] = id[{y, x}] = i;
    }
    vector<int> rt;
    for (int i=1; i<=n; i++)
        if(!vis[i])
            dfs1(i,i), rt.push_back(i);
    for (int j=1; j<20; j++)
        for (int i=1; i<=n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
    for (int i : rt)
        dfs2(i);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}