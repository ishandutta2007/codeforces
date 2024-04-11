#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;

int T;
int n;
int a[Maxn];
int b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        int mn = 0, mx = 1000000005;
        for (int i = 0; i < n; i++)
            if (b[i] > 0) {
                mn = max(mn, a[i] - b[i]);
                mx = min(mx, a[i] - b[i]);
            } else mn = max(mn, a[i] - b[i]);
        printf("%s\n", mn <= mx? "YES": "NO");
    }
    return 0;
}