#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int r = n - 1;
    int l = (n - 1) / 2 - 1;
    for (int i = 0; i + 1 < n; i++)
        if (i % 2 == 0) res[i] = a[r--];
        else res[i] = a[l--];
    res[n - 1] = a[r--];
    int ans = 0;
    for (int i = 1; i + 1 < n; i++)
        if (res[i - 1] > res[i] && res[i] < res[i + 1]) ans++;
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}