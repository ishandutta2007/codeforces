#include <bits/stdc++.h>
using namespace std;

const int Maxb = 25;

int T;
int a, b;

int Solve(int a, int b)
{
    if (a == b) return 0;
    int v = Maxb - 1;
    while (v >= 0 && bool(a & 1 << v) <= bool(b & 1 << v)) v--;
    if (v < 0) return 1;
    int res = 1;
    while (v >= 0) {
        if (a & 1 << v) res += 1 << v;
        if (b & 1 << v) res -= 1 << v;
        v--;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        int res = 1000000000;
        for (int i = 0; a + i <= b; i++)
            res = min(res, i + Solve(a + i, b));
        printf("%d\n", res);
    }
    return 0;
}