#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

char B[Maxn][Maxn];
int T;
int n, m, k;

void Print(bool val)
{
    printf("%s\n", val? "YES": "NO");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        bool got;
        if (n % 2 == 0 && m % 2 == 0) got = k % 2 == 0;
        else if (n % 2 == 1) got = k >= m / 2 && k % 2 == m / 2 % 2;
        else got = k <= n * (m - 1) / 2 && k % 2 == n * (m - 1) / 2 % 2;
        Print(got);
        if (!got) continue;
        fill((char*)B, (char*)B + Maxn * Maxn, '.');
        if (n % 2) {
            char x = 'x', y = 'y';
            for (int j = 0; j + 1 < m; j += 2) {
                B[n - 1][j] = B[n - 1][j + 1] = x;
                swap(x, y);
                k--;
            }
        }
        int pnt = 0;
        for (int j = 0; j + 1 < m; j += 2)
            for (int i = 0; i < n; i++) if (B[i][j] == '.' && k > 0) {
                if (j > 0 && B[i][j - 1] == 'a' + pnt) pnt = (pnt + 1) % 3;
                B[i][j] = B[i][j + 1] = 'a' + pnt;
                pnt = (pnt + 1) % 3;
                k--;
            }
        pnt = 0;
        for (int i = 0; i + 1 < n; i += 2)
            for (int j = 0; j < m; j++) if (B[i][j] == '.') {
                if (i > 0 && B[i - 1][j] == 'd' + pnt) pnt = (pnt + 1) % 3;
                B[i][j] = B[i + 1][j] = 'd' + pnt;
                pnt = (pnt + 1) % 3;
            }
        for (int i = 0; i < n; i++) {
            B[i][m] = '\0';
            printf("%s\n", B[i]);
        }
    }
    return 0;
}