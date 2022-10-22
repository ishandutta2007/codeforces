#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Inf = 1000000000;
const int Maxd = 4;
const int dy[Maxd] = {-1, 1, 0, 0};
const int dx[Maxd] = {0, 0, -1, 1};
const int cost[Maxd] = {0, 0, 1, 1};

int n, m;
int r, c;
int x, y;
char B[Maxn][Maxn];
int dist[Maxn][Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d", &r, &c);
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= n; i++)
        scanf("%s", B[i] + 1);
    fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
    dist[r][c] = 0;
    deque <ii> Q; Q.push_back(ii(r, c));
    while (!Q.empty()) {
        ii v = Q.front(); Q.pop_front();
        for (int j = 0; j < Maxd; j++) {
            ii u = ii(v.first + dy[j], v.second + dx[j]);
            if (1 <= u.first && u.first <= n && 1 <= u.second && u.second <= m &&
                B[u.first][u.second] == '.') {
                int cand = dist[v.first][v.second] + cost[j];
                if (cand < dist[u.first][u.second]) {
                    dist[u.first][u.second] = cand;
                    if (cost[j]) Q.push_back(u);
                    else Q.push_front(u);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (dist[i][j] < Inf) {
            int mid = (dist[i][j] - abs(j - c)) / 2;
            int lef = mid, rig = mid;
            if (j < c) lef += dist[i][j] - 2 * mid;
            else rig += dist[i][j] - 2 * mid;
            if (lef <= x && rig <= y)
                res++;
        }
    printf("%d\n", res);
    return 0;
}