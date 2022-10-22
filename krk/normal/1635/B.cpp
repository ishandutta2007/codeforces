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
        int res = 0;
        for (int i = 2; i < n; i++) if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            int mx = a[i];
            if (i + 2 <= n) mx = max(mx, a[i + 2]);
            a[i + 1] = mx; res++;
        }
        printf("%d\n", res);
        for (int i = 1; i <= n; i++)
            printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}