#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int pnt = 3;
        while (pnt + pnt - 1 + pnt - 2 < n) pnt++;
        int res1 = pnt; n -= pnt;
        pnt = 2;
        while (pnt + pnt - 1 < n) pnt++;
        int res2 = pnt; n -= pnt;
        int res3 = n;
        printf("%d %d %d\n", res2, res1, res3);
    }
    return 0;
}