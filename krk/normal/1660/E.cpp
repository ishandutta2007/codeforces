#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int T;
int n;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ones = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            for (int j = 0; j < n; j++)
                if (B[i][j] == '1') ones++;
        }
        int res = Maxn * Maxn;
        for (int j = 0; j < n; j++) {
            int gotones = 0;
            for (int i = 0; i < n; i++) {
                int my = (i + j) % n;
                if (B[i][my] == '1') gotones++;
            }
            res = min(res, ones - gotones + (n - gotones));
        }
        printf("%d\n", res);
    }
    return 0;
}