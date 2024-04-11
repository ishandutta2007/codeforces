#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef pair<pair<int, int>, int> edge;

const int maxn = 200100;
const int maxlg = 18;

int n, m;
edge edges[maxn]; // ( (u, v), (c, id) )
int ind[maxn];
bool inmst[maxn];
int ans[maxn];

bool cmp(int i1, int i2) { return edges[i1].B < edges[i2].B; }

int pardsu[maxn];
int getpar(int a) { return pardsu[a] == a ? a : pardsu[a] = getpar(pardsu[a]); }
void merge(int a, int b) { pardsu[getpar(a)] = getpar(b); }

vector<pair<int, int> > adj[maxn];

int jump[maxlg][maxn], jumpv[maxlg][maxn];
int dep[maxn];

void dfs(int v, int p = -1, int pi = -1) {
    dep[v] = (p == -1 ? 0 : dep[p] + 1);
    jump[0][v] = (p == -1 ? v : p);
    jumpv[0][v] = (p == -1 ? 0 : edges[pi].B);

    for (auto i : adj[v]) {
        if (i.A == p) continue;
        dfs(i.A, v, i.B);
    }
}

void initlca() {
    for (int k = 0; k + 1 < maxlg; k++)
        for (int i = 1; i <= n; i++) {
            jump[k + 1][i] = jump[k][jump[k][i]];
            jumpv[k + 1][i] = max(jumpv[k][i], jumpv[k][jump[k][i]]);
        }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);

    for (int k = maxlg - 1; k >= 0; k--)
        if (dep[jump[k][b]] >= dep[a])
            b = jump[k][b];

    if (a == b) return a;

    for (int k = maxlg - 1; k >= 0; k--)
        if (jump[k][a] != jump[k][b])
            a = jump[k][a], b = jump[k][b];
    return jump[0][a];
}

// b is ancestor of a
int getmaxcost(int a, int b) {
    assert(dep[a] >= dep[b]);
    int ret = 0;
    for (int k = maxlg - 1; k >= 0; k--)
        if (dep[jump[k][a]] >= dep[b]) {
            ret = max(ret, jumpv[k][a]);
            a = jump[k][a];
        }
    return ret;
}

vector<int> ins[maxn], del[maxn];

typedef multiset<int>* stpnt;

stpnt merge(stpnt st1, stpnt st2) {
    if (st1->size() > st2->size()) swap(st1, st2);
    for (int i : *st1) st2->insert(i);
    return st2;
}

stpnt dfs2(int v, int p = -1, int pi = -1) {
    stpnt st = new multiset<int> (ins[v].begin(), ins[v].end());
    
    for (auto i : adj[v]) {
        if (i.A == p) continue;
        st = merge(st, dfs2(i.A, v, i.B));
    }

    for (int i : del[v]) {
        st->erase(st->find(i));
        st->erase(st->find(i));
    }
    
    if (pi == -1) return st;

    if (st->empty()) ans[pi] = 0;
    else ans[pi] = *st->begin();
    return st;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].A.A, &edges[i].A.B, &edges[i].B);
        ind[i] = i;
    }
    sort(ind, ind + m, cmp);

    for (int i = 1; i <= n; i++) pardsu[i] = i;
    for (int ii = 0; ii < m; ii++) {
        int i = ind[ii];
        int a = getpar(edges[i].A.A), b = getpar(edges[i].A.B);
        if (a != b) {
            inmst[i] = true;
            merge(a, b);
        }
    }

    for (int i = 0; i < m; i++)
        if (inmst[i]) {
            int a = edges[i].A.A, b = edges[i].A.B;
            adj[a].push_back(MP(b, i));
            adj[b].push_back(MP(a, i));
        }

    dfs(1);
    initlca();

    for (int i = 0; i < m; i++)
        if (!inmst[i]) {
            int a = edges[i].A.A, b = edges[i].A.B;
            int c = lca(a, b);
            ans[i] = max(getmaxcost(a, c), getmaxcost(b, c));
            int cost = edges[i].B;
            ins[a].push_back(cost), ins[b].push_back(cost);
            del[c].push_back(cost);
        }

    dfs2(1);

    for (int i = 0; i < m; i++) printf("%d ", ans[i] - 1);
}