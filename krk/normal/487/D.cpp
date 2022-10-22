#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 12;
const int Maxp = 320;

int n, m, q;
char B[Maxn][Maxm];
ii goesto[Maxn][Maxm];

ii getLeft(int r, int c)
{
    if (c == 0) return ii(r, c - 1);
    return goesto[r][c - 1];
}

ii getRight(int r, int c)
{
    if (c == m - 1) return ii(r, c + 1);
    return goesto[r][c + 1];
}

ii getUp(int r, int c)
{
    if (r % Maxp == 0) return ii(r - 1, c);
    return goesto[r - 1][c];
}

void splitRight(int r, int c, ii give)
{
    for (c++; c < m && B[r][c] == '<'; c++)
        goesto[r][c] = give;
}

void splitLeft(int r, int c, ii give)
{
    for (c--; c >= 0 && B[r][c] == '>'; c--)
        goesto[r][c] = give;
}

void solveRow(int i)
{
    for (int j = 0; j < m; j++)
        goesto[i][j] = ii(-2, -2);
    splitRight(i, -1, ii(i, -1));
    for (int j = 0; j < m; j++)
        if (B[i][j] == '^') {
            goesto[i][j] = getUp(i, j);
            splitLeft(i, j, goesto[i][j]);
            splitRight(i, j, goesto[i][j]);
        }
    splitLeft(i, m, ii(i, m));
}

void changeBelt(int r, int c, char ch)
{
    B[r][c] = ch;
    int p = r / Maxp;
    int from = p * Maxp, to = min(n, (p + 1) * Maxp);
    for (int i = from; i < to; i++)
        solveRow(i);
}

ii getAns(int r, int c)
{
    ii cur = ii(r, c);
    while (cur.first >= 0 && cur.second >= 0 && cur.second < m)
        cur = goesto[cur.first][cur.second];
    return cur;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf("%s", B[i]);
        solveRow(i);
    }
    while (q--) {
        char typ, ch;
        int x, y;
        scanf(" %c %d %d", &typ, &x, &y); x--; y--;
        if (typ == 'C') {
            scanf(" %c", &ch);
            changeBelt(x, y, ch);
        } else {
            ii res = getAns(x, y); res.first++; res.second++;
            printf("%d %d\n", res.first, res.second);
        }
    }
    return 0;
}