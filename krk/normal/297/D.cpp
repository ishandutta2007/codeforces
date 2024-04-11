#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m, k;
char V[Maxn][Maxn], H[Maxn][Maxn];
int R[Maxn][Maxn];

void enterRow(int r)
{
    R[r][0] = 0;
    for (int j = 1; j < m; j++)
        if (V[r][j - 1] == 'E') R[r][j] = R[r][j - 1];
        else R[r][j] = 1 - R[r][j - 1];
}

void enterCol(int c)
{
    R[0][c] = 0;
    for (int i = 1; i < n; i++)
        if (H[i - 1][c] == 'E') R[i][c] = R[i - 1][c];
        else R[i][c] = 1 - R[i - 1][c];
}

void fixRow(int r)
{
    int ok = 0, notok = 0;
    for (int j = 0; j < m; j++)
        if ((H[r - 1][j] == 'E') == (R[r - 1][j] == R[r][j]))
            ok++;
        else notok++;
    if (notok > ok)
        for (int j = 0; j < m; j++)
            R[r][j] = 1 - R[r][j];
}

void fixCol(int c)
{
    int ok = 0, notok = 0;
    for (int i = 0; i < n; i++)
        if ((V[i][c - 1] == 'E') == (R[i][c - 1] == R[i][c]))
            ok++;
        else notok++;
    if (notok > ok)
        for (int i = 0; i < n; i++)
            R[i][c] = 1 - R[i][c];
}

int main()
{
    int cnte = 0, all = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            scanf(" %c", &V[i][j]);
            cnte += V[i][j] == 'E';
            all++;
        }
        for (int j = 0; j < m; j++) {
            scanf(" %c", &H[i][j]);
            cnte += H[i][j] == 'E';
            all++;
        }
    }
    for (int j = 0; j < m - 1; j++) {
        scanf(" %c", &V[n - 1][j]);
        cnte += V[n - 1][j] == 'E';
        all++;
    }
    if (k == 1) {
        if (4 * cnte >= 3 * all) {
            printf("YES\n");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    printf("1%c", j + 1 < m? ' ': '\n');
        } else printf("NO\n");
        return 0;
    }
    if (n * (m - 1) >= (n - 1) * m) {
        enterRow(0);
        for (int i = 1; i < n; i++) {
            enterRow(i);
            fixRow(i);
        }
    } else {
        enterCol(0);
        for (int j = 1; j < m; j++) {
            enterCol(j);
            fixCol(j);
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%c", R[i][j] + 1, j + 1 < m? ' ': '\n');
    return 0;
}