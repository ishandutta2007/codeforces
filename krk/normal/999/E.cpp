#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n, m, s;
vector <int> neigh[Maxn];
bool reach[Maxn][Maxn];
int res;

void Fill(int v, bool reach[])
{
    if (reach[v]) return;
    reach[v] = true;
    for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i], reach);
}

int Fin()
{
    for (int i = 1; i <= n; i++)
        if (!reach[s][i]) return i;
    return -1;
}

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        Fill(i, reach[i]);
    int v;
    while ((v = Fin()) != -1) {
        res++;
        for (int i = 1; i <= n; i++)
            if (!reach[v][i] && reach[i][v]) v = i;
        for (int j = 1; j <= n; j++)
            reach[s][j] |= reach[v][j];
    }
    printf("%d\n", res);
    return 0;
}