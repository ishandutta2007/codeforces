#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &n);
        int res = 0;
        while (a <= n && b <= n) {
            res++;
            if (a > b) b += a;
            else a += b;
        }
        printf("%d\n", res);
    }
    return 0;
}