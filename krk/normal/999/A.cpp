#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int lef = 0;
    while (lef < n && a[lef] <= k) lef++;
    if (lef >= n) { printf("%d\n", n); return 0; }
    int rig = n - 1;
    while (rig >= 0 && a[rig] <= k) rig--;
    printf("%d\n", lef + n - 1 - rig);
    return 0;
}