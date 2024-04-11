#include <iostream>
#include <stdio.h>
using namespace std;

int n, t, i = 1;

int main()
{
    scanf("%d", &t);
    n = t;
    while (n >= 10)
    {
        i *= 10;
        n /= 10;
    }
    printf("%d", (n + 1) * i - t);
}