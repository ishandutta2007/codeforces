#include <cstdio>
using namespace std;

const int Maxn = 505;

int n, m;
int neigh[Maxn][Maxn];
int has[Maxn];

bool Ok(int v, int col)
{
    if (has[v] == -2) return true;
    if (has[v] && has[v] != col) return false;
    if (has[v]) return true;
    has[v] = col;
    for (int i = 1; i <= n; i++) if (v != i)
        if (neigh[v][i]) {
            if (!Ok(i, col)) return false;
        } else {
            if (!Ok(i, -col)) return false;
        }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a][b] = neigh[b][a] = true;
    }
    for (int i = 1; i <= n; i++) {
        bool h = false;
        for (int j = 1; j <= n; j++) if (!neigh[i][j] && i != j)
            h = true;
        if (!h) has[i] = -2;
    }
    for (int i = 1; i <= n; i++) if (!has[i])
        if (!Ok(i, -1)) { printf("No\n"); return 0; }
    printf("Yes\n");
    for (int i = 1; i <= n; i++)
        if (has[i] == -2) printf("b");
        else printf("%c", has[i] < 0? 'a': 'c');
    printf("\n");
    return 0;
}