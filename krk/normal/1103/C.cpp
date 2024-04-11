#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 250005;

int n, m, k;
vector <int> neigh[Maxn];
int my[Maxn];
int seq[Maxn];
bool pth;
vector <vector <int> > cycles;

void Write(vector <int> &V, int l, int r)
{
    for (int i = l; i <= r; i++)
        V.push_back(seq[i]);
}

void Traverse(int v, int lvl)
{
    my[v] = lvl; seq[lvl] = v;
    if (lvl + 1 >= (n + k - 1) / k) {
        pth = true;
        printf("PATH\n");
        printf("%d\n", lvl + 1);
        for (int i = 0; i <= lvl; i++)
            printf("%d%c", seq[i], i + 1 <= lvl? ' ': '\n');
        return;
    }
    int mn[2] = {Maxn, Maxn};
    bool nw = false;
    for (int i = 0; i < neigh[v].size() && !pth && cycles.size() < k; i++) {
        int u = neigh[v][i];
        if (my[u] == -1) { Traverse(u, lvl + 1); nw = true; }
        else if (my[u] < mn[0]) mn[1] = mn[0], mn[0] = my[u];
             else if (my[u] < mn[1]) mn[1] = my[u];
    }
    if (cycles.size() < k && !nw) {
        vector <int> tmp;
        tmp.push_back(v);
        if ((lvl - mn[1] + 1) % 3 != 0)
            Write(tmp, mn[1], lvl - 1);
        else if ((lvl - mn[0] + 1) % 3 != 0)
            Write(tmp, mn[0], lvl - 1);
        else Write(tmp, mn[0], mn[1]);
        cycles.push_back(tmp);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    fill(my, my + Maxn, -1);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n && !pth && cycles.size() < k; i++) if (my[i] == -1)
        Traverse(i, 0);
    if (!pth && cycles.size() < k)
        printf("-1\n");
    else if (!pth) {
        printf("CYCLES\n");
        for (int i = 0; i < cycles.size(); i++) {
            printf("%d\n", int(cycles[i].size()));
            for (int j = 0; j < cycles[i].size(); j++)
                printf("%d%c", cycles[i][j], j + 1 < cycles[i].size()? ' ': '\n');
        }
    }
    return 0;
}