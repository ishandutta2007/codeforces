#include <bits/stdc++.h>
using namespace std;
int n, m, k, fa[250005] = {0}, size[250005] = {0}, nm, sizei[250005] = {0}, size0 = 0;
bool flag[250005] = {false}, gone[505][505] = {{false}};
char s[505][505] = {{'\0'}};
int findfa(int x)
{
    int now = x, tmp;
    while (fa[x] != x) x = fa[x];
    while (now != x)
    {
        tmp = fa[now];
        fa[now] = x;
        now = tmp;
    }
    return x;
}
void addedge(int x, int y)
{
    static int fax, fay;
    fax = findfa(x);
    fay = findfa(y);
    if (fax != fay)
    {
        fa[fax] = fay;
        size[fay] += size[fax];
        size[fax] = 0;
    }
}
void dfs(int x, int y)
{
    gone[x][y] = true;
    int flagg = 0;
    if (x > 0 && s[x - 1][y] == '.' && !gone[x - 1][y])
    {
        flagg++;
        dfs(x - 1, y);
        if (s[x - 1][y] == 'X') flagg--;
        if (k <= 0) return;
    }
    if (x < n - 1 && s[x + 1][y] == '.' && !gone[x + 1][y])
    {
        flagg++;
        dfs(x + 1, y);
        if (s[x + 1][y] == 'X') flagg--;
        if (k <= 0) return;
    }
    if (y > 0 && s[x][y - 1] == '.' && !gone[x][y - 1])
    {
        flagg++;
        dfs(x, y - 1);
        if (s[x][y - 1] == 'X') flagg--;
        if (k <= 0) return;
    }
    if (y < m - 1 && s[x][y + 1] == '.' && !gone[x][y + 1])
    {
        flagg++;
        dfs(x, y + 1);
        if (s[x][y + 1] == 'X') flagg--;
        if (k <= 0) return;
    }
    if (flagg == 0)
    {
        s[x][y] = 'X';
        k--;
    }
}
bool cmp(int x, int y){return size[x] < size[y];}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    nm = n * m;
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < nm; i++) fa[i] = i, size[i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            if (s[i][j - 1] == '.' && s[i][j] == '.')
                addedge(i * m + j - 1, i * m + j);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i - 1][j] == '.' && s[i][j] == '.')
                addedge((i - 1) * m + j, i * m + j);
    for (int i = 0; i < nm; i++) findfa(i);
    for (int i = 0; i < nm; i++)
        if (s[i / m][i % m] == '.' && fa[i] == i)
            sizei[++size0] = i;
    sort(sizei + 1, sizei + size0 + 1, cmp);
    for (int i = 1; i < size0; i++) k -= size[sizei[i]];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.' && fa[i * m + j] != sizei[size0])
                s[i][j] = 'X';
    if (k)
    {
        for (int i = 0; i < n && k > 0; i++)
            for (int j = 0; j < m && k > 0; j++)
                if (s[i][j] == '.' && fa[i * m + j] == i * m + j)
                    dfs(i, j);
    }
    for (int i = 0; i < n; i++) puts(s[i]);
}