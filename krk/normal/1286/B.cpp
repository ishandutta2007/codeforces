#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

bool tk[Maxn];
int n;
vector <int> neigh[Maxn];
int c[Maxn], cnt[Maxn];
int root;
int res[Maxn];

int Get(int ind)
{
    for (int i = 1; i <= n; i++) if (!tk[i])
        if (ind == 1) { tk[i] = true; return i; }
        else ind--;
    return -1;
}

void Count(int v)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Count(u);
        cnt[v] += cnt[u];
    }
}

bool Solve(int v)
{
    if (c[v] + 1 > cnt[v]) return false;
    res[v] = Get(c[v] + 1);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (!Solve(u)) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p; scanf("%d %d", &p, &c[i]);
        if (p == 0) root = i;
        else neigh[p].push_back(i);
    }
    Count(root);
    if (!Solve(root)) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}