#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int siz[Maxn];

void Traverse(int v)
{
    if (neigh[v].size() == 0) siz[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Traverse(u);
        siz[v] += siz[u];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    sort(siz + 1, siz + n + 1);
    for (int i = 1; i <= n; i++)
        printf("%d%c", siz[i], i + 1 <= n? ' ': '\n');
    return 0;
}