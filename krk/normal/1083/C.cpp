#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 4;
const int Maxn = 400005;
const int Maxm = 22;
const int Maxs = 1048576;

struct edge {
    int a, b;
    bool ok;
    edge() { a = b = 0; ok = false; }
};

int n;
int val[Maxn];
int seq[Maxn];
vector <int> neigh[Maxn];
int L[Maxn];
int my[Maxn];
int all[Maxn], alen;
int rmq[Maxn][Maxm];
int lg2[Maxn];
edge st[Maxs];

void Traverse(int v)
{
    my[v] = alen; all[alen++] = v;
    for (int i = 0; i < neigh[v].size(); i++) {
        Traverse(neigh[v][i]);
        all[alen++] = v;
    }
}

int getLCA(int a, int b)
{
    if (my[a] > my[b]) swap(a, b);
    int tk = lg2[my[b] - my[a] + 1];
    int u = rmq[my[a]][tk], v = rmq[my[b] - (1 << tk) + 1][tk];
    if (L[u] > L[v]) swap(u, v);
    return u;
}

edge Union(const edge &e1, const edge &e2)
{
    edge res;
    if (!e1.ok || !e2.ok) { res.ok = false; return res; }
    vector <ii> seq;
    seq.push_back(ii(my[e1.a], e1.a));
    seq.push_back(ii(my[e1.b], e1.b));
    seq.push_back(ii(my[e2.a], e2.a));
    seq.push_back(ii(my[e2.b], e2.b));
    sort(seq.begin(), seq.end());
    int glca = -1;
    for (int i = 0; i + 1 < seq.size(); i++) {
        int lca = getLCA(seq[i].second, seq[i + 1].second);
        if (glca == -1 || L[lca] < L[glca]) glca = lca;
    }
    vector <int> myres;
    for (int i = 0; i < 2; i++) {
        int gend = -1;
        for (int j = 0; j < seq.size(); j++) if (seq[j].second != -1)
            if (gend == -1 || L[seq[j].second] > L[seq[gend].second]) gend = j;
        if (gend == -1) break;
        int sav = seq[gend].second; seq[gend].second = -1;
        gend = sav;
        myres.push_back(gend);
        for (int j = 0; j < seq.size(); j++) if (seq[j].second != -1)
            if (getLCA(gend, seq[j].second) == seq[j].second &&
                getLCA(seq[j].second, glca) == glca) seq[j].second = -1;
    }
    for (int j = 0; j < seq.size(); j++) if (seq[j].second != -1) {
        res.ok = false; return res;
    }
    res.ok = true;
    res.a = myres[0];
    res.b = myres.size() >= 2? myres[1]: glca;
    if (getLCA(res.a, res.b) != glca)
        res.ok = false;
    return res;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].ok = true;
        st[v].a = st[v].b = seq[l];
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) {
        st[v].ok = true;
        st[v].a = st[v].b = seq[l];
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int Get(int v, int l, int r, const edge &e, bool has)
{
    if (l == r) {
        if (!st[v].ok) return l;
        if (!has) return l + 1;
        edge tocheck = Union(e, st[v]);
        return tocheck.ok? l + 1: l;
    } else {
        int m = l + r >> 1;
        if (!st[2 * v].ok) return Get(2 * v, l, m, e, has);
        if (!has) return Get(2 * v + 1, m + 1, r, st[2 * v], true);
        edge tocheck = Union(e, st[2 * v]);
        if (tocheck.ok) return Get(2 * v + 1, m + 1, r, tocheck, true);
        else return Get(2 * v, l, m, e, has);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
        seq[val[i]] = i;
    }
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
        L[i] = L[p] + 1;
    }
    Traverse(1);
    for (int i = 0; i < alen; i++)
        rmq[i][0] = all[i];
    for (int j = 1; j < Maxm; j++)
        for (int i = 0; i + (1 << j) <= alen; i++) {
            int a = rmq[i][j - 1], b = rmq[i + (1 << j - 1)][j - 1];
            if (L[a] > L[b]) swap(a, b);
            rmq[i][j] = a;
        }
    for (int i = 0; i < Maxm; i++)
        for (int j = 1 << i; j < Maxn && j < (1 << i + 1); j++)
            lg2[j] = i;
    Create(1, 0, n - 1);
    int q; scanf("%d", &q);
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int a, b; scanf("%d %d", &a, &b);
            if (a == b) continue;
            swap(val[a], val[b]);
            seq[val[a]] = a; seq[val[b]] = b;
            Update(1, 0, n - 1, val[a]);
            Update(1, 0, n - 1, val[b]);
        } else printf("%d\n", Get(1, 0, n - 1, edge(), false));
    }
    return 0;
}