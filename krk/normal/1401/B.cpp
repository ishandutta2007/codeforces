#include <bits/stdc++.h>
using namespace std;

int T;
int x1, y1, z1;
int x2, y2, z2;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &x1, &y1, &z1);
        scanf("%d %d %d", &x2, &y2, &z2);
        int tk = min(z1, y2);
        int res = 2 * tk; z1 -= tk; y2 -= tk;
        tk = min(y1, x2 + y2); y1 -= tk;
        res -= 2 * y1;
        printf("%d\n", res);
    }
    return 0;
}