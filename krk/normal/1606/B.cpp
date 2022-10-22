#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &n, &k);
        n--;
        ll cur = 1;
        ll res = 0;
        while (n > 0 && cur <= k) {
            res++;
            n -= cur;
            cur *= 2;
        }
        if (n > 0) res += (n - 1) / k + 1;
        printf("%I64d\n", res);
    }
    return 0;
}