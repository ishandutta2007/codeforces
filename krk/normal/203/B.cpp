#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n, m;
bool bl[Maxn][Maxn];

bool hasBlack(int r, int c)
{
    if (r < 0 || c < 0 || r + 2 > n || c + 2 > n) return false;
    for (int i = r; i <= r + 2; i++)
        for (int j = c; j <= c + 2; j++) if (!bl[i][j]) return false;
    return true;
}

bool Check(int r, int c)
{
    for (int i = r - 2; i <= r; i++)
        for (int j = c - 2; j <= c; j++)
            if (hasBlack(i, j)) return true;
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    int i;
    for (i = 1; i <= m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        bl[x][y] = true;
        if (Check(x, y)) break;
    }
    printf("%d\n", i <= m? i: -1);
    return 0;
}