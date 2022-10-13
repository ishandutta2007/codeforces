#include <iostream>
#include <cstdio>
using namespace std;

int k;

int main()
{
    scanf("%d", &k);
    if (k > 36)
        printf("-1");
    else
    {
        if (k & 1)
        {
            printf("4");
            k--;
        }
        while (k != 0)
        {
            printf("8");
            k -= 2;
        }
    }
}