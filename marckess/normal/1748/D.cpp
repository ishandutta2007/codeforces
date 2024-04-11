#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

tuple<ll, ll, ll> extendedGcd (ll a, ll b) {
	if(b == 0){
		if(a > 0) return {a, 1, 0};
		else return {-a, -1, 0};
	}else{
		auto[d, x, y] = extendedGcd(b, a%b);
		return {d, y, x - y*(a/b)};
	}
}

ll ceil (ll a, ll b) {
	if (a < 0 != b < 0) return a / b;
	return (abs(a) + abs(b) - 1) / abs(b);
}

ll floor (ll a, ll b) {
	if (a < 0 != b < 0) return -(abs(a) + abs(b) - 1) / abs(b);
	return abs(a) / abs(b);
}

ll a, b, d;

void main_() {
	cin >> a >> b >> d;
	
	ll r = a | b;
	ll x, y, z, g;
	
	z = 1;
	while (z <= r)
		z *= 2;
	
	tie(g, x, y) = extendedGcd(z, -d);
		
	if (r % g) {
		cout << -1 << endl;
	} else {
		ll x0 = (-r / g) * x;
		ll k1 = ceil(-x0 * g, -d);
		ll k2 = floor(-x0 * g, -d);
		
		if (x0 + (-d) * k1 / g >= 0)
			x = x0 + (-d) * k1 / g;
		else
			x = x0 + (-d) * k2 / g;
		assert(x >= 0);
		
		cout << z * x + r << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}