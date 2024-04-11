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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll a, b, c, d;

vi fac (ll n) {
	vi res;
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0) {
			res.pb(i);
			res.pb(n / i);
		}
	return res;
}

ll find (ll x, ll c) {
	return x * (c / x);
}

void main_() {
	cin >> a >> b >> c >> d;
	
	vi fa = fac(a);
	vi fb = fac(b);
	
	for (ll xa : fa)
	for (ll xb : fb) {
		ll nx = xa * xb;
		ll ny = a * b / nx;
		
		ll x = find(nx, c);
		ll y = find(ny, d);
		
		if (a < x)
		if (b < y) {
			cout << x << " " << y << endl;
			return;
		}
	}
	
	cout << -1 << " " << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}