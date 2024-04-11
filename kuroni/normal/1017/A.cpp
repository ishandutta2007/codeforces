#include <iostream>
#include <cstdio>
using namespace std;

int n, s, t, ans = 1;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &t);
        s += t;
    }
    for (int i = 1; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &t);
            tmp += t;
        }
        ans += (tmp > s);
    }
    printf("%d", ans);
}