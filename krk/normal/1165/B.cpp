#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int nd = 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= nd) { res++; nd++; }
    printf("%d\n", res);
    return 0;
}