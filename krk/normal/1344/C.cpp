#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n, m;
vector <int> neigh[Maxn], rneigh[Maxn];
int tk[Maxn];
int mn1[Maxn], mn2[Maxn];
char res[Maxn];
int cnt;

bool Loop(int v)
{
    if (tk[v] == 1) return true;
    if (tk[v] == 2) return false;
    tk[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++)
        if (Loop(neigh[v][i])) return true;
    tk[v] = 2;
    return false;
}

void Solve(int v, int mn[], vector <int> neigh[])
{
    if (tk[v]) return;
    tk[v] = true;
    mn[v] = v;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Solve(u, mn, neigh);
        mn[v] = min(mn[v], mn[u]);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (tk[i] == 0)
        if (Loop(i)) { printf("-1\n"); return 0; }
    fill(tk, tk + n + 1, 0);
    for (int i = 1; i <= n; i++) if (!tk[i])
        Solve(i, mn1, neigh);
    fill(tk, tk + n + 1, 0);
    for (int i = 1; i <= n; i++) if (!tk[i])
        Solve(i, mn2, rneigh);
    for (int i = 1; i <= n; i++)
        if (mn1[i] == i && mn2[i] == i) { res[i] = 'A'; cnt++; }
        else res[i] = 'E';
    res[n + 1] = '\0';
    printf("%d\n", cnt);
    printf("%s\n", res + 1);
    return 0;
}