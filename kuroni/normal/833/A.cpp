#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long x, y, tmp;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%I64d%I64d", &x, &y);
        tmp = round(pow((long double)x * y, 1.0 / 3));
        if (tmp * tmp * tmp == x * y && __gcd(x, y) % tmp == 0)
            printf("Yes\n");
        else printf("No\n");
    }
}