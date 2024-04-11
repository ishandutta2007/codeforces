#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int lef = 0, rig = n - 1;
        while (a[lef] != 1) lef++;
        while (a[rig] != 1) rig--;
        int res = 0;
        for (int i = lef; i <= rig; i++)
            res += a[i] == 0;
        printf("%d\n", res);
    }
    return 0;
}