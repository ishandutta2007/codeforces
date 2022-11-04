#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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
int n, q;
string s;
ll fac[MX], inv[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	cin >> n >> q >> s;
	
	int x[2] = {0}, y[2] = {0};
	
	forn (i, n) {
		if (s[i] == 'b') x[i & 1]++;
		if (s[i] == '?') y[i & 1]++;
	}
	
	ll a = 0, b = 0;
	
	for (int i = 0; i <= y[0] + y[1]; i++) {
		int f = x[0] + min(i, y[0]);
		int g = x[1] + min(y[0] + y[1] - i, y[1]);
		
		if ((f + g) & 1) continue;
		
		ll c = comb(y[0] + y[1], i);
		(a += abs(f - g) * c) %= mod;
		(b += c) %= mod;
	}
	
	cout << a * pot(2 * b, mod - 2) % mod << endl;
	
	return 0;
}