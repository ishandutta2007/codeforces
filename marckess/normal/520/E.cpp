#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll pot (ll b, int p, int M) {
	ll res = 1;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= M;
		}

		b *= b;
		b %= M;
		p /= 2;
	}

	return res;
}

const int M = 1e9+7;
ll fac[200005], ifac[200005];
void precal () {
	fac[0] = ifac[0] = 1;

	for (ll i = 1; i < 2e5; i++) {
		fac[i] = (fac[i-1] * i) % M;
		ifac[i] = pot(fac[i], M-2, M);
	}
}

ll C (int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;

	ll res = fac[n] * ifac[k];
	res %= M;
	res *= ifac[n-k];
	res %= M;

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	precal();
	
	int n, k, a[100005];
	string s;

	cin >> n >> k >> s;
	for (int i = 0; i < n; i++)
		a[i] = s[i] - '0';

	ll res = 0, acu = 0;
	for (ll i = n-1, pw = 1; i >= 0; i--, pw *= 10, pw %= M) {
		res += a[i] * ((pw * C(i, k)) % M);
		res %= M;

		res += a[i] * acu;
		res %= M;

		acu += pw * C(i-1, k-1);
		acu %= M;
	}

	cout << res << endl;

	return 0;
}