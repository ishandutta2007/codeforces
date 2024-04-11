#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, d;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i > 1) {
                int tk = min(a[i], d / (i - 1));
                a[1] += tk; d -= (i - 1) * tk;
            }
        }
        printf("%d\n", a[1]);
    }
    return 0;
}