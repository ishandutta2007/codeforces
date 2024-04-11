#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[3];

int main()
{
    scanf("%d%d%d", a, a + 1, a + 2);
    sort(a, a + 3);
    if (a[0] == 1)
    {
        printf("YES");
        return 0;
    }
    else if (a[0] == 2)
    {
        if (a[1] == 2)
        {
            printf("YES");
            return 0;
        }
        else if (a[1] == 4 && a[2] == 4)
        {
            printf("YES");
            return 0;
        }
    }
    else if (a[0] == 3)
    {
        if (a[1] == 3 && a[2] == 3)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}