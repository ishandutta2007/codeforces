#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
int par[nax];
vector <int> a[nax];
int in_deg[nax];
int out_deg[nax];
int x[nax];
int y[nax];
vector <int> group[nax];
int nxt[nax];
int where[nax];
int root[nax];

struct dsu {
    int par[nax];
    int n;

    dsu(int _n) {
        n = _n;
        iota(par + 1, par + 1 + n, 1);
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        par[y] = x;
        return true;
    }

};

void fail() {
    cout << "0\n";
    exit(0);
}

const int maxn = nax;
bool vis[maxn],d[maxn],ok;
int tin[nax];
vector <int> topo;
void topsort(int nod){
    vis[nod]=true;
    d[nod]=true;
    for(int i:a[nod]){
        if(!vis[i]){
            topsort(i);
        }
        else if(d[i]){
            ok=false;
            fail();
        }
    }
    d[nod]=false;
    topo.push_back(nod);
}

vector < pair <int, int>> edges;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> par[i];
        edges.emplace_back(par[i], i);
       // g[par[i]].push_back(i);
    }

    for (int i = 1 ; i <= k ; ++ i) {
        cin >> x[i] >> y[i];
        ++ in_deg[y[i]];
        ++ out_deg[x[i]];
        nxt[x[i]] = y[i];
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (in_deg[i] >= 2 || out_deg[i] >= 2) {
            fail();
        }
    }

 //   dsu ds(n);

    int top = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (!in_deg[i]) {
            int cur = i;
            group[i].push_back(i);
            while (nxt[cur]) {
                group[i].push_back(nxt[cur]);
       //         ds.unite(cur, nxt[cur]);
                tin[nxt[cur]] = tin[cur] + 1;
                cur = nxt[cur];
            }
            ++ top;
            root[top] = i;
            for (int j : group[i]) where[j] = top;
        }
    }

    for (auto &[u, v] : edges) {
        if (where[u]  == where[v] && tin[u] > tin[v]) fail();
    }

    for (auto &[u, v] : edges) {
        if (where[u] != where[v]) {
            a[where[u]].push_back(where[v]);
        }
    }

    for (int i = 1 ; i <= top ; ++ i) {
        if (!vis[i]) topsort(i);
    }

    if (topo.size() != top) fail();
    reverse(topo.begin(), topo.end());

    for (int j : topo) {
        for (int v : group[root[j]]) cout << v << ' ';
    }
    cout << '\n';
}