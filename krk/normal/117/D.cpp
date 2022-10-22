#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
int m, mod;
ll l, r, u, v;

int getRes(ll delta, ll l, ll r, ll a, ll b, ll u, ll v)
{
    if (v < l || r < u) return 0;
    if (a == 1LL && r <= l + (b - 1LL) * delta) {
        if (u < l) u = l;
        else {
            ll nu = l + (u - l) / delta * delta;
            u = nu < u? nu + delta: u;
        }
        if (r < v) v = r;
        else v = l + (v - l) / delta * delta;
        ll part1 = (u + v);
        ll part2 = (v - u) / delta + 1LL;
        if ((u + v) % 2LL) part2 /= 2LL;
        else part1 /= 2LL;
        part1 %= ll(mod); part2 %= ll(mod);
        return part1 * part2 % ll(mod);
    }
    ll mid = ((r - l) / delta + 2LL) / 2LL;
    bool odd = ((r - l) / delta + 1LL) % 2LL;
    int res = 0;
    if (a <= mid)
        res = (res + getRes(2LL * delta, l, odd? r: r - delta, a, min(mid, b), u, v)) % ll(mod);
    if (mid < b)
        res = (res + getRes(2LL * delta, l + delta, odd? r - delta: r, max(a - mid, 1LL), b - mid, u, v)) % ll(mod);
    return res;
}

int main()
{
    scanf("%I64d %d %d", &n, &m, &mod);
    while (m--) {
        scanf("%I64d %I64d %I64d %I64d", &l, &r, &u, &v);
        printf("%d\n", getRes(1LL, 1LL, n, l, r, u, v));
    }
    return 0;
}