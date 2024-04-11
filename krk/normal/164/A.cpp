#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n, m;
int f[Maxn];
vector <int> neigh[Maxn], rneigh[Maxn];
int st[Maxn];

void DFS1(int v)
{
    if (f[v] == 1 || st[v]) return;
    st[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) DFS1(neigh[v][i]);
}

void DFS2(int v)
{
    if (st[v] >= 2) return;
    st[v] += 2;
    if (f[v] == 1) return;
    for (int i = 0; i < rneigh[v].size(); i++) DFS2(rneigh[v][i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b); rneigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (f[i] == 1) {
        st[i] = 1;
        for (int j = 0; j < neigh[i].size(); j++) DFS1(neigh[i][j]);
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == 2) DFS2(i);
    for (int i = 1; i <= n; i++) printf("%d\n", st[i] == 3);
    return 0;
}