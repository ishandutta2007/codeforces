#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 998244353;
ll n, cn[MX], mu[MX], bs[MX];

ll pot (ll b, ll p) {
	ll res = 1;
	b %= mod;
	
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	
	return res;
}

ll f (ll n) {
	if (n < 1) return 0;
	return n % mod * pot(2, n - 1) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, MX) mu[i] = 1;
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			for (ll j = i; j < MX; j += i) {
				bs[j] = 1;
				mu[j] *= -1;
			}
			
			for (ll j = i * i; j < MX; j += i * i)
				mu[j] = 0;
		}
	
	cin >> n;
	
	while (n--) {
		ll a, f;
		cin >> a >> f;
		cn[a] = f;
	}
	
	ll res = 0;
	for (ll i = 1; i < MX; i++)
		if (mu[i]) {
			ll s = 0, acu = 0, dot = 0;
			
			for (ll j = i; j < MX; j += i) {
				(s += j * cn[j]) %= mod;
				(dot += j * j % mod * cn[j]) %= mod;
				acu += cn[j];
			}
			
			(s *= s) %= mod;
			(s -= dot) %= mod;
			
			ll p = s * (f(acu - 2) + pot(2, acu - 2)) % mod;
			(p += dot * f(acu - 1)) %= mod;
			
			(res += mu[i] * p) %= mod;
		}
	
	cout << MOD(res, mod) << endl;
	
	return 0;
}