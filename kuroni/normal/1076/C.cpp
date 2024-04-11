#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int delta = n * n - 4 * n;
        if (delta < 0)
            printf("N\n");
        else
            printf("Y %.16f %.16f\n", (n + sqrt(delta)) / 2, (n - sqrt(delta)) / 2);
    }
}