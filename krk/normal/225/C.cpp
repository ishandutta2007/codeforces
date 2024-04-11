#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m, x, y;
char B[Maxn][Maxn];
int bcost[Maxn], wcost[Maxn];
int bbest[Maxn], wbest[Maxn];

int main()
{
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", &B[i][j]);
            bcost[j + 1] += B[i][j] == '.';
            wcost[j + 1] += B[i][j] == '#';
        }
    for (int i = 1; i <= m; i++) {
        bcost[i] += bcost[i - 1];
        wcost[i] += wcost[i - 1];
    }
    bbest[0] = 0; fill(bbest + 1, bbest + Maxn, Maxn * Maxn);
    wbest[0] = 0; fill(wbest + 1, wbest + Maxn, Maxn * Maxn);
    for (int i = 1; i <= m; i++)
        for (int j = max(0, i - y); j <= i - x; j++) {
            bbest[i] = min(bbest[i], wbest[j] + bcost[i] - bcost[j]);
            wbest[i] = min(wbest[i], bbest[j] + wcost[i] - wcost[j]);
        }
    printf("%d\n", min(bbest[m], wbest[m]));
    return 0;
}