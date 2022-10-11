#include <iostream>
#include <cstdio>
using namespace std;

const int N = 16;

int n, a[N];

int check(int l, int r)
{
    int so = true;
    for (int i = l; i < l + r - 1; i++)
        if (a[i] > a[i + 1])
            so = false;
    return so ? r : max(check(l, r / 2), check(l + r / 2, r / 2));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("%d\n", check(0, n));
}