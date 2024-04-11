#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 305;
const int Maxm = 4100005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, q;
vector <ii> B[Maxn][Maxn];
vector <ii> my[Maxn][Maxn];
int cur, par[Maxm], siz[Maxm];
int comp;
int delt[Maxm];
int qx[Maxm], qy[Maxm];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    comp--;
}

void addNeighbours(int r, int c)
{
    for (int i = 0; i < Maxd; i++) {
        int nr = r + dy[i], nc = c + dx[i];
        if (1 <= nr && nr <= n && 1 <= nc && nc <= m && B[nr][nc].back().second == B[r][c].back().second)
            unionSet(my[nr][nc].back().second, my[r][c].back().second);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            B[i][j].push_back(ii(0, 0));
            int v = cur++;
            par[v] = v; siz[v] = 1;
            comp++;
            my[i][j].push_back(ii(0, v));
            if (i > 1) unionSet(my[i][j].back().second, my[i - 1][j].back().second);
            if (j > 1) unionSet(my[i][j].back().second, my[i][j - 1].back().second);
        }
    delt[0]++;
    for (int i = 1; i <= q; i++) {
        int x, y, c; scanf("%d %d %d", &x, &y, &c);
        qx[i] = x; qy[i] = y;
        if (c > B[x][y].back().second) {
            B[x][y].push_back(ii(i, c));
            int oldcomp = comp;
            int v = cur++;
            par[v] = v; siz[v] = 1;
            comp++;
            my[x][y].push_back(ii(i, v));
            addNeighbours(x, y);
            delt[i] += comp - oldcomp;
        }
    }
    for (int i = 0; i < cur; i++) {
        par[i] = i; siz[i] = 1;
    }
    comp = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            comp++;
            if (i > 1 && B[i][j].back().second == B[i - 1][j].back().second)
                unionSet(my[i][j].back().second, my[i - 1][j].back().second);
            if (j > 1 && B[i][j].back().second == B[i][j - 1].back().second)
                unionSet(my[i][j].back().second, my[i][j - 1].back().second);
        }
    for (int i = q; i > 0; i--) {
        int x = qx[i], y = qy[i];
        if (B[x][y].back().first == i) {
            B[x][y].pop_back();
            my[x][y].pop_back();
            int oldcomp = comp;
            comp++;
            addNeighbours(x, y);
            delt[i] -= comp - oldcomp;
        }
    }
    int sum = delt[0];
    for (int i = 1; i <= q; i++) {
        sum += delt[i];
        printf("%d\n", sum);
    }
    return 0;
}