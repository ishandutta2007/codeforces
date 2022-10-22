#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int lst = 0;
    for (int i = 0; i < n; i++)
        if (lst < a[i])
            if (lst < a[i] - 1) { res++; lst = a[i] - 1; }
            else { res++; lst = a[i]; }
        else if (lst == a[i]) { res++; lst = a[i] + 1; }
    printf("%d\n", res);
    return 0;
}