#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    for (int a = 1; a <= x; a++)
        for (int b = 1; b <= x; b++)
            if (a % b == 0 && a * b > x && a < b * x)
            {
                printf("%d %d\n", a, b);
                return 0;
            }
    printf("-1");
}