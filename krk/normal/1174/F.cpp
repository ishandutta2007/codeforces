#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
int L[Maxn];
bool er[Maxn];
int cnt[Maxn];
int nd;

int Ask(char typ, int u)
{
    printf("%c %d\n", typ, u); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print(int v) { printf("! %d\n", v); fflush(stdout); }

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        L[u] = L[v] + 1;
        Traverse(u, v);
    }
}

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int sz)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        if (cnt[u] > sz / 2) return getCentroid(u, v, sz);
    }
    return v;
}

void Solve(int v)
{
    Count(v, 0);
    int c = getCentroid(v, 0, cnt[v]);
    int got = Ask('d', c);
    if (got == 0) { Print(c); return; }
    er[c] = true;
    if (got + L[c] == nd) {
        int s = Ask('s', c);
        Solve(s);
    } else for (int i = 0; i < neigh[c].size(); i++) {
                int p = neigh[c][i];
                if (!er[p] && L[p] < L[c]) Solve(p);
            }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    nd = Ask('d', 1);
    if (nd == 0) { Print(1); return 0; }
    Solve(1);
    return 0;
}