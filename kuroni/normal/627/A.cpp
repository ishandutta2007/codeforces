#include <iostream>
#include <stdio.h>

using namespace std;

long long a, b, diff, save_b, ans = 1;

int main()
{
    scanf("%lld%lld", &a, &b);
    if (a < b || (a - b) % 2 == 1)
    {
        printf("0");
        return 0;
    }
    diff = (a - b) / 2;
    save_b = b;
    while (diff != 0 || b != 0)
    {
        if (b % 2 == 1)
        {
            if (diff % 2 == 0)
                ans *= 2;
            else
            {
                printf("0");
                return 0;
            }
        }
        diff /= 2;
        b /= 2;
    }
    printf("%lld", ans - 2 * (save_b == a));
}