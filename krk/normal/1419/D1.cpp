#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int l = 0, r = n - 1;
    printf("%d\n", (n - 1) / 2);
    for (int i = 0; i < n; i++)
        if (i % 2 == 0) printf("%d%c", a[r--], i + 1 < n? ' ': '\n');
        else printf("%d%c", a[l++], i + 1 < n? ' ': '\n');
    return 0;
}