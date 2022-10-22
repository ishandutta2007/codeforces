#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

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
        sort(a, a + n);
        int res = 2000000007;
        for (int i = 0; i + 2 < n; i++)
            res = min(res, a[i + 2] - a[i]);
        printf("%d\n", res);
    }
    return 0;
}