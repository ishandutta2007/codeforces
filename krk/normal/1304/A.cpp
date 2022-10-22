#include <bits/stdc++.h>
using namespace std;

int T;
int x, y, a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        int s = y - x, v = a + b;
        if (s % v) printf("-1\n");
        else printf("%d\n", s / v);
    }
    return 0;
}