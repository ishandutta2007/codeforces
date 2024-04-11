#include <bits/stdc++.h>
using namespace std;

const int Inf = 2000000007;

int t;
int n, x, y, d;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &x, &y, &d);
        int res = Inf;
        if (abs(y - x) % d == 0) res = abs(y - x) / d;
        if ((y - 1) % d == 0) res = min(res, (y - 1) / d + (x - 1) / d + bool((x - 1) % d > 0));
        if ((n - y) % d == 0) res = min(res, (n - y) / d + (n - x) / d + bool((n - x) % d > 0));
        printf("%d\n", res >= Inf? -1: res);
    }
    return 0;
}