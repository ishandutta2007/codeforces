#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            res += (a[i] - 1) / (2 * a[0] - 1);
        }
        printf("%d\n", res);
    }
    return 0;
}