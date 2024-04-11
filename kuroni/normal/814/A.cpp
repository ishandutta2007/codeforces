#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, a[205];
    scanf("%d%d", &n, &m);
    if (m > 1)
    {
        printf("Yes");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (a[i] == 0)
            m = i;
    }
    scanf("%d", a + m);
    for (int i = 1; i < n; i++)
        if (a[i + 1] <= a[i])
    {
        printf("Yes");
        return 0;
    }
    printf("No");
    return 0;
}