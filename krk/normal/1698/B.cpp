#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (k == 1) { printf("%d\n", (n - 1) / 2); continue; }
        int res = 0;
        for (int i = 1; i + 1 < n; i++)
            res += int(a[i] > a[i - 1] + a[i + 1]);
        printf("%d\n", res);
    }
    return 0;
}