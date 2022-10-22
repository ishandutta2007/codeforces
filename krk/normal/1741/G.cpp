#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 10005;
const int Maxk = 6;

int T;
int n, m;
vector <int> neigh[Maxn];
int dist[Maxk + 1][Maxn];
int f;
int a[Maxn];
bool spec[Maxn];
int k;
int walking[Maxk];
bool dp[Maxn][1 << Maxk];

void BFS(int v, int dist[])
{
    fill(dist + 1, dist + n + 1, Inf);
    dist[v] = 0;
    queue <int> Q; Q.push(v);
    while (!Q.empty()) {
        v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
}

bool Less(const int &u, const int &v)
{
    return dist[Maxk][a[u]] < dist[Maxk][a[v]];
}

bool Check(int u, int mask)
{
    int res = 0;
    int lst = Maxk;
    for (int i = 0; i < k; i++) if (mask & 1 << i) {
        res += dist[lst][a[walking[i]]];
        lst = i;
    }
    res += dist[lst][u];
    return res == dist[Maxk][u];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        scanf("%d", &f);
        for (int i = 0; i < f; i++) {
            scanf("%d", &a[i]);
            spec[i] = false;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int ind; scanf("%d", &ind);
            ind--;
            spec[ind] = true;
            walking[i] = ind;
        }
        BFS(1, dist[Maxk]);
        sort(walking, walking + k, Less);
        for (int i = 0; i < k; i++)
            BFS(a[walking[i]], dist[i]);
        for (int i = 0; i <= f; i++)
            fill(dp[i], dp[i] + (1 << k), false);
        dp[0][0] = true;
        for (int i = 0; i < f; i++)
            if (spec[i])
                for (int j = 0; j < 1 << k; j++)
                    dp[i + 1][j] = dp[i][j];
            else for (int z = 0; z < 1 << k; z++) if (Check(a[i], z))
                for (int j = 0; j < 1 << k; j++)
                    dp[i + 1][z | j] |= dp[i][j];
        int res = k;
        for (int j = 0; j < 1 << k; j++) if (dp[f][j])
            res = min(res, k - __builtin_popcount(j));
        printf("%d\n", res);
    }
    return 0;
}