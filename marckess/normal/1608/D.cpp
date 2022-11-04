// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 200005, mod = 998244353;
ll fac[MX], inv[MX];

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

string s[MX];
int a, b, c, d, e;

void main_() {
	int n;
	
	cin >> n;
	forn (i, n) {
		cin >> s[i];
		
		if (s[i] == "??") a++;
		if (s[i] == "WW") d++;
		if (s[i] == "BB") e++;
		
		b += s[i][0] == 'B';
		b += s[i][1] == 'B';
		
		c += s[i][0] == 'W';
		c += s[i][1] == 'W';
	}
	
	ll res = 0;
	if (!d && !e) {
		res = -pot(2, a);
		
		ll p = 1;
		forn (i, n)
			if (s[i][0] == 'W' || s[i][1] == 'B')
				p = 0;
		res += p;
		
		p = 1;
		forn (i, n)
			if (s[i][0] == 'B' || s[i][1] == 'W')
				p = 0;
		res += p;
	}
	res %= mod;
	
	(res += comb(2 * n - b - c, n - c)) %= mod;
	
	
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		assert(fac[i] * inv[i] % mod == 1);
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}