#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 +  10 ;
int const N = 1 << 10;
const int inf = 1e9;
const int K = 41;
int dist[N][N][K];
int a[N][N];
int n, m, k;
pair <int, int> q[nax];
int cost[K][K];
vector <pair <int, int>> col[K];

void bfs (int color) {
    int topQ = 0;

    static bool vis[N][N];
    static bool done[K];
    memset(done, false, sizeof(cost));
    done[color] = true;

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        if (a[i][j] != color) {
            dist[i][j][color] = nax;
            vis[i][j] = false;
        } else {
            dist[i][j][color] = 0;
            q[topQ ++] = {i, j};
            vis[i][j] = true;
        }
    }


    for (int g = 0 ; g < topQ ; ++ g) {
        auto [x, y] = q[g];

        if  (!done[a[x][y]]) {
            int c = a[x][y];
            done[c] = true;
            for (auto &[u, v] : col[c]) {
                if (!vis[u][v]) {
                    q[topQ ++] = {u, v};
                    dist[u][v][color] = dist[x][y][color] + 1;
                    vis[u][v] = true;
                }
            }
        }

        if (x > 1 && !vis[x - 1][y]) {
            dist[x - 1][y][color] = dist[x][y][color] + 1;
            q[topQ ++] = {x - 1, y};
            vis[x - 1][y] = true;
        }

        if (x + 1 <= n && !vis[x + 1][y]) {
            dist[x + 1][y][color] = dist[x][y][color] + 1;
            q[topQ ++] = {x + 1, y};
            vis[x + 1][y] = true;
        }

        if (y > 1 && !vis[x][y - 1]) {
            dist[x][y - 1][color] = dist[x][y][color] + 1;
            q[topQ ++] = {x, y - 1};
            vis[x][y - 1] = true;
        }

        if (y + 1 <= m && !vis[x][y + 1]) {
            dist[x][y + 1][color] = dist[x][y][color] + 1;
            q[topQ ++] = {x, y + 1};
            vis[x][y + 1] = true;
        }
    }

}



int main () {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j)
        scanf("%d", &a[i][j]), col[a[i][j]].emplace_back(i, j);

    for (int i = 1 ; i <= k; ++ i)
        bfs(i);



    int nq;
    scanf("%d", &nq);

    for (; nq -- ; ) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int ans = nax + nax;

        for (int i = 1 ; i <= k ; ++ i) {
            ans = min(ans, dist[r1][c1][i] + dist[r2][c2][i] + 1);
        }

        ans = min(ans, abs(r1 - r2) + abs(c1 - c2));
        printf("%d\n", ans);
    }
}
/*
    Good Luck
        -Lucina
*/