#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int root;
int id[Maxn];
int res[Maxn];

bool Solve(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (id[v] < id[u]) res[u] = id[u] - id[v];
        else return false;
        if (!Solve(u)) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 1; i <= n; i++) {
            int p; scanf("%d", &p);
            if (p == i) root = i;
            else neigh[p].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            id[num] = i;
        }
        res[root] = 0;
        if (Solve(root))
            for (int i = 1; i <= n; i++)
                printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        else printf("-1\n");
    }
    return 0;
}