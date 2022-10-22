#include <bits/stdc++.h>
using namespace std;

int q;
int n;
int a;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            res += a;
        }
        res = (res - 1) / n + 1;
        printf("%d\n", res);
    }
    return 0;
}