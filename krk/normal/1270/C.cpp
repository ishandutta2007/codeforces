#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n, a;
ll sum, xr;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        sum = xr = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            sum += a;
            xr ^= a;
        }
        printf("2\n");
        printf("%I64d ", xr);
        sum += xr;
        printf("%I64d\n", sum);
    }
    return 0;
}