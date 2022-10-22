#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

struct pos {
    int r, c;
    bool ver;
    pos(int r = 0, int c = 0, bool ver = false): r(r), c(c), ver(ver) {}
};

int n, m;
char B[Maxn][Maxn];
int W[Maxn][Maxn], E[Maxn][Maxn], N[Maxn][Maxn], S[Maxn][Maxn];
int dist[Maxn][Maxn][2];
deque <pos> Q;

void checkPos(const pos &u, int d, bool ch)
{
    if (d + ch < dist[u.r][u.c][u.ver]) {
        dist[u.r][u.c][u.ver] = d + ch;
        if (ch) Q.push_back(u);
        else Q.push_front(u);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    B[1][0] = B[n][m + 1] = '#';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf(" %c", &B[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m + 1; j++) {
            if (i == 1) N[i][j] = -1;
            else if (B[i - 1][j] == '#') N[i][j] = i - 1;
            else N[i][j] = N[i - 1][j];
            if (j == 0) W[i][j] = -1;
            else if (B[i][j - 1] == '#') W[i][j] = j - 1;
            else W[i][j] = W[i][j - 1];
        }
    for (int i = n; i >= 1; i--)
        for (int j = m + 1; j >= 0; j--) {
            if (i == n) S[i][j] = -1;
            else if (B[i + 1][j] == '#') S[i][j] = i + 1;
            else S[i][j] = S[i + 1][j];
            if (j == m + 1) E[i][j] = -1;
            else if (B[i][j + 1] == '#') E[i][j] = j + 1;
            else E[i][j] = E[i][j + 1];
        }
    fill((int*)dist, (int*)dist + Maxn * Maxn * 2, Inf);
    dist[n][m + 1][0] = 0; Q.push_back(pos(n, m + 1, 0));
    while (!Q.empty()) {
        pos v = Q.front(); Q.pop_front(); int d = dist[v.r][v.c][v.ver];
        if (v.r == 1 && v.c == 0) { printf("%d\n", d); return 0; }
        if (N[v.r][v.c] != -1) {
            pos u = pos(N[v.r][v.c], v.c, 1);
            checkPos(u, d, !v.ver);
        }
        if (S[v.r][v.c] != -1) {
            pos u = pos(S[v.r][v.c], v.c, 1);
            checkPos(u, d, !v.ver);
        }
        if (W[v.r][v.c] != -1) {
            pos u = pos(v.r, W[v.r][v.c], 0);
            checkPos(u, d, v.ver);
        }
        if (E[v.r][v.c] != -1) {
            pos u = pos(v.r, E[v.r][v.c], 0);
            checkPos(u, d, v.ver);
        }
    }
    printf("-1\n");
    return 0;
}