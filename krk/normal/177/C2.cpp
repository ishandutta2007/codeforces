#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, k, m;
bool F[Maxn][Maxn], E[Maxn][Maxn];
bool taken[Maxn];
vector <int> group;
int res;

void Invite(int v)
{
    if (taken[v]) return;
    taken[v] = true; group.push_back(v);
    for (int i = 1; i <= n; i++)
        if (F[v][i]) Invite(i);
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &k);
    while (k--) {
        int u, v; scanf("%d %d", &u, &v);
        F[u][v] = F[v][u] = true;
    }
    scanf("%d", &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        E[u][v] = E[v][u] = true;
    }
    for (int i = 1; i <= n; i++) if (!taken[i]) {
        group.clear();
        Invite(i);
        bool bad = false;
        for (int j = 0; j < group.size() && !bad; j++)
            for (int k = j + 1; k < group.size() && !bad; k++)
                bad = E[group[j]][group[k]];
        if (!bad) res = max(res, (int)group.size());
    }
    printf("%d\n", res);
    return 0;
}