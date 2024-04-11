#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int Inf = 1000000000;

int n, m;
vector <ii> neigh[Maxn], rneigh[Maxn];
int reach[Maxn];
int mn[Maxn], mx[Maxn];
int res[Maxn];
int ea[Maxn], eb[Maxn];

void Reach(int v, vector <ii> neigh[], int b)
{
    if (reach[v] & b) return;
    reach[v] |= b;
    for (int i = 0; i < neigh[v].size(); i++)
        Reach(neigh[v][i].first, neigh, b);
}

void getMin(int v, int val)
{
    if (val <= mn[v] || reach[v] != 3) return;
    mn[v] = val;
    if (val >= 10000) return;
    for (int i = 0; i < neigh[v].size(); i++)
        getMin(neigh[v][i].first, val + 1);
    for (int i = 0; i < rneigh[v].size(); i++)
        getMin(rneigh[v][i].first, val - 2);
}

void getMax(int v, int val)
{
    if (val >= mx[v] || reach[v] != 3) return;
    mx[v] = val;
    if (val < 0) return;
    for (int i = 0; i < neigh[v].size(); i++)
        getMax(neigh[v][i].first, val + 2);
    for (int i = 0; i < rneigh[v].size(); i++)
        getMax(rneigh[v][i].first, val - 1);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        ea[i] = a; eb[i] = b;
        neigh[a].push_back(ii(b, i));
        rneigh[b].push_back(ii(a, i));
    }
    Reach(1, neigh, 1);
    Reach(n, rneigh, 2);
    fill(mn, mn + n + 1, -Inf);
    fill(mx, mx + n + 1, Inf);
    getMin(1, 0);
    getMax(1, 0);
    for (int i = 1; i <= n; i++) if (reach[i] == 3)
        if (mn[i] > mx[i]) { printf("No\n"); return 0; }
    printf("Yes\n");
    for (int i = 0; i < m; i++)
        if (reach[ea[i]] != 3 || reach[eb[i]] != 3) printf("1\n");
        else printf("%d\n", mn[eb[i]] - mn[ea[i]]);
    return 0;
}