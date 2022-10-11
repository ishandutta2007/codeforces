#include <iostream>
#include <cstdio>
using namespace std;

int n;
double cur = -1.0, ans = 0.0, p;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf", &p);
        ans += ((cur += 2) *= p);
        cur += p - 1.0;
    }
    printf("%lf", ans);
}