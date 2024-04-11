#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int xr[Maxn];
int T;
int a, b;

int main()
{
    for (int i = 1; i < Maxn; i++)
        xr[i] = (i ^ xr[i - 1]);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        int cur = xr[a - 1];
        int res = a;
        if (b != cur)
            if ((b ^ cur) == a) res += 2;
            else res++;
        printf("%d\n", res);
    }
    return 0;
}