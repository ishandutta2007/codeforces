#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, d;

int main()
{
    scanf("%d", &n);
    d = sqrt(n - 1) + 1;
    for (int i = 1; i <= (n - 1) / d + 1; i++)
        for (int j = min(n, i * d); j > (i - 1) * d; j--)
            printf("%d ", j);
}