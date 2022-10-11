#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int q;
long long n;

long long f(long long n)
{
    return n + (long long)(sqrt(n * 8 + 1) - 1) / 2 * 2;
}

long long solve(long long n)
{
    long long l = 0, r = n, mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid) <= n)
            l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%I64d", &n);
        if (n <= 5)
            printf("%I64d\n", n - 1);
        else printf("%I64d\n", n + solve(n - 6));
    }
    return 0;
}