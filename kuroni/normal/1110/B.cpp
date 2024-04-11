#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, k, a[N];

int main()
{
    scanf("%d%d%d", &n, &k, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        a[i - 1] = a[i] - a[i - 1];
    }
    sort(a + 1, a + n);
    int ans = k;
    for (int i = 1; i <= n - k; i++)
        ans += a[i];
    printf("%d", ans);
}