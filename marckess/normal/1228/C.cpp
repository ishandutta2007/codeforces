#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int mod = 1000000007;
ll n, x;
vl p;

ll pot (ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> n;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			p.pb(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x > 1)
		p.pb(x);

	ll res = 1;
	for (ll a : p) {
		ll y = a;
		while (y <= n) {
			(res *= pot(a, n / y)) %= mod;
			if (n / y >= a) {
				y *= a;
			} else {
				y = n + 1;
			}
		}
	}
	cout << res << endl;

	return 0;
}