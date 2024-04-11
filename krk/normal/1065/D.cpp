#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 11;
const int Maxm = Maxn * Maxn;
const int Maxd = 8;
const int dy[Maxd] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dx[Maxd] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int Inf = 1000000000;

struct pos {
    int ind, r, c, piece;
};

int n;
int B[Maxn][Maxn];
ii dist[Maxm][Maxn][Maxn][3];
int sx, sy;
priority_queue <iii> Q;

int Encode(const pos &p)
{
    int res = p.ind;
    res = res * Maxn + p.r;
    res = res * Maxn + p.c;
    res = res * 3 + p.piece;
    return res;
}

pos Decode(int v)
{
    pos p;
    p.piece = v % 3; v /= 3;
    p.c = v % Maxn; v /= Maxn;
    p.r = v % Maxn; v /= Maxn;
    p.ind = v;
    return p;
}

void tryAll(int wh, int curx, int cury, int deltx, int delty, int piece, ii cand)
{
    if (curx < 0 || curx >= n || cury < 0 || cury >= n) return;
    int nwh = B[curx][cury] == wh? wh + 1: wh;
    if (cand < dist[nwh][curx][cury][piece]) {
        dist[nwh][curx][cury][piece] = cand;
        Q.push(iii(ii(-cand.first, -cand.second), Encode({nwh, curx, cury, piece})));
    }
    tryAll(wh, curx + deltx, cury + delty, deltx, delty, piece, cand);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            if (B[i][j] == 1) { sx = i; sy = j; }
        }
    fill((ii*)dist, (ii*)dist + Maxm * Maxn * Maxn * 3, ii(Inf, Inf));
    for (int i = 0; i < 3; i++) {
        dist[2][sx][sy][i] = ii(0, 0);
        Q.push(iii(ii(0, 0), Encode({2, sx, sy, i})));
    }
    while (!Q.empty()) {
        pos p = Decode(Q.top().second);
        ii d = Q.top().first; d = ii(-d.first, -d.second); Q.pop();
        if (d != dist[p.ind][p.r][p.c][p.piece]) continue;
        if (p.ind > n * n) {
            printf("%d %d\n", d.first, d.second);
            break;
        }
        for (int j = 0; j < 3; j++) {
            ii cand = ii(d.first + 1, d.second + 1);
            pos u = {p.ind, p.r, p.c, j};
            if (cand < dist[u.ind][u.r][u.c][u.piece]) {
                dist[u.ind][u.r][u.c][u.piece] = cand;
                Q.push(iii(ii(-cand.first, -cand.second), Encode(u)));
            }
        }
        ii cand = ii(d.first + 1, d.second);
        if (p.piece == 0) {
            tryAll(p.ind, p.r, p.c, -1, -1, 0, cand);
            tryAll(p.ind, p.r, p.c, -1, 1, 0, cand);
            tryAll(p.ind, p.r, p.c, 1, -1, 0, cand);
            tryAll(p.ind, p.r, p.c, 1, 1, 0, cand);
        } else if (p.piece == 1) {
            tryAll(p.ind, p.r, p.c, 1, 0, 1, cand);
            tryAll(p.ind, p.r, p.c, -1, 0, 1, cand);
            tryAll(p.ind, p.r, p.c, 0, -1, 1, cand);
            tryAll(p.ind, p.r, p.c, 0, 1, 1, cand);
        } else for (int z = 0; z < Maxd; z++) {
            pos u = {p.ind, p.r + dx[z], p.c + dy[z], 2};
            if (u.r < 0 || u.r >= n || u.c < 0 || u.c >= n) continue;
            if (B[u.r][u.c] == u.ind) u.ind++;
            if (cand < dist[u.ind][u.r][u.c][u.piece]) {
                dist[u.ind][u.r][u.c][u.piece] = cand;
                Q.push(iii(ii(-cand.first, -cand.second), Encode(u)));
            }
        }
    }
    return 0;
}