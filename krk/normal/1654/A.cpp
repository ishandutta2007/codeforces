#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

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
        printf("%d\n", a[n - 2] + a[n - 1]);
    }
    return 0;
}