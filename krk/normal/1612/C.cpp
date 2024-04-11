#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int k;
ll x;

ll Sum(ll a, ll b)
{
    if (a > b) swap(a, b);
    return ll(a + b) * (b - a + 1) / 2;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d", &k, &x);
        ll l = 1, r = 2 * k - 2;
        while (l <= r) {
            ll mid = l + r >> 1ll;
            ll got = 0;
            if (mid <= k) got = Sum(1, mid);
            else got = Sum(1, k) + Sum(k - 1, k - (mid - k));
            if (got >= x) r = mid - 1ll;
            else l = mid + 1ll;
        }
        printf("%I64d\n", l);
    }
    return 0;
}