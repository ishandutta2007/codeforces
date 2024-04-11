#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[301][301], b[301][301];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        bool ok = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                b[i][j] = 4;
                if (i == 1)
                    --b[i][j];
                if (i == n)
                    --b[i][j];
                if (j == 1)
                    --b[i][j];
                if (j == m)
                    --b[i][j];
                if (a[i][j] > b[i][j])
                    ok = false;
            }
        if (!ok)
            printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                    printf("%d ", b[i][j]);
                printf("\n");
            }
        }
    }
}