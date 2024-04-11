#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int n;
set <int> neigh[Maxn];
bool tk[Maxn];

void Mark(int v)
{
    tk[v] = true;
    for (auto it: neigh[v])
        neigh[it].erase(v);
    neigh[v].clear();
}

void Traverse(int v, int p)
{
    if (tk[v]) return;
    set <int> my = neigh[v];
    Mark(v);
    for (auto it: my) {
        int u = it;
        if (u == p) continue;
        Traverse(u, v);
    }
}

int Ask(int a, int b)
{
    printf("? %d %d\n", a, b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print(int v)
{
    printf("! %d\n", v); fflush(stdout);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    while (true) {
        int zer = -1, one = -1, two = -1;
        for (int i = 1; i <= n; i++) if (!tk[i])
            if (neigh[i].size() == 0) zer = i;
            else if (neigh[i].size() == 1) one = i;
            else if (neigh[i].size() >= 2) two = i;
        if (two != -1) {
            int i = two;
            int a = *neigh[i].begin();
            int b = *neigh[i].rbegin();
            int g = Ask(a, b);
            if (g == a) Traverse(i, a);
            else if (g == b) Traverse(i, b);
            else {
                Traverse(a, i);
                Traverse(b, i);
            }
        } else if (one != -1) {
            int a = one, b = *neigh[one].begin();
            int g = Ask(a, b);
            Print(g); return 0;
        } else { Print(zer); return 0; }
    }
    return 0;
}