#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 5;
const int Maxm = 20;

int n, m;
int a[Maxn], b[Maxm];
char B[Maxn][Maxm];
int has[Maxm];
bool gotres;

void Print()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%c", B[i][j]);
        printf("\n");
    }
}

bool checkRow(int r, int c, bool lst, int hasline, int wr)
{
    if (!lst && wr) hasline++;
    if (hasline > a[r]) return false;
    if (hasline < a[r]) {
        int lft = m - c - wr;
        return lft >= 0 && hasline + lft / 2 >= a[r];
    }
    return true;
}

bool checkCol(int r, int c, int wr)
{
    int hascol = has[c];
    if ((r == 0 || B[r - 1][c] == '.') && wr) hascol++;
    if (hascol > b[c]) return false;
    if (hascol < b[c]) {
        int lft = n - r - wr;
        return lft >= 0 && hascol + lft / 2 >= b[c];
    }
    return true;
}

void changeRow(int r, int c, bool &lst, int &hasline, int wr)
{
    if (!lst && wr) hasline++;
    lst = wr;
}

void changeCol(int r, int c, int wr)
{
    if ((r == 0 || B[r - 1][c] == '.') && wr) has[c]++;
}

void Solve(int r, int c, bool lst, int hasline)
{
    if (r == n) { Print(); gotres = true; return; }
    if (c == m) { Solve(r + 1, 0, false, 0); return; }
    if (checkRow(r, c, lst, hasline, 0) && checkCol(r, c, 0)) {
        bool memlst = lst; int memhasline = hasline;
        int memhas = has[c];
        changeRow(r, c, lst, hasline, 0); changeCol(r, c, 0);
        B[r][c] = '.';
        Solve(r, c + 1, lst, hasline);
        lst = memlst; hasline = memhasline;
        has[c] = memhas;
    }
    if (gotres) return;
    if (checkRow(r, c, lst, hasline, 1) && checkCol(r, c, 1)) {
        bool memlst = lst; int memhasline = hasline;
        int memhas = has[c];
        changeRow(r, c, lst, hasline, 1); changeCol(r, c, 1);
        B[r][c] = '*';
        Solve(r, c + 1, lst, hasline);
        lst = memlst; hasline = memhasline;
        has[c] = memhas;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    Solve(0, 0, false, 0);
    return 0;
}