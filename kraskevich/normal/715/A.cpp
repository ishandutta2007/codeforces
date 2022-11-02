#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = (ll)2e18;

ll mul(ll a, ll b) {
    if (a == 0 || b == 0)
        return 0;
    if (a > INF / b)
        return INF;
    return min(a * b, INF);
}

ll add(ll a, ll b) {
    return min(INF, a + b);
}

ll calc(ll k, ll t, ll cur) {
    ll res = -cur;
    res = add(res, mul(mul(k * k * k, t), t));
    res = add(res, mul(mul(2 * k * k, t), t));
    res = add(res, mul(mul(k, t), t));
    return res;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll cur = 2;
    for (ll k = 1; k <= n; k++) {
       ll lo = -1;
       ll hi = (ll) 1e18;
       while (hi - lo > 1) {
           ll mid = (lo + hi) / 2;
           if (calc(k, mid, cur) >= 0)
               hi = mid;
           else
               lo = mid;
       }
       cout << calc(k, hi, cur) << "\n";
       assert (mul(hi, k) == hi * k);
       cur = hi * k;
    }
}