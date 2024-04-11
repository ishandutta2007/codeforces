#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
vector <int> neigh[Maxn];
int col[Maxn];

bool Traverse(int v, int c)
{
    if (col[v]) return col[v] == c;
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++)
        if (!Traverse(neigh[v][i], -c)) return false;
    return true;
}

bool Solve()
{
    for (int i = 1; i <= n; i++)
        if (neigh[i].size() != 2) return false;
    for (int i = 1; i <= n; i++) if (!col[i])
        if (!Traverse(i, 1)) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            col[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}