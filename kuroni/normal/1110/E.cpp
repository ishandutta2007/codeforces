#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a[N], b[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for (int i = n; i > 1; i--)
    {
        a[i] -= a[i - 1];
        b[i] -= b[i - 1];
    }
    sort(a + 2, a + n + 1);
    sort(b + 2, b + n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return printf("No"), 0;
    printf("Yes");
}