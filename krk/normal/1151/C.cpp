#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll l, r;

int F(ll r)
{
    ll odd = 1, ev = 2;
    ll hm = 1;
    bool cur_odd = true;
    int res = 0;
    for (ll was = 0, hm = 1; was < r; hm <<= 1) {
        ll tk = min(hm, r - was);
        if (cur_odd) {
            ll tkmod = tk % mod;
            res = (ll(res) + ll(odd + (tk - 1)) % mod * tkmod % mod) % mod;
            odd += 2 * tk;
        } else {
            ll tkmod = tk % mod;
            res = (ll(res) + ll(ev + (tk - 1)) % mod * tkmod % mod) % mod;
            ev += 2 * tk;
        }
        was += tk;
        cur_odd ^= true;
    }
    return res;
}

int main()
{
    cin >> l >> r;
    int got = (F(r) - F(l - 1) + mod) % mod;
    printf("%d\n", got);
    return 0;
}