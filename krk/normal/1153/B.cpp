#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, m, h;
int cols[Maxn];
int rows[Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &h);
    for (int j = 0; j < m; j++)
        scanf("%d", &cols[j]);
    for (int i = 0; i < n; i++)
        scanf("%d", &rows[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a; scanf("%d", &a);
            if (a > 0) a = min(rows[i], cols[j]);
            printf("%d%c", a, j + 1 < m? ' ': '\n');
        }
    return 0;
}