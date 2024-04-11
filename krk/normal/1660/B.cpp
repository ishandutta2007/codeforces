#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n + 1);
        printf("%s\n", a[n - 1] + 1 >= a[n]? "YES": "NO");
    }
    return 0;
}