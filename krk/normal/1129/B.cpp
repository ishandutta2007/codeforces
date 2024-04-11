#include <bits/stdc++.h>
using namespace std;

int k;

int main()
{
    scanf("%d", &k);
    for (int b = 2; b <= 2000; b++)
        for (int a = 1; a < b; a++)
            if ((k + b) % (b - a) == 0 && (k + b) / (b - a) <= 1000000) {
                int x = (k + b) / (b - a);
                printf("%d\n", b);
                for (int i = 0; i < b - a - 1; i++)
                    printf("0 ");
                printf("-1 ");
                for (int i = 0; i < a - 1; i++)
                    printf("0 ");
                printf("%d\n", x);
                return 0;
            }
    printf("-1\n");
    return 0;
}