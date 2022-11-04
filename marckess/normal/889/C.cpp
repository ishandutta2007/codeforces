#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
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

const int MX = 1000005, mod = 1000000007;
int n, k;
ll fac[MX], inv[MX], dp[MX];

ll pot (ll b, int p) {
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
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	cin >> n >> k;
	
	for (ll i = n, acu = fac[n - 1]; i >= 1; i--) {
		(acu += fac[i - 1] * dp[i + 1]) %= mod;
		dp[i] = acu * inv[i - 1] % mod;
		if (i + k <= n)
			(acu -= fac[i + k - 2] * dp[i + k]) %= mod;
	}
	
	cout << MOD(fac[n] - dp[1], mod) << endl;
	
	return 0;
}