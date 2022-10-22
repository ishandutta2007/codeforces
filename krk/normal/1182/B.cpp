#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n, m;
char B[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < m; j++)
            if (B[i][j] == '*' &&
                B[i - 1][j] == '*' && B[i + 1][j] == '*' &&
                B[i][j - 1] == '*' && B[i][j + 1] == '*') {
                B[i][j] = '.';
                for (int j1 = j - 1; j1 >= 0; j1--)
                    if (B[i][j1] == '*') B[i][j1] = '.';
                    else break;
                for (int j2 = j + 1; j2 < m; j2++)
                    if (B[i][j2] == '*') B[i][j2] = '.';
                    else break;
                for (int i1 = i - 1; i1 >= 0; i1--)
                    if (B[i1][j] == '*') B[i1][j] = '.';
                    else break;
                for (int i2 = i + 1; i2 < n; i2++)
                    if (B[i2][j] == '*') B[i2][j] = '.';
                    else break;
                bool ok = true;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (B[i][j] == '*') ok = false;
                printf("%s\n", ok? "YES": "NO");
                return 0;
            }
    printf("NO\n");
    return 0;
}