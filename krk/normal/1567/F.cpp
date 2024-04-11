#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
int cid, comp[Maxn][Maxn];
vector <int> neigh[Maxm];
int col[Maxm];
int res[Maxn][Maxn];

void Fill(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == 'X' || comp[r][c]) return;
    comp[r][c] = cid;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            Fill(r + i, c + j);
}

void Colour(int v, int c)
{
    if (col[v]) return;
    col[v] = c;
    for (int i = 0; i < neigh[v].size(); i++)
        Colour(neigh[v][i], -c);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (B[i][j] == '.' && !comp[i][j]) {
                cid++;
                Fill(i, j);
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == 'X') {
                vector <int> un;
                for (int d = 0; d < Maxd; d++) {
                    int ni = i + dy[d], nj = j + dx[d];
                    if (B[ni][nj] == '.') un.push_back(comp[ni][nj]);
                }
                if (un.size() % 2) { printf("NO\n"); return 0; }
                res[i][j] = un.size() / 2 * 5;
                sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
                if (un.size() > 1) {
                    neigh[un[0]].push_back(un[1]);
                    neigh[un[1]].push_back(un[0]);
                }
            }
    for (int i = 1; i <= cid; i++) if (!col[i])
        Colour(i, -1);
    printf("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (B[i][j] == '.')
                res[i][j] = ((col[comp[i][j]] == 1) ^ (j % 2 == 1))? 1: 4;
            printf("%d%c", res[i][j], j + 1 < m? ' ': '\n');
        }
    return 0;
}