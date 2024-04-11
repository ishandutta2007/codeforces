#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
int A[Maxn], B[Maxn];
int par[Maxn], siz[Maxn];
vector <ii> neigh[Maxn];
bool tk[Maxn];
vector <int> rem;
deque <ii> seq;
int lst = 1;
vector <int> cur = {1};
vector <vector <int> > res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

void skipSeq()
{
    while (!seq.empty() && getPar(seq.back().second) == getPar(1))
        seq.pop_back();
}

void addEdge(int a, int b, int ind)
{
    neigh[a].push_back(ii(b, ind));
    neigh[b].push_back(ii(a, ind));
}

void insertCur()
{
    int sz = cur.size(); cur.insert(cur.begin(), sz);
    res.push_back(cur); cur.clear();
}

void Change(int a, int b, int ind)
{
    unionSet(a, b);
    insertCur();
    res.push_back({ind, a, b});
    addEdge(a, b, ind);
    tk[ind] = true;
}

void Entry(int v)
{
    if (v != lst) {
        cur.push_back(v);
        lst = v;
    }
}

void Traverse(int v, int p)
{
    Entry(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p) continue;
        Traverse(u, v);
        Entry(v);
        int ind = neigh[v][i].second;
        skipSeq();
        if (!seq.empty() && !tk[ind])
            Change(v, seq.back().second, ind);
    }
}

void processLeaf(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p) continue;
        processLeaf(u, v);
        return;
    }
    int ind = neigh[v][0].second;
    int pnt = 0;
    while (neigh[p][pnt].second != ind) pnt++;
    neigh[p].erase(neigh[p].begin() + pnt);
    neigh[v].clear();
    par[v] = v; siz[v] = 1;
    seq.push_front(ii(1, v));
    Change(p, 1, ind);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &A[i], &B[i]);
        if (unionSet(A[i], B[i]))
            addEdge(A[i], B[i], i);
        else rem.push_back(i);
    }
    for (int i = 1; i <= n; i++) if (getPar(i) == i && i != getPar(1))
        seq.push_back(ii(siz[i], i));
    sort(seq.begin(), seq.end());
    for (int i = 0; i < rem.size(); i++) {
        int ind = rem[i];
        int p = getPar(A[ind]);
        skipSeq();
        if (!seq.empty())
            if (p == getPar(1))
                Change(A[ind], seq.back().second, ind);
            else Change(A[ind], 1, ind);
    }
    Traverse(1, 0);
    skipSeq();
    while (!seq.empty())
        if (seq.back().first <= 2) break;
        else {
            neigh[1].clear();
            processLeaf(seq.back().second, 0);
            Traverse(1, 0);
            skipSeq();
        }
    if (!seq.empty()) {
        printf("NO\n");
        return 0;
    }
    insertCur();
    printf("YES\n");
    printf("%d\n", int(res.size()) / 2);
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[i].size(); j++)
            printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
    return 0;
}