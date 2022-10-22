#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 500005;

int n;
vector <int> neigh[Maxn];
vector <int> my[Maxn];
int pnt;

void Traverse(int v, int p)
{
    for (int i = int(neigh[v].size()) - 1; i >= 0; i--) {
        int u = neigh[v][i];
        if (u == p) continue;
        my[u].push_back(++pnt);
    }
    my[v].push_back(++pnt);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
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
    my[1].push_back(++pnt);
    Traverse(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", my[i][0], my[i][1]);
    return 0;
}