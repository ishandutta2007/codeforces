#include <cstdio>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;
const int Maxl = 26;
const int Inf = 1000000000;

int n, m;
char B[Maxn][Maxn];
int l[Maxl], r[Maxl];
int res[Maxn][Maxl][Maxl];
ii p[Maxn][Maxl][Maxl];

int main()
{
    fill((int*)res, (int*)res + Maxn * Maxl * Maxl, Inf);
    fill((int*)res[0], (int*)res[0] + Maxl * Maxl, 0);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf(" %c", &B[i][j]);
        for (int j = 0; j < Maxl; j++) {
            l[j] = r[j] = 0;
            for (int k = 0; k < m; k++) {
                l[j] += k % 2 == 0 && j + 'a' != B[i][k];
                r[j] += k % 2 && j + 'a' != B[i][k];
            }
        }
        for (int j = 0; j < Maxl; j++)
            for (int k = 0; k < Maxl; k++) if (res[i][j][k] != Inf)
                for (int j2 = 0; j2 < Maxl; j2++) if (j != j2)
                    for (int k2 = 0; k2 < Maxl; k2++) if (k != k2 && j2 != k2) {
                        int cand = res[i][j][k] + l[j2] + r[k2];
                        if (cand < res[i + 1][j2][k2]) {
                                 res[i + 1][j2][k2] = cand;
                                 p[i + 1][j2][k2] = mp(j, k);
                        }
                    }
    }
    ii v = mp(0, 0);
    for (int i = 0; i < Maxl; i++)
        for (int j = 0; j < Maxl; j++) 
            if (res[n][i][j] < res[n][v.first][v.second]) v = mp(i, j);
    printf("%d\n", res[n][v.first][v.second]);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) B[i][j] = j % 2? v.second + 'a': v.first + 'a';
        v = p[i + 1][v.first][v.second];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%c", B[i][j]);
        printf("\n");
    }
    return 0;
}