#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];
int res;

bool getCycle(int v)
{
    if (tk[v]) return true;
    tk[v] = true;
    bool ok = neigh[v].size() == 2;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!getCycle(neigh[v][i])) ok = false;
    return ok;
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!tk[i])
        res += getCycle(i);
    printf("%d\n", res);
    return 0;
}