#include <bits/stdc++.h>
using namespace std;

int n;
int ax, ay;
int bx, by;
int cx, cy;

int main()
{
    scanf("%d\n", &n);
    scanf("%d %d", &ax, &ay);
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &cx, &cy);
    if ((bx > ax) == (cx > ax) &&
        (by > ay) == (cy > ay))
        printf("YES\n");
    else printf("NO\n");
    return 0;
}