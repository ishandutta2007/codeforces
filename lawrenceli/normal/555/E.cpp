#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 200100;
const int MAXLG = 20;

int n, m, q;
vector<pii> adj[MAXN];
int ind[MAXN], lowlink[MAXN], cnt;

int par[MAXN];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }

void merge(int a, int b) { par[getpar(a)] = getpar(b); }

void dfs(int cur, int p=-1, int pa=-1) {
    ind[cur] = lowlink[cur] = cnt++;
    for (pii x : adj[cur]) {
        if (x.se == p) continue;
        if (ind[x.fi] == -1) {
            dfs(x.fi, x.se, cur);
            lowlink[cur] = min(lowlink[cur], lowlink[x.fi]);
        } else {
            lowlink[cur] = min(lowlink[cur], ind[x.fi]);
        }
    }

    if (pa != -1 && lowlink[cur] <= ind[pa])
        merge(cur, pa);
}

bool vis[MAXN];
vector<int> uadj[MAXN];
int jump[MAXN][MAXLG], dep[MAXN];

int cmp[MAXN], cmpcnt;

void dfs2(int cur, int p=-1) {
    assert(!vis[cur]);
    vis[cur] = 1;
    cmp[cur] = cmpcnt;
    jump[cur][0] = p == -1 ? cur : p;
    dep[cur] = p == -1 ? 0 : dep[p]+1;
    for (int i : uadj[cur]) {
        if (i == p) continue;
        dfs2(i, cur);
    }
}

void initlca() {
    for (int k=0; k+1<MAXLG; k++)
        for (int i=1; i<=n; i++)
            jump[i][k+1] = jump[jump[i][k]][k];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

int add[MAXN][2];

pii dfs3(int cur, int p=-1) {
    assert(!vis[cur]);
    vis[cur] = 1;
    pii ret = pii(add[cur][0], add[cur][1]);
    for (int i : uadj[cur]) {
        if (i == p) continue;
        pii x = dfs3(i, cur);
        ret.fi += x.fi, ret.se += x.se;
    }
    assert(ret.fi >= 0 && ret.se >= 0);
    if (ret.fi && ret.se) {
        cout << "No";
        exit(0);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> q;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(pii(b, i));
        adj[b].push_back(pii(a, i));
    }

    for (int i=1; i<=n; i++) par[i] = i;

    memset(ind, -1, sizeof(ind));
    for (int i=1; i<=n; i++)
        if (ind[i] == -1)
            dfs(i);

    for (int i=1; i<=n; i++)
        for (pii x : adj[i])
            if (getpar(i) != getpar(x.fi))
                uadj[getpar(i)].push_back(getpar(x.fi));

    for (int i=1; i<=n; i++) {
        sort(uadj[i].begin(), uadj[i].end());
        uadj[i].resize(unique(uadj[i].begin(), uadj[i].end())-uadj[i].begin());
    }

    for (int i=1; i<=n; i++)
        if (!vis[i]) {
            dfs2(i);
            cmpcnt++;
        }

    initlca();

    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        a = getpar(a), b = getpar(b);
        if (cmp[a] != cmp[b]) {
            cout << "No";
            return 0;
        }
        int c = lca(a, b);
        add[a][0]++, add[b][1]++;
        add[c][0]--, add[c][1]--;
    }

    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++)
        if (!vis[i])
            dfs3(i);
    cout << "Yes";
}