#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
bool col[Maxn];
bool has[Maxn];

void Traverse(int v, int p, bool c)
{
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v, !c);
    }
}

int getSmall()
{
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() == 1 && col[i])
            return 3;
    return 1;
}

int getBig()
{
    int res = n - 1;
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() == 1) {
            has[neigh[i].back()] = true;
            res--;
        }
    for (int i = 1; i <= n; i++) if (neigh[i].size() > 1)
        res += int(has[i]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int r = 1;
    while (neigh[r].size() > 1) r++;
    Traverse(r, 0, false);
    printf("%d %d\n", getSmall(), getBig());
    return 0;
}