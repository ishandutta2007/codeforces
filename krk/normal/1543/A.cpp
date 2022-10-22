#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &a, &b);
        ll dif = abs(a - b);
        if (dif == 0) printf("0 0\n");
        else {
            ll mn = min(a % dif, dif - a % dif);
            printf("%I64d %I64d\n", dif, mn);
        }
    }
    return 0;
}