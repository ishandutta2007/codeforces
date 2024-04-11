#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lll;
using namespace std;
const ll P1 = 8192, P2 = 1220703125, P3 = 48828125, P4 = 1e13;
const ll C1 = 12288, C2 = 4882812500, C3 = C2 / 25;
vector<ll> na, nb;
void calc1(ll x) {
	if(x == 0) na.eb(0);
	if(x == 1) na.eb(1);
	ll a = 0, b = 1;
	for(ll i = 2; i < C1; i++) {
		a = (a + b) % P1;
		swap(a, b);
		if(b == x) {
            na.eb(i);
        }
	}
    return;
}
void calc2(ll x) {
	if(x == 0) nb.eb(0);
	if(x == 1) nb.eb(1);
	ll a = 0, b = 1;
	for(ll i = 2; i < C3; i++) {
		a = (a + b) % P3;
		swap(a, b);
		if(b == x) {
            nb.eb(i);
        }
	}
}
void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if(!b) {
		d = a, x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, d, y, x);
	y -= a / b * x;
	return;
}
pair<lll, lll> fib(ll n) {
    if(n == 0) return {0, 1};
    if(n % 2) {
        pair<lll, lll> f = fib(n - 1);
        f.x = (f.x + f.y) % P4;
        swap(f.x, f.y);
        return f;
    }
    pair<lll, lll> f = fib(n / 2);
    return {f.x * (f.y * 2 - f.x + P4) % P4, (f.x * f.x + f.y * f.y) % P4};
}
ll calc(ll a1, ll a2, ll n) {
	ll d, x, y;
	exgcd(C1, C2, d, x, y);
    if((a1 - a2) % d) return 1e18;
	ll c = a1 - a2;
	x = ((x % C2) + C2) % C2;
	c /= d;
	c = (c % C2 + C2) % C2;
	x = __int128(x) * c % C2;
    ll LCM = C1 * C2 / 4;
	ll ans = (a1 - x * C1 % LCM + LCM) % LCM;
    // cout << ans <<" " << ll(fib(ans).x) << endl;
    if(fib(ans).x == n) return ans;
    return 1e18;
}
int main() {
	ll n;
	cin >> n;
	calc1(n % P1), calc2(n % P3);
    vector<ll> nc;
    for(ll x : nb) {
        for(int j = 0; j < 25; j++) {
            nc.eb(j * C3 + x);
        }
    }
    nb = nc;
    ll ans = 1e18;
    for(ll p : na) for(ll q : nb) ans = min(ans, calc(p, q, n));
    if(ans >= 1e18) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}