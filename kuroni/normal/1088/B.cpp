#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, k, a[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i] > a[i - 1])
        {
            printf("%d\n", a[i] - a[i - 1]);
            if (--k == 0)
                break;
        }
    while (k--)
        printf("0\n");
}