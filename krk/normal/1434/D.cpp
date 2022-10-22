#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 2097152;

int n;
int A[Maxn], B[Maxn], C[Maxn];
vector <ii> neigh[Maxn];
int my[2][Maxn];
int cur[2], L[2][Maxn], R[2][Maxn];
ii val[2][Maxn];
ii st[2][Maxm];
bool fl[2][Maxm];

ii getMax(int v, int p, int lvl = 0)
{
    ii res = ii(lvl, v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p) continue;
        res = max(res, getMax(u, v, lvl + 1));
    }
    return res;
}

void Traverse(int v, int p, int c, int lvl, int t)
{
    L[t][v] = ++cur[t];
    if (c) val[t][cur[t]] = ii(0, lvl);
    else val[t][cur[t]] = ii(lvl, 0);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        if (u == p) continue;
        int nc = C[neigh[v][i].second]? 1 - c: c;
        Traverse(u, v, nc, lvl + 1, t);
        my[t][neigh[v][i].second] = u;
    }
    R[t][v] = cur[t];
}

void downOn(int t, int v)
{
    swap(st[t][v].first, st[t][v].second);
    fl[t][v] = !fl[t][v];
}

void Down(int t, int v)
{
    if (fl[t][v]) {
        downOn(t, 2 * v);
        downOn(t, 2 * v + 1);
        fl[t][v] = false;
    }
}

void Union(int t, int v)
{
    st[t][v].first = max(st[t][2 * v].first, st[t][2 * v + 1].first);
    st[t][v].second = max(st[t][2 * v].second, st[t][2 * v + 1].second);
}

void Create(int t, int v, int l, int r)
{
    if (l == r) st[t][v] = val[t][l];
    else {
        int m = l + r >> 1;
        Create(t, 2 * v, l, m);
        Create(t, 2 * v + 1, m + 1, r);
        Union(t, v);
    }
}

void Update(int t, int v, int l, int r, int a, int b)
{
    if (l == a && r == b) downOn(t, v);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (a <= m) Update(t, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Update(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
        Union(t, v);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        neigh[A[i]].push_back(ii(B[i], i));
        neigh[B[i]].push_back(ii(A[i], i));
    }
    ii v = getMax(1, 0);
    ii u = getMax(v.second, 0);
    Traverse(v.second, 0, 0, 0, 0);
    Traverse(u.second, 0, 0, 0, 1);
    Create(0, 1, 1, n);
    Create(1, 1, 1, n);
    int m; scanf("%d", &m);
    while (m--) {
        int ind; scanf("%d", &ind);
        ind--;
        int lef = L[0][my[0][ind]];
        int rig = R[0][my[0][ind]];
        Update(0, 1, 1, n, lef, rig);
        lef = L[1][my[1][ind]];
        rig = R[1][my[1][ind]];
        Update(1, 1, 1, n, lef, rig);
        printf("%d\n", max(st[0][1].first, st[1][1].first));
    }
    return 0;
}