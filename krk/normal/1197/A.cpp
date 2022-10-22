#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int t;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int res = min(n - 2, a[n - 2] - 1);
        printf("%d\n", res);
    }
    return 0;
}