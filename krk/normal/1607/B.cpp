#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x0, n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &x0, &n);
        ll delt = 0;
        if (n % 4 == 0) delt = 0;
        else if (n % 4 == 1) delt = -n;
        else if (n % 4 == 2) delt = 1;
        else delt = n + 1;
        if (x0 % 2 != 0) delt = -delt;
        x0 += delt;
        printf("%I64d\n", x0);
    }
    return 0;
}