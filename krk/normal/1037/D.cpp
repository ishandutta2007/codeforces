#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> neigh[Maxn];
int deg[Maxn];
set <ii> S;

void Mark(int v)
{
    for (int i = 0; i < neigh[v].size(); i++)
        deg[neigh[v][i]]--;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b); deg[a]++;
        neigh[b].push_back(a); deg[b]++;
        S.insert(ii(a, b));
        S.insert(ii(b, a));
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (a[1] != 1) { printf("No\n"); return 0; }
    int pnt = 1; Mark(1);
    for (int i = 2; i <= n; i++) {
        while (pnt < i && deg[a[pnt]] == 0) pnt++;
        if (pnt >= i || S.find(ii(a[pnt], a[i])) == S.end()) {
            printf("No\n"); return 0;
        }
        Mark(a[i]);
    }
    printf("Yes\n");
    return 0;
}