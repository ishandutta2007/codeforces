#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int leaves, buds;

bool Traverse(int v, int p = 0)
{
    int ch = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ch += Traverse(u, v);
    }
    if (ch > 0) {
        leaves += ch;
        buds++;
        return false;
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
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        leaves = buds = 0;
        Traverse(1);
        printf("%d\n", leaves - buds + 1);
    }
    return 0;
}