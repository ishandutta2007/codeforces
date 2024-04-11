#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 2005;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[Maxn];
int curtim, tim[Maxn], lowt[Maxn];
int par[Maxn], siz[Maxn];
vector <int> tneigh[Maxn];
int cnt[Maxn], res[Maxn];
bool canget[Maxn];
int best, adder;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
    else { siz[b] += siz[a]; par[a] = b; }
}

void Traverse1(int v, int p = 0)
{
    tim[v] = lowt[v] = ++curtim;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (tim[u] == 0) {
            Traverse1(u, v); lowt[v] = min(lowt[v], lowt[u]);
        } else lowt[v] = min(lowt[v], tim[u]);
        if (tim[v] >= lowt[u]) unionSet(v, u);
    }
}

void Traverse2(int v, int p = 0)
{
    cnt[v] = siz[v]; res[v] = 0;
    for (int i = 0; i < tneigh[v].size(); i++) {
        int u = tneigh[v][i];
        if (u == p) continue;
        Traverse2(u, v); 
        cnt[v] += cnt[u];
        res[v] += res[u] + cnt[u] * siz[v];
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    Traverse1(1);
    for (int i = 1; i <= n; i++) {
        par[i] = getPar(i);
        if (par[i] == i) adder += siz[i] * siz[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            if (par[i] != par[u]) tneigh[par[i]].push_back(par[u]);
        }
    for (int i = 1; i <= n; i++) if (par[i] == i) {
        Traverse2(i);
        int myadder = adder + res[i];
        canget[0] = true; fill(canget + 1, canget + n + 1, false);
        for (int j = 0; j < tneigh[i].size(); j++) {
            int u = tneigh[i][j];
            for (int k = n - cnt[u]; k >= 0; k--) if (canget[k])
                canget[k + cnt[u]] = true;
        }
        for (int k = 0; k <= n; k++) if (canget[k])
            best = max(best, k * (n - k - siz[i]) + myadder);
    }
    printf("%d\n", best);
    return 0;
}