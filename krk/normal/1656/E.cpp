#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
vector <int> neigh[Maxn];
int res[Maxn];

int Solve(int v, int p, int lvl)
{
    int got = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        got += Solve(u, v, (lvl + 1) % 2);
    } 
    if (v == 1) {
        res[v] = -got;
        return 0;
    }
    if (lvl == 0) {
        res[v] = 1 - got;
        return 1;
    }
    res[v] = -1 - got;
    return -1;
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
        Solve(1, 0, 0);
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}