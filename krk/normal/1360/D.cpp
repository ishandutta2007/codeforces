#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        int res = n;
        for (int i = 1; i * i <= n; i++) if (n % i == 0) {
            if (i <= k) res = min(res, n / i);
            if (n / i <= k) res = min(res, i);
        }
        printf("%d\n", res);
    }
    return 0;
}