#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll n, k, mod = 1e6+3;

ll mul (ll a, ll b, ll m) {
	ll res = 0;
	b %= m;

	while (a) {
		if (a & 1) {
			res += b;
			res %= m;
		}

		b += b;
		b %= m;
		a /= 2;
	}

	return res;
}

ll pot (ll b, ll p, ll m) {
	ll res = 1;
	b %= m;

	while (p) {
		if (p & 1) 
			res = (res * b) % m;
		b = (b * b) % m;
		p /= 2;
	}

	return res;
}

ll vezRep (ll x) {
	ll res = 0;
	for (ll i = 2; i <= x; i *= 2)
		res += x / i;

	if (res && res / n > k - 1)
		return n * (k - 1);

	return res;
}

ll num () {
	if (k >= mod)
		return 0;

	ll res = 1;
	for (int i = 1; i <= k-1; i++) {
		res *= MOD(pot(2, n, mod) - i, mod);
		res %= mod;
	}

	return (res * pot(pot(2, vezRep(k-1), mod), mod-2, mod)) % mod;
}

ll den () {
	return pot(2, MOD(mul(n, k-1, mod-1) - vezRep(k-1), mod-1), mod);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;

    if (n < 60 && pot(2, n, (1LL << 62)) < k) {
    	cout << "1 1" << endl;
    	return 0;
    }

    cout << MOD(den() - num(), mod) << " " << den() << endl;

    return 0;
}