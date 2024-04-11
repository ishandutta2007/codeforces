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

const int MX = 20000005, mod = 998244353;
int n, a, x, y, k, m;
ll cn[MX], acu[MX];

void main_() {
	cin >> n >> a >> x >> y >> k >> m;
	
	int lim = 1;
	for (int i = 1; i <= 16; i++)
		lim = i * lim / __gcd(i, lim);
	
	forn (i, n) {
		cn[a % lim]++;
		(acu[a % lim] += a) %= mod;
		
		a = (1ll * a * x + y) % m;
	}
	
	ll res = 0;
	for (int i = 1; i <= k; i++) {
		ll p = 0;
		
		forn (j, lim) {
			ll x = cn[j];
			ll y = acu[j];
			
			(p += y) %= mod;
			
			cn[j] = acu[j] = 0;
			
			cn[j] = (n - 1) * x % mod;
			acu[j] = (n - 1) * y % mod;
			
			(cn[j - j % i] += x) %= mod;
			(acu[j - j % i] += y - x * (j % i)) %= mod;
		}
		
		for (int j = i; j < k; j++)
			(p *= n) %= mod;
		
		(res += p) %= mod;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}