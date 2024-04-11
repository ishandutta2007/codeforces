#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
char R[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", B[i]);
        fill(R[i], R[i] + m, '.');
    }
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < m; j++) {
            bool ok = true;
            for (int ni = i - 1; ni <= i + 1 && ok; ni++)
                for (int nj = j - 1; nj <= j + 1 && ok; nj++) if (ni != i || nj != j)
                    ok = B[ni][nj] == '#';
            if (ok)
                for (int ni = i - 1; ni <= i + 1; ni++)
                    for (int nj = j - 1; nj <= j + 1; nj++) if (ni != i || nj != j)
                        R[ni][nj] = '#';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (R[i][j] != B[i][j]) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}