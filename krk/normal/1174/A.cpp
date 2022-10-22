#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum -= a[i];
    for (int i = n; i < 2 * n; i++)
        sum += a[i];
    if (sum != 0)
        for (int i = 0; i < 2 * n; i++)
            printf("%d%c", a[i], i + 1 < 2 * n? ' ': '\n');
    else printf("-1\n");
    return 0;
}