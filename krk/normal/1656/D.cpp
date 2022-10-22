#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

bool Check(ll val, ll mem)
{
    return val > 1 && val <= 2000000000 && val * (val + 1) / 2 <= mem && (mem - val * (val + 1) / 2) % val == 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        ll mem = n;
        int p = 0;
        while (n % 2 == 0) { p++; n /= 2; }
        if (Check(1ll << ll(p) + 1ll, mem)) printf("%I64d\n", 1ll << ll(p) + 1ll);
        else if (Check(n, mem)) printf("%I64d\n", n);
        else printf("-1\n");
    }
    return 0;
}