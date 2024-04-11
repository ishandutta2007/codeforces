#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n, m, a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        if (n * a != m * b) printf("NO\n");
        else {
            int B[Maxn][Maxn] = {};
            int col = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < a; j++) {
                    B[i][col] = 1;
                    col = (col + 1) % m;
                }
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    printf("%d", B[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}