#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, m;
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
                if ((B[i][j] % 2 != (i + j) % 2)) B[i][j]++;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                printf("%d%c", B[i][j], j + 1 < m? ' ': '\n');
    }
    return 0;
}