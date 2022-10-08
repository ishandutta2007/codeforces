
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// compute gcd. How many times do we have to decrease until another divisor of a appears?
// b - k * g = 0 (mod d)
// b = k * g (mod d)
// where d is a divisor of a

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

ll a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    vector<ll> div;
    for(ll i = 1; i * i <= a; i++) {
        if(a % i == 0) {
            div.push_back(i);
            if(i * i != a) {
                div.push_back(a / i);
            }
        }
    }
    ll ans = 0;
    while(b != 0) {
        ll g = gcd(a, b);
        ll k = b / g;
        for(ll d : div) {
            if(d > b || b % d == 0) continue;
            ll gg = gcd(g, d);
            ll dd = d / gg;
            ll bb = (b / gg) % dd;
            k = min(k, (((modinverse(g / gg, dd) * bb) % dd) + dd) % dd);
        }
        ans += k;
        b -= k * g;
    }
    cout << ans << '\n';
}