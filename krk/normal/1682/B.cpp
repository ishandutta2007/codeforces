#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res = (1 << 18) - 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] != i) res &= a[i];
        }
        printf("%d\n", res);
    }
    return 0;
}