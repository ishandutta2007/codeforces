#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxm = 30000000;
const int Maxn = 200005;
const int Inf = 1000000000;

ii A[Maxn], B[Maxn];
int alen, blen;
ii seq[Maxn];
int slen;
iii V[Maxm];
int vlen;
int n;
int h[Maxn];
vector <int> Q;
vector <int> neigh[Maxn];
bool tk[Maxn];
int par[Maxn];
int res[Maxn];

void createNew()
{
    V[vlen++] = iii(ii(Inf, 1), 0);
}

int getLst()
{
    return vlen - 1;
}

int moveBad(int cur)
{
    createNew();
    int lst = getLst();
    if (V[cur].first.first == Inf) {
        V[lst] = V[cur];
        V[lst].first.second++;
    } else V[lst] = iii(ii(Inf, 1), cur);
    return lst;
}

int moveGood(int cur)
{
    if (V[cur].first.second > 1) {
        createNew();
        int lst = getLst();
        V[lst] = V[cur];
        V[lst].first.second--;
        return lst;
    } else if (V[cur].second) return V[cur].second;
           else return cur;
}

void addSeq(const ii &p)
{
    if (slen == 0 || seq[slen - 1].first > p.first) seq[slen++] = p;
    else seq[slen - 1].second += p.second;
}

int Join(int cur1, int cur2)
{
    slen = 0;
    alen = blen = 0;
    while (cur1) {
        A[alen++] = V[cur1].first;
        cur1 = V[cur1].second;
    }
    while (cur2) {
        B[blen++] = V[cur2].first;
        cur2 = V[cur2].second;
    }
    int i = 0, j = 0;
    while (i < alen || j < blen) {
        int val = Inf + 1;
        if (i < alen) val = min(val, A[i].first);
        if (j < blen) val = min(val, B[j].first);
        int hm = Inf;
        if (i < alen) hm = min(hm, A[i].second);
        if (j < blen) hm = min(hm, B[j].second);
        addSeq(ii(val, hm));
        if (i < alen) {
            A[i].second -= hm;
            if (A[i].second == 0) i++;
        }
        if (j < blen) {
            B[j].second -= hm;
            if (B[j].second == 0) j++;
        }
    }
    int nxt = 0;
    for (int i = slen - 1; i >= 0; i--) {
        createNew();
        int lst = getLst();
        V[lst] = iii(seq[i], nxt);
        nxt = lst;
    }
    return nxt;
}

void Traverse1(int v, int p, bool sam)
{
    tk[v] = true;
    if (sam) V[par[v]].first = ii(h[v], 1);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (h[u] > h[v] || u == p) continue;
        if (h[u] == h[v]) {
            Traverse1(u, v, sam);
            par[v] = Join(par[v], moveBad(par[u]));
        } else par[v] = Join(par[v], moveGood(par[u]));
    }
}

void Traverse2(int v, int p)
{
    res[v] = max(h[v], 2 * h[v] - V[par[v]].first.first);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (h[u] != h[v] || u == p) continue;
        par[u] = Join(par[u], moveBad(par[v]));
        Traverse2(u, v);
    }
}

int main()
{
    scanf("%d", &n);
    createNew();
    for (int i = 1; i <= n; i++) {
        int l; scanf("%d", &l);
        if (l == 1) Q.push_back(i);
        else h[i] = Inf;
        createNew();
        par[i] = getLst();
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int z = 0; z < Q.size(); z++) {
        int v = Q[z];
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (h[v] + 1 < h[u]) {
                h[u] = h[v] + 1;
                Q.push_back(u);
            }
        }
    }
    for (int z = 0; z < Q.size(); z++) {
        int v = Q[z];
        if (tk[v]) continue;
        int cnt = 0, sam = 0;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            cnt += h[u] <= h[v];
            sam += h[u] == h[v];
        }
        if (h[v] == 0) {
            if (sam > 0) V[par[v]].first = ii(0, 1);
            continue;
        }
        if (cnt == 1) {
            int i = 0;
            while (h[neigh[v][i]] > h[v]) i++;
            int u = neigh[v][i];
            par[v] = moveGood(par[u]);
            res[v] = max(h[v], 2 * h[v] - V[par[v]].first.first);
        } else {
            Traverse1(v, 0, sam);
            Traverse2(v, 0);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}