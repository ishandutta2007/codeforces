#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int sume;

struct segtree {
    vector <ii> st;
    vector <bool> fl;
    int n;
    void downOn(int v) {
        swap(st[v].first, st[v].second);
        fl[v] = !fl[v];
    }
    void Down(int v) {
        if (fl[v]) {
            downOn(2 * v);
            downOn(2 * v + 1);
            fl[v] = false;
        }
    }
    void Create(int v, int l, int r) {
        st[v] = ii(0, r - l + 1);
        if (l < r) {
            int m = l + r >> 1;
            Create(2 * v, l, m);
            Create(2 * v + 1, m + 1, r);
        }
    }
    void Union(int v) {
        int lc = 2 * v, rc = 2 * v + 1;
        st[v] = ii(st[lc].first + st[rc].first, st[lc].second + st[rc].second);
    }
    segtree(int gn = 0) {
        n = gn;
        if (n == 0) return;
        int m = 1;
        while (m <= 4 * n) m *= 2;
        st.resize(m);
        fl.resize(m, false);
        Create(1, 0, n - 1);
    }
    void Update(int v, int l, int r, int a, int b) {
        if (l == a && r == b) downOn(v);
        else {
            int m = l + r >> 1;
            Down(v);
            if (a <= m) Update(2 * v, l, m, a, min(m, b));
            if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
            Union(v);
        }
    }
    void Update(int lef, int rig) {
        sume -= st[1].first;
        Update(1, 0, n - 1, lef, rig);
        sume += st[1].first;
    }
};

int n, m;
vector <int> neigh[Maxn];
int tk[Maxn];
int P[Maxn];
vector <int> cycle;
int cycleid[Maxn];
bool incycle[Maxn];
int cnt[Maxn], L[Maxn];
int head[Maxn], id[Maxn];
int paredge[Maxn];
segtree st[Maxn], G;

bool discoverCycle(int v, int p)
{
    if (tk[v] == 2) return false;
    if (tk[v] == 1) {
        while (true) {
            incycle[p] = true;
            cycleid[p] = cycle.size();
            cycle.push_back(p);
            if (p == v) break;
            p = P[p];
        };
        G = segtree(cycle.size());
        return true;
    }
    tk[v] = 1;
    P[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (discoverCycle(u, v)) return true;
    }
    tk[v] = 2;
    return false;
}

void Traverse1(int v)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u || incycle[u]) continue;
        P[u] = v; L[u] = L[v] + 1;
        cycleid[u] = cycleid[v];
        Traverse1(u);
        cnt[v] += cnt[u];
    }
}

void Traverse2(int v)
{
    bool was = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u || incycle[u]) continue;
        if (cnt[u] > cnt[v] / 2) {
            was = true;
            head[u] = head[v]; id[u] = id[v] + 1;
        } else {
            head[u] = u; id[u] = 0;
        }
        Traverse2(u);
    }
    if (!was) st[head[v]] = segtree(id[v]);
}

void flipCycle(int from, int to)
{
    ii lef;
    lef.first = (from - to + int(cycle.size())) % int(cycle.size());
    lef.second = cycle[(from - 1 + int(cycle.size())) % int(cycle.size())];
    ii rig;
    rig.first = (to - from + int(cycle.size())) % int(cycle.size());
    rig.second = cycle[(from + 1) % int(cycle.size())];
    if (lef < rig) swap(from, to);
    if (from < to) G.Update(from, to - 1);
    else {
        G.Update(from, int(cycle.size()) - 1);
        if (to > 0) G.Update(0, to - 1);
    }
}

void flipEdge(int v)
{
    sume -= paredge[v];
    paredge[v] = 1 - paredge[v];
    sume += paredge[v];
}

void flipTree(int a, int b)
{
    while (head[a] != head[b]) {
        if (L[head[a]] < L[head[b]])
            swap(a, b);
        if (id[a] > 0) st[head[a]].Update(0, id[a] - 1);
        a = head[a];
        flipEdge(a);
        a = P[a];
    }
    if (a == b) return;
    if (L[a] < L[b]) swap(a, b);
    st[head[a]].Update(id[b], id[a] - 1);
}

int getAnswer()
{
    int res = n - sume;
    if (G.st[1].first == cycle.size()) res++;
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    discoverCycle(1, 0);
    for (int i = 0; i < cycle.size(); i++) {
        int root = cycle[i];
        P[root] = L[root] = 0;
        Traverse1(root);
        head[root] = root; id[root] = 0;
        Traverse2(root);
    }
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        if (cycleid[a] == cycleid[b])
            flipTree(a, b);
        else {
            flipTree(a, cycle[cycleid[a]]);
            flipCycle(cycleid[a], cycleid[b]);
            flipTree(b, cycle[cycleid[b]]);
        }
        printf("%d\n", getAnswer());
    }
    return 0;
}