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

const int MX = 400005, mod = 998244353;
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

int n, k, a[MX], pos[MX];

void solve () {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	
	pos[n] = -1;
	forn (i, n)
		pos[a[i]] = i;
	
	int dif = 1;
	forn (i, n - 1)
		if (pos[a[i] + 1] > pos[a[i + 1] + 1])
			dif++;
	
	cout << comb(k + n - dif, n) << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
		assert(fac[i] * inv[i] % mod == 1);
	}
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
 
	return 0;
}