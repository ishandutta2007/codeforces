#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int lef = i > 0? a[i - 1]: 0;
            int rig = j + 1 < n? a[j + 1]: 1001;
            if (rig - lef - 1 == j - i + 1)
                res = max(res, j - i + 1);
        }
    printf("%d\n", res);
    return 0;
}