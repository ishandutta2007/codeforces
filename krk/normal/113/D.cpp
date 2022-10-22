#include <bits/stdc++.h>
using namespace std;

const int Maxs = 300;
const int Maxn = 25;
const double eps = 1e-9;

int n, m, a, b;
vector <int> neigh[Maxn];
double prob[Maxn];
double nxt[Maxn][Maxn];
int s, my[Maxn][Maxn];
double B[Maxs][Maxs];
double res[Maxs];

void Swap(int r1, int r2)
{
    for (int j = r1; j <= s; j++)
        swap(B[r1][j], B[r2][j]);
}

void Rem(int r1, int r2)
{
    if (fabs(B[r2][r1]) < eps) return;
    double mult = B[r2][r1] / B[r1][r1];
    for (int j = r1; j <= s; j++)
        B[r2][j] -= B[r1][j] * mult;
}

int Get(int a, int b)
{
    if (a > b) swap(a, b);
    return my[a][b];
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &prob[i]);
        nxt[i][i] = prob[i];
        double oth = (1.0l - prob[i]) / double(neigh[i].size());
        for (int j = 0; j < neigh[i].size(); j++)
            nxt[i][neigh[i][j]] = oth;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            my[i][j] = s++;
            B[my[i][j]][my[i][j]] = 1;
        }
    B[Get(a, b)][s] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            double myself = 0;
            for (int a = 1; a <= n; a++)
                for (int b = 1; b <= n; b++)
                    if (Get(i, j) == Get(a, b))
                        myself += nxt[i][a] * nxt[j][b];
            double dv = 1 - myself;
            for (int a = 1; a <= n; a++)
                for (int b = 1; b <= n; b++)
                    if (Get(i, j) != Get(a, b))
                        B[Get(a, b)][Get(i, j)] -= nxt[i][a] * nxt[j][b] / dv;
        }
    for (int i = 0; i < s; i++) {
        int row = i;
        while (row < s && fabs(B[row][i]) < eps)
            row++;
        assert(row < s);
        if (i != row)
            Swap(i, row);
        for (int i2 = row + 1; i2 < s; i2++)
            Rem(i, i2);
    }
    for (int i = s - 1; i >= 0; i--) {
        double cur = B[i][s];
        for (int j = i + 1; j < s; j++)
            cur -= res[j] * B[i][j];
        res[i] = cur / B[i][i];
    }
    for (int i = 1; i <= n; i++)
        printf("%.8f%c", res[my[i][i]], i + 1 <= n? ' ': '\n');
    return 0;
}