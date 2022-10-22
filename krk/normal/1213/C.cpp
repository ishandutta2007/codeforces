#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n, m;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d %I64d", &n, &m);
        ll res = 0;
        for (int i = 0; i < 10; i++) {
            ll st = i * m;
            int dig = st % 10;
            if (st <= n) {
                ll tims = (n - st) / (10ll * m) + 1;
                res += tims * ll(dig);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}