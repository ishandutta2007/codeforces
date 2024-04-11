#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 105;
const int Inf = 1000000000;

int mod1, mod2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, a, b;
vector <int> neigh[Maxn];
int dist[Maxn][Maxn];
ii ways[Maxn][Maxn];
int k;
int qa[Maxn], qb[Maxn];
int val[Maxn][Maxn];
int res[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Bfs(int v, int dist[], ii ways[])
{
    fill(dist, dist + n + 1, Inf);
    dist[v] = 0;
    ways[v] = ii(1, 1);
    queue <int> Q; Q.push(v);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                ways[u] = ii(0, 0);
                Q.push(u);
            }
            if (dist[v] + 1 == dist[u]) {
                ways[u].first = (ways[u].first + ways[v].first) % mod1;
                ways[u].second = (ways[u].second + ways[v].second) % mod2;
            }
        }
    }
}

int main()
{
    mod1 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        neigh[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        Bfs(i, dist[i], ways[i]);
    fill(res, res + n + 1, Inf); res[b] = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d %d", &qa[i], &qb[i]);
    for (int t = 0; t < n; t++) {
        fill((int*)val, (int*)val + Maxn * Maxn, 0);
        for (int i = 1; i <= n; i++)
            val[i][i] = res[i];
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < neigh[i].size(); j++) {
                int u = neigh[i][j];
                val[i][u] = min(res[i], res[u]);
            }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (dist[i][k] + dist[k][j] == dist[i][j])
                        val[i][j] = max(val[i][j], min(val[i][k], val[k][j]));
        for (int v = 1; v <= n; v++) if (res[v] >= Inf) {
            int nval = Inf;
            for (int i = 0; i < k; i++)
                if (dist[qa[i]][qb[i]] < Inf &&
                    dist[qa[i]][v] + dist[v][qb[i]] == dist[qa[i]][qb[i]] &&
                    ll(ways[qa[i]][v].first) * ways[v][qb[i]].first % mod1 == ways[qa[i]][qb[i]].first &&
                    ll(ways[qa[i]][v].second) * ways[v][qb[i]].second % mod2 == ways[qa[i]][qb[i]].second)
                    nval = min(nval, val[v][qb[i]]);
            res[v] = nval + 1;
        }
    }
    printf("%d\n", res[a] < Inf? res[a]: -1);
    return 0;
}