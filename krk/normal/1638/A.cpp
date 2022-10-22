#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
int n;
int p[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        int pnt = 0;
        while (pnt < n && p[pnt] == pnt + 1) pnt++;
        if (pnt < n) {
            int nd = pnt + 1;
            int pnt2 = pnt;
            while (p[pnt2] != nd) pnt2++;
            reverse(p + pnt, p + pnt2 + 1);
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", p[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}