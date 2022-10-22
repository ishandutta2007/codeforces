#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef pair <iii, ii> i5;

const int Maxd = 4;
const int Maxp = 10;
const int Maxn = 1005;
const int Inf = 1000000000;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, p;
int s[Maxp];
char B[Maxn][Maxn];
iii dist[Maxn][Maxn];
int my[Maxp];

iii Neg(iii p)
{
    return iii(ii(-p.first.first, -p.first.second), -p.second);
}

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= p; i++)
        scanf("%d", &s[i]);
    fill((iii*)dist, (iii*)dist + Maxn * Maxn, iii(ii(Inf, 0), 0));
    priority_queue <i5> Q;
    for (int i = 0; i < n; i++) {
        scanf("%s", B[i]);
        for (int j = 0; j < m; j++)
            if (B[i][j] == '#' || B[i][j] == '.') ;
            else {
                int pl = B[i][j] - '0';
                dist[i][j] = iii(ii(-1, pl), 0);
                Q.push(i5(Neg(dist[i][j]), ii(i, j)));
                B[i][j] = '.';
            }
    }
    while (!Q.empty()) {
        ii v = Q.top().second;
        iii d = Neg(Q.top().first); Q.pop();
        if (dist[v.first][v.second] != d) continue;
        for (int j = 0; j < Maxd; j++) {
            ii u = ii(v.first + dy[j], v.second + dx[j]);
            if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m &&
                B[u.first][u.second] == '.') {
                iii cand = iii(ii(d.second / s[d.first.second], d.first.second), d.second + 1);
                if (cand < dist[u.first][u.second]) {
                    dist[u.first][u.second] = cand;
                    Q.push(i5(Neg(cand), u));
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (dist[i][j].first.first < Inf)
            my[dist[i][j].first.second]++;
    for (int i = 1; i <= p; i++)
        printf("%d%c", my[i], i + 1 <= p? ' ': '\n');
    return 0;
}