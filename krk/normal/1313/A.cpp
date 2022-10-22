#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a < b) swap(a, b);
        if (b < c) swap(b, c);
        if (a < b) swap(a, b);
        int res = 0;
        if (a) { a--; res++; }
        if (b) { b--; res++; }
        if (c) { c--; res++; }
        if (a && b) { a--; b--; res++; }
        if (a && c) { a--; c--; res++; }
        if (b && c) { b--; c--; res++; }
        if (a && b && c) res++;
        printf("%d\n", res);
    }
    return 0;
}