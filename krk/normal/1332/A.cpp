#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c, d;
int x, y, X1, Y1, X2, Y2;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%d %d %d %d %d %d", &x, &y, &X1, &Y1, &X2, &Y2);
        bool fall = false;
        int tk = min(a, b); a -= tk; b -= tk;
        if (tk && x == X1 && x == X2) fall = true;
        if (a > 0) x -= a;
        else if (b > 0) x += b;
        tk = min(c, d); c -= tk; d -= tk;
        if (tk && y == Y1 && y == Y2) fall = true;
        if (c > 0) y -= c;
        else if (d > 0) y += d;
        printf("%s\n", X1 <= x && x <= X2 && Y1 <= y && y <= Y2 && !fall? "Yes": "No"); 
    }
    return 0;
}