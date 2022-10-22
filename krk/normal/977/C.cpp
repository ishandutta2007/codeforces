#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    if (k == n) printf("%d\n", a[n - 1]);
    else if (k == 0)
            if (a[0] == 1) printf("-1\n");
            else printf("1\n");
    else if (a[k - 1] != a[k]) printf("%d\n", a[k - 1]);
         else printf("-1\n");
    return 0;
}