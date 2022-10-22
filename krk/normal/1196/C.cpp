#include <bits/stdc++.h>
using namespace std;

const int lim = 100000;
const int Maxn = 100005;

int q;

int main()
{
    scanf("%d", &q);
    while (q--) {
        int X1 = -lim, X2 = lim;
        int Y1 = -lim, Y2 = lim;
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x, y, a, b, c, d; scanf("%d %d %d %d %d %d", &x, &y, &a, &b, &c, &d);
            if (a == 0) X1 = max(X1, x);
            if (b == 0) Y2 = min(Y2, y);
            if (c == 0) X2 = min(X2, x);
            if (d == 0) Y1 = max(Y1, y);
        }
        if (X1 <= X2 && Y1 <= Y2)
            printf("1 %d %d\n", X1, Y1);
        else printf("0\n");
    }
    return 0;
}