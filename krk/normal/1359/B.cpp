#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, m, x, y;
char B[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &x, &y);
        y = min(y, 2 * x);
        int res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            for (int a = 0; a < m; )
                if (B[i][a] == '*') a++;
                else {
                    int old = a;
                    while (a < m && B[i][a] != '*') a++;
                    res += (a - old) / 2 * y + (a - old) % 2 * x;
                }
        }
        printf("%d\n", res);
    }
    return 0;
}