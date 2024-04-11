#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = (1 << 17) + 4;

int T;
int n;
vector <ii> neigh[Maxn];
int res[Maxn];
int rese[Maxn];
int cur;

void Solve(int v, int p, int got)
{
    got ^= res[v];
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.first == p) continue;
        if (got >= n) {
            rese[u.second] = n + cur;
            res[u.first] = cur;
        } else {
            rese[u.second] = cur;
            res[u.first] = n + cur;
        }
        cur++;
        Solve(u.first, v, (got ^ rese[u.second]));
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int p; scanf("%d", &p);
        n = 1 << p;
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(ii(b, i));
            neigh[b].push_back(ii(a, i));
        }
        cur = 1;
        res[1] = n;
        Solve(1, 0, 0);
        printf("1\n");
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        for (int i = 0; i < n - 1; i++)
            printf("%d%c", rese[i], i + 1 < n - 1? ' ': '\n');
    }
    return 0;
}