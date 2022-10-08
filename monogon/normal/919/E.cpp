
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// b != 0, so solution only exists when n invertible
// a^n == b * n^-1
// (a^-1)^n == b^-1 * n
// if we know (n mod p) and (n mod (p-1)), use CRT to find n mod p(p - 1), check if <= x
// all b * n^-1 values will be distinct, so we don't get quadratic behavior
// meet in the middle + CRT for O(p log p) time

const int P = 1e6 + 5;
ll a, b, p, x;
int arr[P];

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
ll euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while(b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}
ll modinverse(ll a, ll m) {
    ll x, y;
    ll g = euclid(a, m, x, y);
    return g > 1 ? -1 : mod(x, m);
}
pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll s, t;
    ll g = euclid(m1, m2, s, t);
    if(r1 % g != r2 % g) return {0, -1};
    ll M = m1 / g * m2;
    return {mod(mod(s * r2, M) * (m1 / g) + mod(t * r1, M) * (m2 / g), M), M};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> p >> x;
    a = modinverse(a, p);
    b = modinverse(b, p);
    ll cnt = 0, powa = 1;
    rep(n, 1, p) {
        powa = mod(powa * a, p);
        cnt++;
        if(powa == 1) break;
    }
    rep(n, 1, p) {
        arr[mod(b * n, p)] = n;
    }
    ll ans = 0;
    rep(n, 0, cnt) {
        if(arr[powa] > 0) {
            ll y = crt(n, cnt, arr[powa], p).fi;
            if(y <= x) {
                ll k = (x - y) / (cnt * p);
                ans += k + 1;
                // cout << y << ' ' << " mod " << (cnt * p) << endl;
            }
        }
        powa = mod(powa * a, p);
    }
    cout << ans << '\n';
}