#include <bits/stdc++.h>
using namespace std;

int T;
int x1, p1;
int x2, p2;

int Digs(int x)
{
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x1, &p1);
        scanf("%d %d", &x2, &p2);
        int d1 = Digs(x1) + p1;
        int d2 = Digs(x2) + p2;
        if (d1 != d2) printf("%c\n", d1 < d2? '<': '>');
        else {
            int tk = min(p1, p2);
            p1 -= tk; p2 -= tk;
            while (p1--) x1 *= 10;
            while (p2--) x2 *= 10;
            if (x1 != x2) printf("%c\n", x1 < x2? '<': '>');
            else printf("=\n");
        }
    }
    return 0;
}