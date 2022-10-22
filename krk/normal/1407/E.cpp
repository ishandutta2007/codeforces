#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;
const int Inf = 1000000000;

int n, m;
vector <ii> neigh[Maxn];
int dist[Maxn][2];
vector <ii> Q;
char str[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, t; scanf("%d %d %d", &u, &v, &t);
        neigh[v].push_back(ii(u, t));
    }
    fill((int*)dist, (int*)dist + Maxn * 2, Inf);
    dist[n][0] = dist[n][1] = 0;
    Q.push_back(ii(n, 0));
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i].first, d = Q[i].second;
        for (int j = 0; j < neigh[v].size(); j++) {
            ii u = neigh[v][j];
            if (d + 1 < dist[u.first][u.second]) {
                dist[u.first][u.second] = d + 1;
                if (dist[u.first][1 - u.second] <= dist[u.first][u.second])
                    Q.push_back(ii(u.first, d + 1));
            }
        }
    }
    int res = max(dist[1][0], dist[1][1]);
    printf("%d\n", res < Inf? res: -1);
    for (int i = 1; i <= n; i++)
        str[i - 1] = dist[i][0] >= dist[i][1]? '0': '1';
    str[n] = '\0';
    printf("%s\n", str);
    return 0;
}