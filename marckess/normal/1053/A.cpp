#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll n, m, k, x = 1, y = 1;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	if (2 * n * m % k) {
		cout << "NO" << endl;
		return 0;
	}

	ll c = 2 * n * m / k;
	ll a = n, b = m;

	while (gcd(c, a) > 1) {
		ll d = gcd(c, a);
		if (x * d > n) break;

		a /= d;
		c /= d;
		x *= d; 
	}

	while (gcd(c, b) > 1) {
		ll d = gcd(c, b);
		if (y * d > m) return -1;

		b /= d;
		c /= d;
		y *= d;
	}

	if (c > 1) {
		if (x * c <= n) x *= c;
		else if (y * c <= m) y *= c;
		else return -1;
	} 

	cout << "YES" << endl;
	cout << 0 << " " << 0 << endl;
	cout << x << " " << 0 << endl;
	cout << 0 << " " << y << endl;

	return 0;
}