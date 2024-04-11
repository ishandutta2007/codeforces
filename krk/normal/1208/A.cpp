#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &n);
        n %= 3;
        int res;
        if (n == 0) res = a;
        else if (n == 1) res = b;
        else res = (a ^ b);
        printf("%d\n", res);
    }
    return 0;
}