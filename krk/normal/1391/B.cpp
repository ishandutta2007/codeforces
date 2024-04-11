#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, m;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", B[i]);
        int res = 0;
        for (int j = 0; j + 1 < m; j++)
            res += B[n - 1][j] != 'R';
        for (int i = 0; i + 1 < n; i++)
            res += B[i][m - 1] != 'D';
        printf("%d\n", res);
    }
    return 0;
}