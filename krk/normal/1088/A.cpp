#include <bits/stdc++.h>
using namespace std;

int x;

int main()
{
    scanf("%d", &x);
    for (int a = 1; a <= x; a++)
        for (int b = 1; b <= x; b++)
            if (a % b == 0 && a * b > x && a < x * b) {
                printf("%d %d\n", a, b);
                return 0;
            }
    printf("-1\n");
    return 0;
}