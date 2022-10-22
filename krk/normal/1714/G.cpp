#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;

int T;
int n;
int P[Maxn];
vector <iii> neigh[Maxn];
ll sumA[Maxn], sumB[Maxn];
ii res[Maxn];

void Solve(int v, int lvl)
{
    res[v] = ii(lvl, v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i].first;
        sumA[u] = sumA[v] + neigh[v][i].second.first;
        sumB[u] = sumB[v] + neigh[v][i].second.second;
        Solve(u, lvl + 1);
        res[v] = min(res[v], res[u]);
    }
    while (sumA[v] < sumB[res[v].second]) {
        res[v].first--;
        res[v].second = P[res[v].second];
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 2; i <= n; i++) {
            scanf("%d", &P[i]);
            int a, b; scanf("%d %d", &a, &b);
            neigh[P[i]].push_back(iii(i, ii(a, b)));
        }
        Solve(1, 0);
        for (int i = 2; i <= n; i++)
            printf("%d%c", res[i].first, i + 1 <= n? ' ': '\n');
    }
    return 0;
}