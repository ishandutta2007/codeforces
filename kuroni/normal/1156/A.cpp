#include <iostream>
#include <cstdio>
using namespace std;

const int N = 105;

int n, cnt = 0, a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (i > 1)
        {
            if (a[i] == 1 || a[i - 1] == 1)
            {
                cnt += max(a[i], a[i - 1]) + 1;
                if (a[i] == 2 && a[i - 1] == 1 && a[i - 2] == 3)
                    cnt--;
            }
            else
            {
                printf("Infinite");
                return 0;
            }
        }
    }
    printf("Finite\n%d\n", cnt);
}