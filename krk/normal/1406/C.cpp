#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
bool was;

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getLeaf(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        return getLeaf(u, v);
    }
    printf("%d %d\n", v, p);
    return v;
}

void Solve(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (2 * cnt[u] == n) {
            was = true;
            printf("%d %d\n", v, getLeaf(u, v));
            return;
        }
        Solve(u, v);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Count(1, 0);
        was = false;
        Solve(1, 0);
        if (!was)
            printf("1 %d\n1 %d\n", neigh[1][0], neigh[1][0]);
    }
    return 0;
}