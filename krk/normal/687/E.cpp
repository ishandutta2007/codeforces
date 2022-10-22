#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[Maxn];
int dist[Maxn][Maxn];
int seq[Maxn], slen;
int par[Maxn], siz[Maxn], mn[Maxn], ot[Maxn];

void getDist(int v, int dist[])
{
    fill(dist, dist + n + 1, Inf); dist[v] = 0;
    seq[0] = v; slen = 1;
    for (int i = 0; i < slen; i++) {
        v = seq[i];
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                seq[slen++] = u;
            }
        }
    }
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b, int cand)
{
    a = getPar(a), b = getPar(b);
    mn[a] = min(mn[a], cand);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    mn[a] = min(mn[a], min(cand, mn[b]));
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
        mn[i] = Inf;
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        getDist(i, dist[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            if (dist[u][i] < Inf)
                unionSet(i, u, dist[u][i] + 1);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            if (dist[u][i] >= Inf)
                ot[getPar(i)]++;
        }
    int res = n;
    for (int i = 1; i <= n; i++) if (getPar(i) == i && !ot[i] && mn[i] < Inf) {
        int got = mn[i];
        res = (res - got + got * 999 + 1);
    }
    cout << res << endl;
    return 0;
}