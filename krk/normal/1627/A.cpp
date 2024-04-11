#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, m, r, c;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &r, &c);
        bool was = false, was2 = false;
        for (int i = 1; i <= n; i++) {
            scanf("%s", B[i] + 1);
            for (int j = 1; j <= m; j++) 
                if (B[i][j] == 'B') {
                    was = true;
                    if (i == r || j == c) was2 = true;
                }
        }
        if (B[r][c] == 'B') printf("0\n");
        else if (!was) printf("-1\n");
        else if (was2) printf("1\n");
        else printf("2\n");
    }
    return 0;
}