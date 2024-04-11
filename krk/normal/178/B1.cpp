#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 2005;
const int Maxm = 2005;

int n, m;
vector <int> neigh[Maxn], id[Maxn];
bool taken[Maxn];
int num[Maxn], low[Maxn];
int col;
bool br[Maxm];
int k;
int p[Maxn], pid[Maxn];

void Search(int v, int p)
{
    num[v] = low[v] = col++; taken[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (taken[u]) low[v] = min(low[v], low[u]);
        else {
            Search(u, v);
            if (num[v] < low[u]) br[id[v][i]] = true;
            low[v] = min(low[v], low[u]);
        }
    }
}

void Go(int v)
{
    taken[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (!taken[u]) {
            taken[u] = true;
            p[u] = v; pid[u] = id[v][i];
            Go(u);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b); neigh[b].push_back(a);
        id[a].push_back(i); id[b].push_back(i);
    }
    Search(1, 0);
    scanf("%d", &k);
    while (k--) {
        int s, l; scanf("%d %d", &s, &l);
        fill(taken, taken + n + 1, false);
        Go(s);
        int res = 0;
        while (l != s) {
            res += br[pid[l]];
            l = p[l];
        }
        printf("%d\n", res);
    }
    return 0;
}