#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Maxd = 2;

int T;
int n, m;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int sum = 0, mn = 4;
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            for (int j = 0; j < m; j++)
                sum += B[i][j] - '0';
        }
        for (int i = 0; i + 2 <= n; i++)
            for (int j = 0; j + 2 <= m; j++) {
                int cur = 0;
                for (int i2 = 0; i2 < 2; i2++)
                    for (int j2 = 0; j2 < 2; j2++)
                        cur += B[i + i2][j + j2] - '0';
                if (cur > 1) cur--;
                if (cur > 0) mn = min(mn, cur);
            }
        if (sum == 0) printf("0\n");
        else printf("%d\n", 1 + sum - mn);
    }
    return 0;
}