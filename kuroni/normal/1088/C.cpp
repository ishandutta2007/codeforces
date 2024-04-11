#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2005;

int n, a[N];

int main()
{
    scanf("%d", &n);
    printf("%d\n", n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        a[i] += 500000;
    }
    printf("1 %d 500000\n", n);
    for (int i = 1; i <= n; i++)
        printf("2 %d %d\n", i, a[i] - i + 1);
}