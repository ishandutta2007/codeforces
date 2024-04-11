#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 42;
const int Maxd = 8;
const int dy[Maxd] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dx[Maxd] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct pos {
    int r[2], c[2];
    int wh;
    pos(int A = 0, int B = 0, int C = 0, int D = 0, int E = 0) {
        r[0] = A; c[0] = B;
        r[1] = C; c[1] = D;
        wh = E;
    }
};

int n, m;
int ways[Maxn][Maxn];
ii dp[Maxn][Maxn][Maxn][Maxn][2];
int lft[Maxn][Maxn][Maxn][Maxn][2];
pos p;

pos getPos(int mask)
{
    pos p;
    p.wh = mask % 2; mask /= 2;
    p.c[1] = mask % m; mask /= m;
    p.r[1] = mask % n; mask /= n;
    p.c[0] = mask % m; mask /= m;
    p.r[0] = mask;
    return p;
}

int getMask(const pos &p)
{
    int res = 0;
    res += p.r[0]; res *= m;
    res += p.c[0]; res *= n;
    res += p.r[1]; res *= m;
    res += p.c[1]; res *= 2;
    res += p.wh;
    return res;
}

bool Inside(int r, int c) { return 0 <= r && r < n && 0 <= c && c < m; }

void Read(int &r, int &c)
{
    scanf("%d %d", &r, &c); r--; c--;
}

void Print(int r, int c)
{
    printf("%d %d\n", r + 1, c + 1); fflush(stdout);
}

bool Move()
{
    pos u = p;
    int got = dp[p.r[0]][p.c[0]][p.r[1]][p.c[1]][p.wh].second;
    for (int d = 0; d < Maxd; d++) {
        u.r[p.wh] = p.r[p.wh] + dy[d];
        u.c[p.wh] = p.c[p.wh] + dx[d];
        if (Inside(u.r[p.wh], u.c[p.wh])) {
            u.wh = 1 - p.wh;
            if (dp[u.r[0]][u.c[0]][u.r[1]][u.c[1]][u.wh].first == -1 &&
                dp[u.r[0]][u.c[0]][u.r[1]][u.c[1]][u.wh].second == got - 1) {
                Print(u.r[p.wh], u.c[p.wh]);
                p.r[p.wh] = u.r[p.wh]; p.c[p.wh] = u.c[p.wh];
                break;
            }
        }
    }
    return got == 1;
}


int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < Maxd; d++)
                ways[i][j] += Inside(i + dy[d], j + dx[d]);
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            for (int c = 0; c < n; c++)
                for (int d = 0; d < m; d++)
                    for (int e = 0; e < 2; e++)
                        lft[a][b][c][d][e] = e == 0? ways[a][b]: ways[c][d];
    vector <int> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int e = 0; e < 2; e++) {
                dp[i][j][i][j][e] = ii(-1, 0);
                Q.push_back(getMask(pos(i, j, i, j, e)));
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (dp[n / 2 - 1][m / 2 - 1][i][j][0].first == 0) {
            int a = abs(n / 2 - 1 - i);
            int b = abs(m / 2 - 1 - j);
            if (a > b) swap(a, b);
            if (a == 1 && b == 2) ;
            else {
                dp[n / 2 - 1][m / 2 - 1][i][j][1] = ii(-1, 0);
                Q.push_back(getMask(pos(n / 2 - 1, m / 2 - 1, i, j, 1)));
            }
            dp[n / 2 - 1][m / 2 - 1][i][j][0] = ii(1, 0);
            Q.push_back(getMask(pos(n / 2 - 1, m / 2 - 1, i, j, 0)));
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (dp[i][j][n / 2][m / 2 - 1][1].first == 0) {
            int a = abs(n / 2 - i);
            int b = abs(m / 2 - 1 - j);
            if (a > b) swap(a, b);
            if (a == 1 && b == 2) ;
            else {
                dp[i][j][n / 2][m / 2 - 1][0] = ii(-1, 0);
                Q.push_back(getMask(pos(i, j, n / 2, m / 2 - 1, 0)));
            }
            dp[i][j][n / 2][m / 2 - 1][1] = ii(1, 0);
            Q.push_back(getMask(pos(i, j, n / 2, m / 2 - 1, 1)));
        }
    for (int i = 0; i < Q.size(); i++) {
        pos p = getPos(Q[i]);
        ii my = dp[p.r[0]][p.c[0]][p.r[1]][p.c[1]][p.wh];
        int d = my.second;
        pos u = p; u.wh = 1 - p.wh;
        for (int j = 0; j < Maxd; j++) {
            u.r[u.wh] = p.r[u.wh] + dy[j];
            u.c[u.wh] = p.c[u.wh] + dx[j];
            if (Inside(u.r[u.wh], u.c[u.wh]) && dp[u.r[0]][u.c[0]][u.r[1]][u.c[1]][u.wh].first == 0)
                if (my.first == -1) {
                    dp[u.r[0]][u.c[0]][u.r[1]][u.c[1]][u.wh] = ii(1, d + 1);
                    Q.push_back(getMask(u));
                } else if (--lft[u.r[0]][u.c[0]][u.r[1]][u.c[1]][u.wh] == 0) {
                    dp[u.r[0]][u.c[0]][u.r[1]][u.c[1]][u.wh] = ii(-1, d + 1);
                    Q.push_back(getMask(u));
                }
        }
    }
    Read(p.r[0], p.c[0]);
    Read(p.r[1], p.c[1]);
    p.wh = 0;
    assert(dp[p.r[0]][p.c[0]][p.r[1]][p.c[1]][p.wh].first != 0);
    if (dp[p.r[0]][p.c[0]][p.r[1]][p.c[1]][p.wh].first == 1) {
        printf("WHITE\n");
        p.wh = 0;
        if (Move()) return 0;
    } else {
        printf("BLACK\n");
        p.wh = 1;
    }
    fflush(stdout);
    while (true) {
        Read(p.r[1 - p.wh], p.c[1 - p.wh]);
        if (Move()) break;
    }
    return 0;
}