#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res; scanf("%d", &res);
        for (int i = 1; i < n; i++) {
            scanf("%d", &a);
            res &= a;
        }
        printf("%d\n", res);
    }
    return 0;
}