#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10;

int T;
int n, m;
char B[Maxn][Maxn];
int lef, up;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        lef = Maxn, up = Maxn;
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            for (int j = 0; j < m; j++) if (B[i][j] == 'R') {
                up = min(up, i);
                lef = min(lef, j);
            }
        }
        bool ok = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (B[i][j] == 'R')
                if (i <= up && j <= lef) ok = true;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}