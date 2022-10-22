#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n + 1);
    for (int i = 0; i < n; i++)
        if (a[i] != a[i + 1] && k > 0) {
            printf("%d\n", a[i + 1] - a[i]);
            k--;
        }
    while (k--)
        printf("0\n");
    return 0;
}