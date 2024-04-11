#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int zers = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            zers += a[i] == 0;
        }
        int res = zers;
        int ones = 0;
        for (int i = 0; i < n; i++) {
            zers -= a[i] == 0;
            ones += a[i] == 1;
            res = min(res, max(zers, ones));
        }
        printf("%d\n", res);
    }
    return 0;
}