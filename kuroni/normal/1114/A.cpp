#include <iostream>
#include <cstdio>
using namespace std;

int x, y, z, a, b, c;

int main()
{
    scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
    if (a < x)
        return printf("NO"), 0;
    a -= x;
    if (a + b < y)
        return printf("NO"), 0;
    a -= y;
    if (a + b + c < z)
        return printf("NO"), 0;
    printf("YES");
}