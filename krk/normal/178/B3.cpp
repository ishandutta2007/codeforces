#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 100005;
const int Maxp = 18;

int n, m;
int a[Maxm], b[Maxm];
vector <int> neigh[Maxn], id[Maxn];
bool taken[Maxn];
int num[Maxn], low[Maxn];
int col;
bool br[Maxm];
int k;
int p[Maxn], pid[Maxn];
set <ii> S;
vector <int> nneigh[Maxn];
int T[Maxn], L[Maxn], P[Maxn][Maxp];

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

void giveColor(int v)
{
    if (taken[v]) return;
    taken[v] = true; num[v] = col;
    for (int i = 0; i < neigh[v].size(); i++) if (!br[id[v][i]]) giveColor(neigh[v][i]);
}

void Traverse(int v, int p, int l)
{
    T[v] = p; L[v] = l;
    for (int i = 0; i < nneigh[v].size(); i++) {
        int u = nneigh[v][i];
        if (u == p && u != v) continue;
        Traverse(u, v, l + 1);
    }
}

void Preprocess()
{
    for (int i = 0; i < col; i++)
        for (int j = 0; 1 << j < col; j++) P[i][j] = -1;
    for (int i = 0; i < col; i++) P[i][0] = T[i];
    for (int j = 1; 1 << j < col; j++)
        for (int i = 0; i < col; i++)
            if (P[i][j - 1] != -1) P[i][j] = P[P[i][j - 1]][j - 1];
}

int getRes(int v, int u)
{
    int res = 0;
    if (L[v] < L[u]) swap(v, u);
    int log = 1;
    while (1 << log <= L[v]) log++;
    log--;
    for (int i = log; i >= 0; i--)
        if (L[v] - (1 << i) >= L[u]) {
            res += 1 << i;
            v = P[v][i];
        }
    if (v == u) return res;
    for (int i = log; i >= 0; i--)
        if (P[v][i] != -1 && P[v][i] != P[u][i]) {
            res += 2 * (1 << i);
            v = P[v][i], u = P[u][i];
        }
    return res + 2;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        neigh[a[i]].push_back(b[i]); neigh[b[i]].push_back(a[i]);
        id[a[i]].push_back(i); id[b[i]].push_back(i);
    }
    Search(1, 0);
    fill(taken, taken + Maxn, false);
    col = 0;
    for (int i = 1; i <= n; i++) if (!taken[i]) {
        giveColor(i); col++;
    }
    for (int i = 0; i < m; i++) if (br[i]) {
        S.insert(make_pair(num[a[i]], num[b[i]]));
        S.insert(make_pair(num[b[i]], num[a[i]]));
    }
    for (set <ii>::iterator it = S.begin(); it != S.end(); it++)
        nneigh[it->first].push_back(it->second);
    fill(T, T + Maxn, -1);
    Traverse(0, -1, 0);
    Preprocess();
    scanf("%d", &k);
    while (k--) {
        int s, l; scanf("%d %d", &s, &l);
        printf("%d\n", getRes(num[s], num[l]));
    }
    return 0;
}