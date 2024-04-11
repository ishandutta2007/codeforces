#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mx = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > a[mx]) mx = i;
        }
        int res = -1;
        for (int i = 1; i <= n; i++) if (a[i] == a[mx])
            if (i - 1 > 0 && a[i - 1] < a[mx] ||
                i + 1 <= n && a[i + 1] < a[mx]) {
                    res = i; break;
                }
        printf("%d\n", res);
    }
    return 0;
}