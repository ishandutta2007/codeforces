#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll l, r;
ll res;

ll refl(ll d, ll x)
{
    ll res = 0;
    while (d) {
          res += d * (9LL - x / d % 10LL);
          d /= 10LL;
    }
    return res;
}

ll getBest(ll d, ll l, ll r)
{
    if (l > r) return res;
    if (l <= 5LL * d && 5LL * d <= r) return (5LL * d) * (5LL * d - 1LL);
    return max(l * refl(d, l), r * refl(d, r));
}

int main()
{
    cin >> l >> r;
    for (ll d = 1LL; d <= r; d *= 10LL)
       res = max(res, getBest(d, max(d, l), min(10LL * d - 1LL, r)));
    cout << res << endl;
    return 0;
}