#include <iostream>
#include <cstdio>
using namespace std;

int n, a[1005], mini = 1e9;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        mini = min(mini, a[i]);
    }
    for (int i = 0; i < n; i++)
        if (a[i] % mini != 0)
        {
            printf("-1");
            return 0;
        }
    printf("%d\n", 2 * n);
    for (int i = 0; i < n; i++)
        printf("%d %d ", a[i], mini);
}