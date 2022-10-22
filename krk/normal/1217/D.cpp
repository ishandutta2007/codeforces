#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n, m;
int a[Maxn], b[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
int cur = 1, st[Maxn];
int mx, res[Maxn];

void Solve(int v)
{
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int b = neigh[v][i];
        if (!tk[b]) Solve(b);
    }
    st[v] = cur++;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        neigh[a[i]].push_back(b[i]);
    }
    for (int i = 1; i <= n; i++) if (!tk[i])
        Solve(i);
    for (int i = 0; i < m; i++)
        if (st[a[i]] > st[b[i]]) { mx = max(mx, 1); res[i] = 1; }
        else { mx = max(mx, 2); res[i] = 2; }
    printf("%d\n", mx);
    for (int i = 0; i < m; i++)
        printf("%d%c", res[i], i + 1 < m? ' ': '\n');
    return 0;
}