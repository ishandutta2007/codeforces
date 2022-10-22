#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 100005;
const int Maxw = 1000000;

int n, m;
int p[Maxn], siz[Maxn];
vector <int> neigh[Maxn], id[Maxn];
set <int> A;
int cur, mn[Maxn];
int a[Maxm], b[Maxm], w[Maxm];
int s[Maxm];
int res[Maxm];

bool Less(const int &a, const int &b)
{
    return w[a] < w[b];
}

int getPar(int x)
{
    return p[x] == x? x: p[x] = getPar(p[x]);
}

void findBridges(int v, int p, int ind)
{
    if (mn[v]) return;
    int st = ++cur;
    mn[v] = st;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p && id[v][i] == ind) continue;
        findBridges(u, v, id[v][i]);
        mn[v] = min(mn[v], mn[u]);
    }
    if (p && mn[v] == st) res[ind] = 1;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i], &b[i], &w[i]);
        s[i] = i;
    }
    for (int i = 1; i <= n; i++) { p[i] = i; siz[i] = 1; }
    sort(s, s + m, Less);
    int j = 0;
    for (int i = 1; i <= Maxw; i++) {
        while (j < m && w[s[j]] < i) j++;
        if (j == m || w[s[j]] > i) continue;
        A.clear();
        for (int l = j; l < m && w[s[l]] == i; l++) {
            int e = s[l];
            int pa = getPar(a[e]), pb = getPar(b[e]);
            if (pa == pb) res[s[l]] = -1;
            else {
                if (A.find(pa) == A.end()) { neigh[pa].clear(); id[pa].clear(); A.insert(pa); mn[pa] = 0; }
                if (A.find(pb) == A.end()) { neigh[pb].clear(); id[pb].clear(); A.insert(pb); mn[pb] = 0; }
                neigh[pa].push_back(pb); id[pa].push_back(e);
                neigh[pb].push_back(pa); id[pb].push_back(e);
            }
        }
        cur = 0;
        if (!A.empty())
            for (set <int>::iterator it = A.begin(); it != A.end(); it++) findBridges(*it, 0, -1);
        for (int l = j; l < m && w[s[l]] == i; l++) {
            int e = s[l];
            int pa = getPar(a[e]), pb = getPar(b[e]);
            if (pa != pb)
                if (siz[pa] > siz[pb]) { p[pb] = pa; siz[pa] += siz[pb]; }
                else { p[pa] = pb; siz[pb] += siz[pa]; }
        }
    }
    for (int i = 0; i < m; i++)
        if (res[i] > 0) printf("any\n");
        else if (res[i] == 0) printf("at least one\n");
        else printf("none\n");
    return 0;
}