#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 105;

int n;
long long a[N];

bool cmp(long long a, long long b)
{
    int l = 0, r = 0;
    while (a % 3 == 0)
    {
        ++l;
        a /= 3;
    }
    while (b % 3 == 0)
    {
        ++r;
        b /= 3;
    }
    if (l != r)
        return l > r;
    l = r = 0;
    while (a % 2 == 0)
    {
        ++l;
        a /= 2;
    }
    while (b % 2 == 0)
    {
        ++r;
        b /= 2;
    }
    return l < r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
}