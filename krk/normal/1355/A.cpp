#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll a;
ll k;

int minDig(ll x)
{
    ll res = 10;
    while (x) {
        res = min(res, x % 10);
        x /= 10;
    }
    return res;
}

int maxDig(ll x)
{
    ll res = 0;
    while (x) {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d", &a, &k); k--;
        ll lst = a;
        while (k > 0) {
            a += minDig(a) * maxDig(a);
            k--;
            if (lst == a) break;
            lst = a;
        }
        printf("%I64d\n", a);
    }
    return 0;
}