#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int ans = -1;
        for (int i = 3; i <= 360; i++)
            if (n * i % 180 == 0 && n * i / 180 < i - 1)
            {
                ans = i;
                break;
            }
        printf("%d\n", ans);
    }
}