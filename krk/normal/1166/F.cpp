#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxb = 60;
const int Maxp = 11;
const int Maxs = 645;

int n, m, c, q;
map <ii, int> M;
int deg[Maxn];
int X[Maxn], Y[Maxn], Z[Maxn];
char qtyp[Maxn];
int qa[Maxn], qb[Maxn], qc[Maxn];
int me[Maxn];
vector <int> spec;
vector <int> neigh[Maxn];
int par[Maxn], siz[Maxn];
ll my[Maxn][Maxp];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    for (int i = 0; i < Maxp; i++)
        my[a][i] |= my[b][i];
}

void Add(int a, int b, int col)
{
    neigh[a].push_back(b);
    neigh[b].push_back(a);
    if (me[a] != -1) {
        int parb = getPar(b);
        my[parb][me[a] / Maxb] |= 1ll << ll(me[a] % Maxb);
    }
    if (me[b] != -1) {
        int para = getPar(a);
        my[para][me[b] / Maxb] |= 1ll << ll(me[b] % Maxb);
    }
    map <ii, int>::iterator it = M.find(ii(a, col));
    if (it != M.end()) unionSet(it->second, b);
    else M[ii(a, col)] = b;
    it = M.find(ii(b, col));
    if (it != M.end()) unionSet(it->second, a);
    else M[ii(b, col)] = a;
}

bool Check(int a, int b)
{
    if (getPar(a) == getPar(b)) return true;
    if (neigh[b].size() < Maxs) {
        for (int i = 0; i < neigh[b].size(); i++)
            if (getPar(a) == getPar(neigh[b][i])) return true;
        return false;
    } else {
        a = getPar(a);
        return bool(my[a][me[b] / Maxb] & 1ll << ll(me[b] % Maxb));
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &c, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
        deg[X[i]]++; deg[Y[i]]++;
    }
    for (int i = 0; i < q; i++) {
        scanf(" %c", &qtyp[i]);
        if (qtyp[i] == '+') {
            scanf("%d %d %d", &qa[i], &qb[i], &qc[i]);
            deg[qa[i]]++; deg[qb[i]]++;
        } else scanf("%d %d", &qa[i], &qb[i]);
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i; siz[i] = 1;
        if (deg[i] >= Maxs) {
            me[i] = spec.size();
            spec.push_back(i);
        } else me[i] = -1;
    }
    for (int i = 0; i < m; i++)
        Add(X[i], Y[i], Z[i]);
    for (int i = 0; i < q; i++)
        if (qtyp[i] == '+')
            Add(qa[i], qb[i], qc[i]);
        else printf("%s\n", Check(qa[i], qb[i])? "Yes": "No");
    return 0;
}